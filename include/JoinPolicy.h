#pragma once
#include "Simulation.h"
#include <vector>

class JoinPolicy
{
public:
    virtual int join(vector<int> partyOffers, Simulation &simulate) = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    virtual int join(vector<int> partyOffers, Simulation &simulate);

};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    virtual int join(vector<int> partyOffers, Simulation &simulate);
};