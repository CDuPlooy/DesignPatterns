#include <iostream>
#include <string>

using namespace std;

class Square{
      public:
            Square(int a , int b){
                  this->height = a;
                  this->width = b;
            }

            void Display(){
                  std::cout << "Width : " << width << std::endl << "Height : " << height << std::endl << std::endl;
            }

            Square operator+(const Square &aSquare){ // Square ++
                  Square new_square(0,0);

                  new_square.width = aSquare.width + this->width;
                  new_square.height = aSquare.height + this->height;

                  return new_square;
            }

            Square operator++(){ //++Square
                  this->width = 0;
                  this->height = 0;
                  return *this;
            }

            Square operator++ ( int ){ // Postfix Square++
                  this->width++;
                  this->height++;
                  return *this;
            }

            bool operator== (const Square &test){
                  if(test.height != this->height)
                        return false;
                  if(test.width != this->width)
                        return false;

                  return true; //fallthough
            }



            Square operator=(const Square &anotherSquare){
                  if(this == &anotherSquare)
                        return *this;

                  width = anotherSquare.width;
                  height = anotherSquare.height;
                  return *this;
            }
      private:
            int height, width;
};


int main(){
      Square aSquare(1,2);
      Square bSquare(3,2);
      Square cSquare(6,9);
      cout << "First add two squares: " << endl;
      aSquare = aSquare + bSquare;
      aSquare.Display();

      cout << "Now increment a square: " << endl;
      aSquare++;
      aSquare.Display();

      cout << "Reassign cSquare to aSquare: " << endl;
      aSquare = cSquare;
      aSquare.Display();

      cout << "Testing equality: " << endl;
      if(aSquare == cSquare)
            cout << "\tObjects are equal." << endl;
      else
            cout << "\tObjects are not equal!" << endl;
}
