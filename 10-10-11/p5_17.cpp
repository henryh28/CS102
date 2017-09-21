
        
                #include <iostream>
                #include <cstdlib>
                using namespace std;
        
        
        int get_zip_code()
        {
                int zip_code = 0;
                cout << "Please enter a 5 digit zip code: ";    
                cin >> zip_code;
                if ( cin.fail() )                               // Ensures integer input
                {
                        cin.clear();
                        cout << "Please rerun the program and only enter a 5 digit zip code. ";
                        exit(1);
                }
                if(zip_code > 99999 || zip_code < 10000)        // Ensures 5 digit input
                {
                        cin.clear();
                        cout << "Please rerun the program and only enter a 5 digit zip code. ";
                        exit(1);
                }
                return zip_code;
        }
        
        
        void print_bar_code(int zip_digit)
        {
                if (zip_digit == 1)
                        cout << ":::||";
                if (zip_digit == 2)
                        cout << "::|:|";
                if (zip_digit == 3)
                        cout << "::||:";
                if (zip_digit == 4)
                        cout << ":|::|";
                if (zip_digit == 5)
                        cout << ":|:|:";
                if (zip_digit == 6)
                        cout << ":||::";
                if (zip_digit == 7)
                        cout << "|:::|";
                if (zip_digit == 8)
                        cout << "|::|:";
                if (zip_digit == 9)
                        cout << "|:|::";
                if (zip_digit == 0)
                        cout << "||:::";
        }
        
        
        int create_check_digit(int zip_sum)
        {
                int check_digit = 0;
                check_digit = (10 - (zip_sum % 10));
                if ((zip_sum % 10) < 1)
                        check_digit = 0;
                return check_digit;
        }
        



int main()
{
        int zip_code = get_zip_code();

        cout << "For Zip code " << zip_code << ", the associated bar code is: " << endl;


        /* This code block splits up the zip code into individual integers */
        int zip1 = 0, zip2 = 0, zip3 = 0 , zip4 = 0, zip5 = 0, zip_sum;
        int zip_copy = zip_code;
        zip5 = zip_copy % 10;
        zip_copy = zip_copy /= 10;
        zip4 = zip_copy % 10;
        zip_copy = zip_copy /= 10;
        zip3 = zip_copy % 10;
        zip_copy = zip_copy /= 10;
        zip2 = zip_copy % 10;
        zip_copy = zip_copy /= 10;
        zip1 = zip_copy;
        zip_sum = (zip1 + zip2+ zip3 + zip4 + zip5);


        /* Calls the check digit creater function */
        int check_digit = create_check_digit(zip_sum);

        cout << "|";
        print_bar_code(zip1);
        print_bar_code(zip2);
        print_bar_code(zip3);
        print_bar_code(zip4);
        print_bar_code(zip5);
        print_bar_code(check_digit);
        cout << "|";
}
