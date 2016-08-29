/*
Connor Armand du Plooy 2016
*/
#include <iostream>
#include <vector>

/*
Optionally can have a  client which manipulates the object that comprises the composite.
*/

class parentClass{  //Component-> The interface with which the client interacts.
public:
      virtual void showChar() = 0;
};

class charHolder : public parentClass{      //Leaf -> does not have children , defines the primitive objects of the composition.
public:
      char value;
      charHolder(char val){
            value = val;
      }
      void showChar(){
            std::cout << value;
      }
};

class stringHolder : public parentClass{    //Composite -> Contains children that are either composites or leaves.
public:
      std::vector <parentClass *> children;
      void add(parentClass *pClass){
            children.push_back(pClass);
      }
      void showChar(){
            for(size_t i = 0 ; i < children.size() ; i++)
                  children[i]->showChar();
      }
};

int main(){
      stringHolder stringContainer[20];
      stringContainer[0].add(new charHolder('H'));
      stringContainer[1].add(new charHolder('e'));
      stringContainer[2].add(new charHolder('l'));
      stringContainer[3].add(new charHolder('l'));
      stringContainer[4].add(new charHolder('o'));
      for(unsigned short i = 0 ; i < 5 ; i++)
            stringContainer[i].showChar();
      std::cout << std::endl;
      return 0;
}
