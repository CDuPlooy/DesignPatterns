#include <iostream>
#define ushort unsigned short //An example of using #defines

/*
The prototype design pattern. Explained (mentally - get it? ) in terms of a serious sam game.
I got information from http://gameprogrammingpatterns.com/prototype.html

The idea behind the prototype method is that you don't need to repeat code. You can
have a sort of generic prototype which implements all the classes and child classes
that you need ; Which is to say prototyping!

Connor Armand du Plooy 2016

Participants:
     Abstract prototype -> Mob: Declares an interface for cloning.
     Concrete protoype(s) -> RhinoCyberToy: Implements the cloning.
     Client -> mobGenerator: Asks the prototype (concrete) to clone itself.
*/
class Mob;
class mobGenerator;


class Mob{ //Abstract prototype  : Mob is an abstract class and will never be implemented.
     public:
          virtual ~Mob(){
          /*
          Not that you care , but the destructor for an abstract class should not be left as the default
          otherwise the linker will generate errors.

          Also. Did you know 1+1; compiles? It Does!
          */
          1+1; //This is useless. Read the comments and don't get confused.

          /*
          #JustCompilerThings
          I wonder if the compiler actually executes 1+1... I'll test it :P

          */
          };
          virtual Mob *mobClone() = 0;
};

class mobGenerator{// Client : Asks any concrete protoype to clone itself.
     public:
          mobGenerator(Mob *dummyPointer){
               prototype = dummyPointer;
          };
          Mob *spawnMonster(){
               return prototype->mobClone();
          }
     private:
          Mob *prototype;
};


class RhinoCyberToy : public Mob{ //Concrete protoype : Implements the actual cloning overwridden from it's parent class.
     public:
          RhinoCyberToy( ushort hp , ushort ap ){
               hitPoints = hp;
               attackPoints = ap;
          }
          virtual Mob *mobClone(){
               return new RhinoCyberToy(hitPoints,attackPoints);
          }
     private:
          ushort hitPoints;
          ushort attackPoints;
};

class Mordekai : public Mob{//Concrete protoype : Implements the actual cloning overwridden from it's parent class.
     public:
          Mordekai( ushort hp , ushort ap ){
               hitPoints = hp;
               attackPoints = ap;
          }
          virtual Mob *mobClone(){
               return new Mordekai(hitPoints,attackPoints);
          }
     private:
          ushort hitPoints;
          ushort attackPoints;
};

class Cecil : public Mob{ //Concrete protoype : Implements the actual cloning overwridden from it's parent class.
     public:
          Cecil( ushort hp , ushort ap ){
               hitPoints = hp;
               attackPoints = ap;
          }

          virtual Mob *mobClone(){
               return new Cecil(hitPoints,attackPoints);
          }
     private:
          ushort hitPoints;
          ushort attackPoints;
};


int main(){
     Mordekai mordekai(1,2);
     mobGenerator *MordekaiGenerator = new mobGenerator(&mordekai); //Just an example of how to use a static instance of Mordekai.

     Cecil *cecil = new Cecil(30,50);
     mobGenerator *CecilGenerator = new mobGenerator(cecil); //Does this help understand pointers?

     RhinoCyberToy *rct = new RhinoCyberToy(30,20);
     /*
     The constructor for mobGenerator causes an instance of RhinoCyberToy to be saved in it's memory space.
     Because of this the generator will continue to work regardless of whether the actual instance of RhinoCyberToy
     has been destroyed.
     */
     mobGenerator *rctGenerator = new mobGenerator(rct);


     delete rct;
     delete cecil;
     delete CecilGenerator;
     delete rctGenerator;
     delete MordekaiGenerator;
     //delete mordekai will result in undefined behaviour because mordekai is statically declared.
     //It could just as easily have been dynamically created but I was trying to showcase pointers.

     return 0;
}
