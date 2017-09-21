




#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


        int main()
        {

                
                        cout << "Please enter numeric value for length of the rectangle: ";
                        double length;
                        cin >> length;

                        cout << "Please enter numeric value for width of the rectangle: ";
                        double width;
                        cin >> width;
                
                
                        double area = 0;
                        double perimeter =0;
                        double diagonal = 0;

                        area = length * width;
                        perimeter = (length * 2) + (width * 2);
                        diagonal = sqrt ( pow(length,2)+ pow(width,2) );
                
                
                        cout << "The area of the rectangle is: " << area << endl;
                        cout << "The perimeter of the rectangle is: " << perimeter << endl;
                        cout << "The diagonal length of the rectangle is: " << diagonal << endl;
                

        }
