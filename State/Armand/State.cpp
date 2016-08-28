#include <iostream>
/*
   Connor Armand du Plooy
   State Pattern:

   This examples uses entities , a particular entity will perform a particular action in a particular state.
   I apologise for the strange indentation , it would seem my editor is misbehaving.   
*/

using namespace std;

class Animal;
class Demeanour;
class Impatient;
class Loving;
class Irrirable;

class Animal{
    private:
        Demeanour *demeanour;
    public:
        Animal();	//allocation of incomplete type if inlined
        void feed();
};

class Demeanour{
    public:
        string mood;
        virtual void act() = 0;//pure virtual
        virtual Demeanour *change() = 0;
        virtual ~Demeanour(){};
};

class Impatient : public Demeanour{
    public:
        string mood = "Impatient";
        void act(){
            cout << "Rawr, food now" << endl;
        }
        ~Impatient(){};
    protected:
        Demeanour * change();
};

class Loving : public Demeanour{
    public:
        string mood = "Loving";
        void act(){
            cout << "Food for meh <3" << endl;
        }
        ~Loving(){};
    protected:
        Demeanour * change();
};

class Irritable : public Demeanour{
    public:
        string mood = "Irritable";
        void act(){
            cout << "I couldn't come up with something an irritable animal would do." << endl;
        }
        ~Irritable(){};
    protected:
        Demeanour *change();
};


Animal::Animal(){
    demeanour = new Loving();
}
void Animal::feed(){
    demeanour->act();
    demeanour = demeanour->change();
}

Demeanour * Impatient::change(){
    return new Loving();
}
Demeanour * Loving::change(){
    return new Irritable();
}
Demeanour * Irritable::change(){
    return new Impatient();
}

int main(){
    Animal Lara; //The coolest doge in the world.
    Lara.feed();
    Lara.feed(); // ... Overfeeding your dog might cause it to become irritable..
    Lara.feed();
    Lara.feed(); // Lara loves food though.
    return 0;
}
