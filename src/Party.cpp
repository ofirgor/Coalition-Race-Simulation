#include "Party.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting)
{
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

void Party::step(Simulation &s)
{
    if (timer == 3)
    {
        int joinedParty;
        joinedParty = mJoinPolicy->Join(partyOffers, s);
        mState = Joined;

    }
    if (mState == CollectingOffers)
        timer +=1;
    
    // TODO: implement this method
}
