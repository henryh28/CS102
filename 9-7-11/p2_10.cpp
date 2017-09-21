

#include <iostream>
using namespace std;

int main()
{
        double price = 2.95;  // floating-point value
        double price1 = 4.35;  // floating-point value

        
                int dollars = price;
                int dollars1 = price1;
        ;
        cout << "If unit price is $2.95, then dollar amount is = $" << dollars << endl;

        
                double answer = (price-dollars) * 100 +.5;
                double answer1 = (price1-dollars1) * 100 +.5;
        ;
        cout << "Adding 0.5 to result of Unit price minus dollar amount multipled by 100 = " << answer << endl;

        
                int cents = answer;
                int cents1 = answer1;
        ;
        cout << "Actual remaining amount in cents is "<< cents << endl << endl << endl;

        

        cout << "If unit price is $4.35, then dollar amount is = $" << dollars1 << endl;

        cout << "Adding 0.5 to result of Unit price minus dollar amount multipled by 100 = " << answer1 << endl;

        cout << "Actual remaining amount in cents is "<< cents1 << endl;
}

