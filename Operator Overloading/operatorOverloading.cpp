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

            Square operator+(const Square &aSquare){ // Square + Square
                  Square new_square(0,0);

                  new_square.width = aSquare.width + this->width;
                  new_square.height = aSquare.height + this->height;

                  return new_square;
            }

            Square operator++ ( int ){ // Square++
                  this->width++;
                  this->height++;
                  return *this;
            }

            Square operator=(const Square &anotherSquare){ //still working on this one.
                  if(this == &anotherSquare)
                        return *this;

                  Square *new_square = new Square(1,2);
                  return *new_square;
            }
      private:
            int height, width;
};


int main(){
      Square aSquare(1,2);
      Square bSquare(3,2);
      Square cSquare(5,5);
      cout << "First add two squares: " << endl;
      aSquare = aSquare + bSquare;
      aSquare.Display();

      cout << "Now increment a square: " << endl;
      aSquare++;
      aSquare.Display();

      cout << "Reassign cSquare to aSquare: " << endl;
      aSquare = cSquare;
      aSquare.Display();
}
