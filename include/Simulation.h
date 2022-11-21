#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    int getCoalition(int agentId);
    int getCoalitionMandates(int coalId);
    int getPartyMandates(int partyId);
    int getEdgeW(int p1, int p2);
    void joinCoalition(int agent, int partyId);
    vector<int> getNeighbors(int party);
    vector<int> getAgentsByCoalId(int coalId);
    vector<int> getOfferedParties(int agentId);
    void partyOffer(int party, int agent);
    void cloneAgent(int agentToJoin, int partyId);
private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};
