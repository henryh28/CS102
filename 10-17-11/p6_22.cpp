

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;


        vector <double> get_input()
        {
                vector <double> data;
                bool continue_input = true;
                while (continue_input)  
                {
                        cout << "Please input up to 5 values no greater than 100, use any letter key to quit: ";
                        double input;
                        cin >> input;                   // input validation
                        if (cin.fail() || input > 100 || input < -100)
                        {
                                continue_input = false;
                        }
                        else
                        {
                                data.push_back(abs(input));     // writes input to vector element
                        }
                }
                return data;                            // returns user input as a vector
        }


        vector <string> fill_captions()
        {
                vector <string> captions(5); 
                captions[0] = "Egypt";
                captions[1] = "France";
                captions[2] = "Japan";
                captions[3] = "Uruguay";
                captions[4] = "Switzerland";
                return captions;
        }


        vector <double> create_bar_data(vector <double> database, double max_value)
        {
                vector <double> bar_data;               // creates matching vector
                for (int counter = 0; counter < database.size(); counter++)
                {
                        bar_data.push_back (((database[counter] / max_value) * 100));
                }
                
                return bar_data;
        }


        void bar_chart(vector <double> data, vector <double> bar_data, vector <string> captions)
        {
                for (int counter = 0; counter < bar_data.size (); counter++)
                {
                        cout << right << setw(15) << captions[counter] << " ";
                        for (double bar_counter = 0; bar_counter < bar_data[counter]; bar_counter = bar_counter + 2.5)
                        {
                                cout << "*";
                        }
                        cout << endl;
                }
        }



int main()
{
        vector <double> data = get_input ();
        vector <string> captions = fill_captions ();
        
        /* The following performs very basic input validation */
        if (data.size() == 0)
        {
                cout << "Program requires at least one valid input to continue." << endl;
        }
        else if (data.size() > 5)
        {
                cout << "Maximum of only 5 data entry allowed." << endl;
        }
        else
        {       
                /* This code block checks the vector for the element with the largest value */
                double max_value = data[0];
                for (int counter = 1; counter < data.size (); counter++)
                {
                        if (data [counter] > max_value)
                        {
                                max_value = data [counter];
                        }
                }

                /* The below function creates a vector of % that matches the data vector elements */            
                vector<double> bar_data = create_bar_data(data, max_value);
        
                /* The below function outputs the user input along with the appropriate bars */
                bar_chart (data, bar_data, captions);
        
        }


}
