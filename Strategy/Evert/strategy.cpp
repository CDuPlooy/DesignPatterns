/*
Evert Geldenhuys
2016-08-17

Description:
    Simple example implementation of the strategy design pattern.

    Creates a person (context) and gives them a type of hand/gender (Concrete Strategy).
    The hand/gender is the abstract strategy.
*/

#include <iostream>

using namespace std;

class Hand;
class HandAttacker;
class ManHand;

class Hand // Strategy
{
public:
    virtual void attack()
    {
        cout << "<FUNCTION NOT IMPLEMENTED: attack()\n";
    }

    virtual ~Hand(){} // Otherwise compiler error.
};

class ManHand : public Hand // Concrete Strategy. Inherits from Strategy
{
public:
    void attack()
    {
        cout << "You punch like a man.\n";
    }
};

class WomanHand : public Hand // Concrete Strategy. Inherits from Strategy
{
public:
    void attack()
    {
        cout << "You just got your nails done. Not attacking.\n";
    }
};

class HandAttacker // Context
{
public:
    HandAttacker()
    {
        // Variable needs to be initialised so that we can
        // check its value in setHandType().
        handType = NULL;
    }

    void attack()
    {
        if (handType == NULL)
            cout << "Please give me a hand first!\n";
        else
            handType->attack();
    }

    void setHandType(Hand *type)
    {
        handType = type;
    }

private:
    Hand* handType;
};

int main()
{
    // man will have a type of hand to attack with
    HandAttacker man;
    ManHand *maleHand = new ManHand();

    man.setHandType(maleHand);
    man.attack();

    cout << "Injecting a lot estrogen into the man...\n";
    
    WomanHand *girl = new WomanHand();

    man.setHandType(girl);
    man.attack();

    delete maleHand;
    delete girl;

    return 0;
}
