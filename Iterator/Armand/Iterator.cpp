/*
Connor Armand du Plooy
Iterator pattern
*/
#include <iostream>
#include <string>
using namespace std;

class Cart{
      friend class cartIterator;
      public:
            Cart(){
                  at = 0;
            }
            string items[50];
            void push(string aString){
                  items[at++] = aString;
            }
      private:
            size_t at;


};
class cartIterator{
      public:
            cartIterator(Cart *cart){
                  _cart = cart;
                  at = 0;
            }
            string getElement(){
                  return _cart->items[at];
            }
            void nextElement(){
                  at++;
            }
            void previousElement(){
                  at--;
            }
            bool isNull(){
                  if(_cart->items[at].size() != 0)
                        return false;
                  return true;
            }
      private:
            size_t at;
            Cart *_cart;
};

int main(){
      Cart cart;
      cart.push("Carrot");
      cart.push("Apple");
      cart.push("Pear");

      cartIterator iterator(&cart);
      for(; !iterator.isNull(); iterator.nextElement()){
            cout << iterator.getElement() << endl;
      }
      return 0;
}
