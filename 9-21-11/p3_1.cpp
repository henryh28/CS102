


#include <iostream>
using namespace std;






int main()
{
        double degrees, degrees_celsius;
        char scale;
        string state;
        
                cout << "Enter temperature and scale of the water: ";
                cin >> degrees >> scale;
        
        
                degrees_celsius = degrees;
                if( scale == 'F' ) degrees = 5.0/9.0 * (degrees-32); cout << degrees << endl;
        
        
                if( degrees <= 0) state = "solid";
                else if( degrees >= 100 ) state = "gas";
                else state = "liquid";
        
         
                cout << "At " << degrees_celsius << 'C' << ", water is " << state << endl;
        
 
}
