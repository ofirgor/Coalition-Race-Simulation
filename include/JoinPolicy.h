#pragma once

class JoinPolicy {
    public:
        virtual int Join(vector<int> partyOffers, Simulation &simulate) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual int Join(vector<int> partyOffers, Simulation &simulate);

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int Join(vector<int> partyOffers, Simulation &simulate);
};