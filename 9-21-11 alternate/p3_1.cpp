


#include <iostream>
#include <cmath>
#include <string>
using namespace std;






int main()
{
        
                double temp;
                cout << "Enter numerical value of temperature: ";
                cin >> temp;

                string scale;
                cout << "Enter C for celsius or F for farenheit: ";
                cin >> scale;
        
        
                string state;
                if (scale == "C")
                {
                        if (temp < 0)
                        {
                                state = "Solid";
                        }
                        if ( 0 <= temp and temp <= 100)
                        {
                                state = "liquid";
                        }
                        if (temp > 100)
                        {
                                state = "gas";
                        }
                }
                if (scale == "F")
                {
                        if (temp < 32)
                        {
                                state = "Solid";
                        }
                        if ( 32 <= temp and temp <= 212)
                        {
                                state = "liquid";
                        }
                        if (temp > 212)
                        {
                                state = "gas";
                        }
                }
        
        
                cout << "For the given temperature using given scale, water will be a " << state << endl;
        
}
