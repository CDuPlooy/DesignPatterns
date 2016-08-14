#include <iostream>
#include <cstdlib>

class Position;
class Point;
class PointStore;

class Position{ //Caretaker -> An object used to implement the undo function -> keeps the memento safe.
      friend class Point; //So Point inherits Positions attributes

      private:
            Position(){};
            int x;
            int y;
};

class PointStore{ //Memento -> Stores member attributes of the originator.
      public:
            PointStore(){
                  token = NULL; //to fix a segmentation fault.
            }
            void rememberMe(Position *position){
                  if(token) //If PointStore is already storing a position (token) , free it.
                        delete token;
                  //In either case reassign the token to the new position
                  token = position;
            }

            Position *getToken(){
                  return token;
            }
      private:
            Position *token;
};

class Point{ //Originator -> Creates a memento.
      public:
            Point(int _x , int _y){
                  x = _x;
                  y = _y; //Or this->y = y; would probably work to if the compiler is smart enough.
            }
            void rollback(Position *position){
                  x = position->x;
                  y = position->y;

                  delete position; //position is the mementor here.
            }
            void move(int x , int y){
                  this->x = x;
                  this->y = y;
            }
            Position *checkpoint(int x , int y){
                   Position *position = new Position();

                   position->x = x;
                   position->y = y;

                   return position;
            }
      private:
            int x;
            int y;
};

int main(){
      PointStore pointstore;
      Point point(1,2);

      point.move(1,1);

      pointstore.rememberMe(point.checkpoint(1,1));
      point.rollback(pointstore.getToken());

      return 0;

}

/*
A Brief explanation of what's happening.

Pointstore acts as a memento , an object which can store points.
We can then call the rollback function of point with an argument to rollback to a particular pointstore.
Making undo a very easy function to implement.

Position is not called in main at all , it is just used by point.
Thus Point is a friendly class of position.

Without the friend class specifier Point won't be able to call position's constructor. The friend specifier
exposes Position's interface to point.
*/

//This is a test line
