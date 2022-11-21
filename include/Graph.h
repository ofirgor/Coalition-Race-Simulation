#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    vector<int> getNeighbors(int partyId);
    const Party &getParty(int partyId) const;
    void step(Simulation &s);
    void setPartyState(int partyId, int agent, State state);
    bool isAllJoined() const;
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
