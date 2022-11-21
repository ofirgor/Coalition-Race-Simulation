#include "Party.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0), partyOffers()
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), timer(other.timer), partyOffers()
{
}

Party& Party::operator=(const Party& other)
{
    if (mJoinPolicy)
        delete mJoinPolicy;
    this->mId = other.mId;
    this->mName = other.mName;
    this->mMandates = other.mMandates;
    this->mState = other.mState;
    this->mJoinPolicy = other.mJoinPolicy->clone();
    return *this;
}

Party::~Party()
{
    if(mJoinPolicy)
        delete mJoinPolicy;
}
Party::Party(Party&& other) noexcept:mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), timer(other.timer), partyOffers()
{
    other.mJoinPolicy = nullptr;
}
Party& Party::operator=(Party&& other)
{
    if(this != &other) {
        if (mJoinPolicy)
            delete mJoinPolicy;
        this->mId = other.mId;
        this->mName = other.mName;
        this->mMandates = other.mMandates;
        this->mState = other.mState;
        this->mJoinPolicy = other.mJoinPolicy;
        other.mJoinPolicy = nullptr;
    }
    return *this;
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
