


#include <iostream>
using namespace std;


int main()
{
        
                int year;
                
                cout << "Please enter a year: ";
                cin >> year;
        
        
        bool leap_year;
        leap_year = 0;

        if (year >= 1582)
        {       
                if(year % 4 == 0)               // year divisible by 4 = leap year
                        leap_year = true;
                else                            // year !divisible by 4 != leap year
                        leap_year = false;


                if (year % 100 == 0)
                {
                        if (year % 400 == 0)
                                leap_year = true;
                        else
                                leap_year = false;
                } 
        }
        else
        {       
                if(year % 4 == 0)               // year divisible by 4 = leap year
                        leap_year = true;
                else                            // year !divisible by 4 != leap year
                        leap_year = false;
        }
        
        
                if(leap_year)
                {
                        cout << year << " is a leap year";
                }       
                else
                {       
                        cout << year << " is not a leap year";
                }
        
}
