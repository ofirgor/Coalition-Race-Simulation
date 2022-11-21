#pragma once
#include <vector>
using std::vector;
class Simulation;

class SelectionPolicy
{
public:
    virtual ~SelectionPolicy() = default;
    virtual int select(Simulation &s, vector<int> neighbors, int currParty)=0;
    virtual SelectionPolicy* clone() =0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{ 
public:
    virtual int select(Simulation &s, vector<int> neighbors, int currParty);
    virtual MandatesSelectionPolicy* clone(); 
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
public:
    virtual int select(Simulation &s, vector<int> neighbors, int currParty);
    virtual EdgeWeightSelectionPolicy* clone();
};