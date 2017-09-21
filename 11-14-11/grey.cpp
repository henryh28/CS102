#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


// apply greyscale to the image
void sunset (int& blue, int& green, int& red)
{

	int grey = 0;
	grey = (red * .3) + (green * .59) + (blue * .11);
	blue = grey;
	green = grey;
	red = grey;
}


// Provides image dimension to main function
int get_integer(fstream& bmp, int offset)
{
	bmp.seekg(offset);
	int result = 0;
	int base = 1;
	for (int i = 0; i < 4; i++)
	{
		result = result + bmp.get() * base;
		base = base * 256;
	}
	return result;
}


int main()
{
	cout << "Please enter the filename: ";
	string filename;
	cin >> filename;


	// Creates file stream
	fstream bmp;

	
	// Opens file as binary file
	bmp.open(filename.c_str(), ios::in | ios::out | ios::binary);

	
	// Calls get integer function for file dimensions
	int file_size = get_integer (bmp, 2);
	int start = get_integer (bmp, 10);
	int width = get_integer (bmp, 18);
	int height = get_integer (bmp,22);

	
	// Checks that height is divisible by 4
	int scanline_size = width * 3;
	int padding = 0;
	if (scanline_size % 4 != 0)
	{
		padding = 4 - (scanline_size % 4);
	}


	// Confirms file is 24-bit bmp file format
	if (file_size != start + (scanline_size + padding) * height)
	{
		cout << "Not a valid 24-bit BMP file." << endl;
		return 1;
	}


	// Sets get pointer at offset 10
	bmp.seekg(start);		


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)	
		{
			int position = bmp.tellg();	

			int blue = bmp.get();
			int green = bmp.get();
			int red = bmp.get();
		
			sunset ( blue, green, red);	
			

			// Sets put pointer at offset 10
			bmp.seekp(position);	

			bmp.put(blue);	
			bmp.put(green);	
			bmp.put(red);	

		}
		bmp.seekg (padding, ios::cur);	
	}
	return 0;
}











