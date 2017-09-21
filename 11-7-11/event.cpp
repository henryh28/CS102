#include <fl/fl.h>
#include <fl/fl_window.h>
#include <iostream>

using namespace std;

class EventWindow : public Fl_Window
{
public:
	EventWindow(int, int, const char*);			// constructor
	int handle(int);							// callback function
private:
	int handle_mouse(int, int, int, int);
	int handle_keyboard(int, int);	  
};

int EventWindow::handle_keyboard(int e, int k)
{
	cout << "Keyboard handler: " << e << " key: " << k << endl;
	switch (k)
	{
		case FL_Up:  cout << "up key pressed" << endl;
						break;
		default : cout << "unhandled key" << endl;
	}
}

int EventWindow::handle_mouse(int e, int b, int x, int y)
{
	cout << "in mouse handler" << e << ":" << b << "(" << x << "," << y << ")" << endl;
}

EventWindow::EventWindow(int w,int h, const char* t)		// callback function
	: Fl_Window(w,h,t)
{
}

int EventWindow::handle(int e)	   	   	   	   	   	   	   	   // callback function
{
	cout << e << endl;
	int return_value = 0;

	switch(e)
	{
		case FL_DRAG : 
		case FL_RELEASE : 
		case FL_PUSH: return_value = handle_mouse(e, Fl::event_button(), Fl::event_x(),Fl::event_y());
				break;
		case FL_KEYBOARD: return_value = handle_keyboard(e, Fl::event_key());
		default :return_value = Fl_Window::handle(e);
	}
	return return_value;
}


int main()
{
	Fl_Window w(400,300,"Fl_Window");
	EventWindow ew(400,300,"Event Window");
	
	w.show();
	ew.show();
	w.hide();		// hide the original window
	Fl::run();
}





