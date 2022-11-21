#include "Simulation.h"
#include <vector>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions()
{
    for(Agent& agent: mAgents){
        int agentId = agent.getId();
        int partyId = agent.getPartyId();
        Coalition c(agentId, agentId, partyId);
        mCoalitions.push_back(c);        
    }

    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    mGraph.step(*this);
    for(Agent& agent: mAgents)
        agent.step(*this);
    
}

bool Simulation::shouldTerminate() const
{
    if(mGraph.isAllJoined())
        return true;
    else
    {
        for(Coalition c: mCoalitions)
            if(c.getTotalMandates(const_cast<Simulation&>(*this)) >= 61)
                return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> vec;
    for(Coalition c: mCoalitions)
        vec.push_back(c.getParties());
    return vec;
}

int Simulation::getCoalition(int agentId)
{
    for(Coalition& coal: mCoalitions)
        if(coal.getCoalIdByAgentId(agentId) != -1)
            return coal.getCoalIdByAgentId(agentId);
    return -1;        
}

int Simulation::getCoalitionMandates(int coalId)
{
    return mCoalitions[coalId].getTotalMandates(*this);
}

int Simulation::getPartyMandates(int partyId)
{
    return this->getParty(partyId).getMandates();
}

int Simulation::getEdgeW(int p1, int p2)
{
    return mGraph.getEdgeWeight(p1, p2);
}

void Simulation::joinCoalition(int agent, int partyId)
{
    mCoalitions[mAgents[agent].getCoalitionOfAgent(*this)].addParty(partyId);
}

vector<int> Simulation::getAgentsByCoalId(int coalId)
{
    return mCoalitions[coalId].getAgents();
}

vector<int> Simulation::getNeighbors(int party)
{
    return mGraph.getNeighbors(party);
}

vector<int> Simulation::getOfferedParties(int agentId)
{
    for(Agent& agent: mAgents)
        if(agent.getId() == agentId)
            return agent.getAgentOffers();
    return vector<int>{};
}

void Simulation::partyOffer(int party, int agent)
{
    mGraph.setPartyState(party,agent, CollectingOffers);
}

void Simulation::cloneAgent(int agentToJoin, int partyId)
{
    SelectionPolicy* sp = nullptr;
    for (Agent& agent: mAgents)
       if (agentToJoin == agent.getId())
       {
            sp = agent.getSp();
            break;
       }
    int aId = mAgents.size();
    Agent a (aId, partyId, sp);
    mAgents.push_back(a);
    mCoalitions[getCoalition(agentToJoin)].addAgent(aId);
}

