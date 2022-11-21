#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

void Graph:: step(Simulation &s) 
{
    for(Party& party: mVertices)
        party.step(s);
}

vector<int> Graph::getNeighbors(int party)
{
    std::vector<int> neighbors;
    for (int i = 0; i < mEdges[party].size(); i++)
    {
       if (mEdges[i][party] != 0)
        {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}
const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

void Graph::setPartyState(int partyId, int agent, State state)
{
    Party& p = mVertices[partyId];
    if(p.getState() == Waiting)
        p.setState(state);
    p.setPartyOffers(agent);

}

bool Graph::isAllJoined()const
{
    for(const Party& p: mVertices)
        if (p.getState() != Joined)
            return false;
    return true;
}