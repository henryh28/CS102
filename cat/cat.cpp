
#include <iostream>
#include <audiere.h>
#include <fl/fl_double_window.h>
#include <fl/fl.h>
#include <fl/fl_jpeg_image.h>
#include <fl/fl_box.h>

using namespace std;
using namespace audiere;

// uppercase c
class CatBox : public Fl_Box
{
	private:
		OutputStreamPtr sound;

	public:
		CatBox(int x, int y, int w, int h, const char* t, OutputStreamPtr s)
			:Fl_Box(x,y,w,h,t), sound(s) {}
		int handle(int e)
		{
			switch(e)
			{
				case FL_PUSH : cout << "Mouse!" << endl;
								cout << Fl::event_x() << "," <<
										Fl::event_y() << endl;
								break;
				case FL_DRAG : position(Fl::event_x(), Fl::event_y()); 
								parent() -> redraw();	// redraws parent window
								break;
				case FL_RELEASE : sound -> play();
								break;
			}
		}
};


class CatWindow : public Fl_Double_Window


{
	public:
		CatWindow(int w, int h, const char* t, OutputStreamPtr s)
			: Fl_Double_Window (w,h,t), 
			catPicture("cat.jpg"), catBox(100,100,100,100, "I'm hungry", s)
			{
				catBox.image(catPicture);
				
			}
	private:
	CatBox catBox;
	Fl_JPEG_Image catPicture;
	
	
};


int main()
{
	AudioDevicePtr device(OpenDevice());
	if (!device)
	{
		cout << "Open device failed" << endl;
			
	}

	// the third parameter is true if streaming the file
	OutputStreamPtr sound(OpenSound(device, "meow.wav", false));
	if (!sound) 
	{
		cout << "Open sound file failed" << endl;
	}
	
	//	  sound -> setRepeat (true);		// sound loop
	//	  sound -> setVolume (0.5);	  	  // 50% volume
	//	  sound -> play();			// initial meow

	CatWindow cat (400,400, "The Cat's Meow", sound);
	cat.show();
	Fl::run();

	//	  system("pause"); 		// no longer needed

}





