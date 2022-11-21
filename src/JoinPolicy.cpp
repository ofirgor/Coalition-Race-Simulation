#include "../include/JoinPolicy.h"
#include "Simulation.h"
#include <vector>

    
int MandatesJoinPolicy::join(vector<int> partyOffers, Simulation &s)
{
    int maxMandates = 0;
    int agentMax = 0;
    int cMandates;
    for(int agent: partyOffers){
        cMandates =  s.getCoalitionMandates(s.getCoalition(agent));
        if (maxMandates < cMandates)
        {
           maxMandates = cMandates;
           agentMax = agent;
        }  
    }
    return agentMax;
}
int LastOfferJoinPolicy::join(vector<int> partyOffers, Simulation &s)
{
    return partyOffers.back();
}
MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return new MandatesJoinPolicy(*this);
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return new LastOfferJoinPolicy(*this);
}


