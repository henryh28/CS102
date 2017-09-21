#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;


bool has_key_word (string line, string key_word)
{
	istringstream stream;
	stream.str(line);
	string word;

	while (stream >> word)
	{
		if (word == key_word)
		{
			return true;
		}
	}
	return false;
}



int main(int argc, char* argv[])
{
	if (argc <3 || argc > 3)
	{
		cout << "Proper syntax for program find is \"find keyword file.extension\"" << endl;
		return 1;
	}

	string filename, key_word;
	key_word = argv[1];
	filename = argv[2];



	ifstream input_file;
	input_file.open(filename.c_str());

	int line_number = 0;
	string line;
	while (getline(input_file, line))
	{
		line_number++;
		if (has_key_word(line, key_word))
		{
			cout << setw(8) << line_number << ":" << line << endl;
		}
	}
	return 0;
}


