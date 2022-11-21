#pragma once
#include "Simulation.h"
#include <vector>

class JoinPolicy
{
public:
    virtual ~JoinPolicy() = default;
    virtual int join(vector<int> partyOffers, Simulation &simulate) = 0;
    virtual JoinPolicy* clone() = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    virtual int join(vector<int> partyOffers, Simulation &simulate);
    virtual MandatesJoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    virtual int join(vector<int> partyOffers, Simulation &simulate);
    virtual LastOfferJoinPolicy* clone();
};