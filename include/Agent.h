#pragma once

#include <vector>
#include "Graph.h"
class Simulation;

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& other);
    Agent& operator=(const Agent& other);
    virtual ~Agent();
    Agent(Agent&& other) noexcept ;
    Agent& operator=(Agent&& other);
    int getPartyId() const;
    int getId() const;
    SelectionPolicy* getSp();
    int getCoalitionOfAgent(Simulation &s);
    bool offeredByCoalition(Simulation &sim, int partyId);
    void step(Simulation &sim);
    vector<int> getAgentOffers();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    bool active;
    std::vector<int> alreadyOffered;
};
