#include "Party.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting)
{
    timer = 0;
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::setPartyOffers(int agent)
{
    partyOffers.push_back(agent);
} 

void Party::step(Simulation &s)
{ 
    if (mState == CollectingOffers) {
        timer += 1;
        if (timer == 3) {
            int agentToJoin;
            agentToJoin = mJoinPolicy->join(partyOffers, s);
            s.joinCoalition(agentToJoin, mId);
            mState = Joined;
            s.cloneAgent(agentToJoin,mId);
        }
    }
    if(mState == Waiting)
        if(partyOffers.size() > 0) //received an offer
            mState = CollectingOffers;

}
