#include "../include/JoinPolicy.h"
#include "../include/Party.h"
#include "../include/Simulation.h"
#include <vector>

    
int MandatesJoinPolicy::Join(vector<int> partyOffers, Simulation &simulate){
    int maxMandates = 0;
    int maxPartyID = 0;
    for(int p: partyOffers){
        if(maxMandates < simulate.getParty(p).getMandates()){
            maxMandates = simulate.getParty(p).getMandates();
            maxPartyID = p;
        }
    }
    return maxPartyID;
}
int LastOfferJoinPolicy::Join(vector<int> partyOffers, Simulation &simulate){
    return partyOffers[0];
}
