#pragma once
#include <string>
#include <vector>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    Party(const Party& other);
    Party& operator=(const Party& other);
    virtual ~Party();
    Party(Party&& other) noexcept ;
    Party& operator=(Party&& other);
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void setPartyOffers(int agent);
    void step(Simulation &s);
    const string &getName() const;
    

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    std::vector<int> partyOffers;
};
