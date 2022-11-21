#include "Agent.h"
#include "Simulation.h"
#include <vector>
#include <algorithm>
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), active(true), alreadyOffered()
{
    // You can change the implementation of the constructor, but not the signature!
}

 Agent::Agent(const Agent& other):mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), active(other.active), alreadyOffered()
 {
 }

 Agent& Agent::operator=(const Agent& other)
 {
    if(this != &other) {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        this->mAgentId = other.mAgentId;
        this->mPartyId = other.mPartyId;
        this->active = other.active;
        this->mSelectionPolicy = other.mSelectionPolicy->clone();
    }
     return *this;
 }
 Agent:: ~Agent()
{
    if(mSelectionPolicy)
        delete mSelectionPolicy;
}

Agent::Agent(Agent&& other) noexcept: mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), active(other.active), alreadyOffered()
{
    other.mSelectionPolicy = nullptr;
}

Agent& Agent::operator=(Agent&& other)
{
    if (mSelectionPolicy)
        delete mSelectionPolicy;
    this->mAgentId = other.mAgentId;
    this->mPartyId = other.mPartyId;
    this->active = other.active;
    this->mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

SelectionPolicy* Agent::getSp()
{
    return mSelectionPolicy->clone();
}

int Agent::getCoalitionOfAgent(Simulation &s)
{
    return s.getCoalition(mAgentId);
}

vector<int> Agent::getAgentOffers()
{
    return alreadyOffered;
}

bool Agent::offeredByCoalition(Simulation &s, int partyId)
{
    int agentCoalition = getCoalitionOfAgent(s);
    std::vector<int> agentsOfCoalition = s.getAgentsByCoalId(agentCoalition);
    std::vector<int> offeredParties;
    for(int agent: agentsOfCoalition){
        offeredParties = s.getOfferedParties(agent);
        for (int p: offeredParties)
            if (p == partyId)
                return true; 
    }
    return false;
}

void Agent::step(Simulation &sim)
{
    if(this->active){
        std::vector<int> neighbors = sim.getNeighbors(mPartyId);
        std::vector<int> validParties;
        std::vector<int>::iterator it;
        bool offered;
        int partyToOffer;
        for (int n: neighbors){
            it = std::find(alreadyOffered.begin(), alreadyOffered.end(), n);
            offered = it != alreadyOffered.end();
            if (sim.getParty(n).getState() != Joined && !offered && !offeredByCoalition(sim,n))
                validParties.push_back(n);   
        }
        if(validParties.size() != 0){
            partyToOffer =  mSelectionPolicy->select(sim, validParties, mPartyId);
            alreadyOffered.push_back(partyToOffer);
            sim.partyOffer(partyToOffer, mAgentId);        
        }
        else
            active = false;
    }   
    
    // TODO: implement this method
}
