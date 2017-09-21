#include <FL/FL.H>
#include <FL/FL_Window.H>
#include <FL/FL_Box.H>
#include <FL/FL_JPEG_Image.H>
#include <iostream>

using namespace std;

// A visible widget that will show the image
// you can also put images on buttons etc.
// This will be the invisible image object.

const double SPEED = 0.005;
struct Widgets
{
	Fl_Box* mypicturebox;
	Fl_JPEG_Image* myimage;
	         
};

void callback(void* w)
{
	Widgets* wp = static_cast<Widgets*>(w);
	wp->mypicturebox->redraw();
	wp->mypicturebox->parent()->redraw();		// the enclosing window of box
	cout << ("(") << wp ->mypicturebox->x() << "," << wp->mypicturebox->y() << ")";

	wp->mypicturebox->position((wp->mypicturebox->x()+10)%300, 
		(wp->mypicturebox->y()+1)%300);
	Fl::repeat_timeout(SPEED, callback, w);
}

int main()
{
	Fl_Window win(400,400, "Images");
	Widgets widgets;		// contains picture and box
	widgets.myimage = new Fl_JPEG_Image("happy.jpg"); // reads the file you have put in
	   

// the same place as the code.
	widgets.mypicturebox = new Fl_Box(0,0,200,200);  // Make it the right size, empty
	widgets.mypicturebox ->image(widgets.myimage);	// Display or change the image whenever you l

	Fl::add_timeout(SPEED, callback, &widgets);
	win.show();
	Fl::run();
}



// experiement with "double window" for smoother image draw


