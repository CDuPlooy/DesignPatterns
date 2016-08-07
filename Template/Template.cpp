#include <iostream>

/*
The template method is really basic in the sense that it just minimizes code.

This particular example seems a bit stupid because it is.

It all boils down to you have one function. Find the highest number between a and b.
The code to find the lowest is very much the same so we can use the template design pattern.

The Abstract class acts as a wrapper class around the two concrete classes which actually implement
the pick function ( a part of some larger algorithm).

Usually there is one Abstract class and more than one Concrete class.
The participants are:
      Abstract Class
      Concrete Classes
*/

class numberList{ //Abstract class -> Is a primitive set of operations that subclasses can implement to finish a particular algorithm.
      public:
      void getHighestOrLowest(int a,int b){ //The larger algorithm
            1+1; //Static parts of the larger algorithm
            std::cout << pick(a,b) << std::endl;            //Dynamic overridden part of the larger algorithm
            2+2; //Static parts of the larger algorithm
      }

      private:
            virtual int pick(int a, int b) = 0; //Remember to assign this to 0;

};

class numberList_Highest : public numberList{//Concrete class -> Carries out smaller sets of operations which are part of a larger algorithm
      virtual int pick(int a, int b){
            std::cout << "Highest : " << std::endl;

            if(a > b)
                  return a;
            else
                  return b;
      }
};

class numberList_Lowest : public numberList{//Concrete class  -> Carries out smaller sets of operations which are part of a larger algorithm
      virtual int pick(int a, int b){
            std::cout << "Lowest : " << std::endl;

            if(a < b)
                  return a;
            else
                  return b;
      }
};

int main(){
      numberList *number = new numberList_Lowest();
      number->getHighestOrLowest(2,1);

      numberList *anotherNumber = new numberList_Highest();
      anotherNumber->getHighestOrLowest(2,3);
      return 0;
}
