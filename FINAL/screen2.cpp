#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <Fl/Fl_Box.H>
#include <FL/FL_JPEG_Image.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
#include <FL/FL_PNG_Image.H>
#include <FL/fl_draw.H>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#include <audiere.h>
using namespace audiere;
/* ver 1.0 */
const int dimxsize = 800;
const int dimysize = 600;
const double SPEED = 0.04;





struct Pictures
{
	Fl_Box* background_box;
	Fl_JPEG_Image* background_pic;
};




struct Widgets
{
	string bgsoundarr[4];
	string objsoundarr[15];

	
	
	AudioDevicePtr audiereDevice;
	  

	int qty;
	Fl_Box* mypicturebox[99];
	Fl_PNG_Image* myimage[20];
	bool right[99];
	bool down[99];
	double speedY [99];
	double speedX [99];
	double imgxsize;
	double imgysize;
	int selection;
	void SpeedChange(int speedY_max, int speedY_min, int speedX_max, int speedX_min)
	{
		for (int i = 0; i < qty; i++)
		{
			speedY[i] = (rand() % speedY_max + speedY_min);
			speedX[i] = (rand() % speedX_max + speedX_min);
			mypicturebox[i]->position ( (rand() % 900) , (rand() % 700 + 100 ) );
		}
	}
};

/*
void play_sound(void* w)
	{

	Widgets* wp = static_cast<Widgets*>(w);

	OutputStreamPtr sounds(OpenSound(wp->device, wp->bgsound.c_str() , false));
		if (!sounds)
		{
			cout << "Open sound file failed" << endl;// failure
		}

	//sounds->play("Sounds\\Backgrounds\\Ocean.wav");
	}

*/


void create_sound_bank (void* s)
{
	Widgets* bgsound = static_cast<Widgets*>(s);
	bgsound-> bgsoundarr[0] = "Sounds\\Backgrounds\\Highway.wav";
	bgsound-> bgsoundarr[1] = "Sounds\\Backgrounds\\Ocean.wav";
	bgsound-> bgsoundarr[2] = "Sounds\\Backgrounds\\Park.wav";
	bgsound-> bgsoundarr[3] = "Sounds\\Backgrounds\\Sky.wav";
}
/* =========================================== */
/* Wall detection */
void up_down(Widgets* wp, int i)
{
	if (wp->down[i])
	{
		if (wp->mypicturebox[i]->y() > dimysize - 100 ) // "IF it hits the bottom" ... dimysize - size ... "- size" compensates for the 100 x 100 image size
		{
			wp->down[i] = false;
		}
		else // GO DOWN
		{
			wp->mypicturebox[i]->position((wp->mypicturebox[i]->x() ),
			                              (wp->mypicturebox[i]->y() + wp->speedY[i]));
		}
	}
	else if (!wp->down[i])
	{
		if (wp->mypicturebox[i]->y() < 100 ) // "IF it hits the top"
		{
			wp->down[i] = true;
		}
		else // GO UP
		{
			wp->mypicturebox[i]->position((wp->mypicturebox[i]->x() ),
			                              (wp->mypicturebox[i]->y() - wp->speedY[i]));
			;
		}
	}
}
void right_left(Widgets* wp, int i)
{
	if (wp->right[i])
	{
		if (wp->mypicturebox[i]->x() > dimxsize - 100 ) // "IF it hits the right side" ... dimxsize - size ... "- size" compensates for the 100 x 100 image size
		{
			wp->right[i] = false;
		}
		else // GO RIGHT
		{
			wp->mypicturebox[i]->position((wp->mypicturebox[i]->x() + wp->speedX[i]),
			                              (wp->mypicturebox[i]->y() ));
		}
	}
	else if (!wp->right[i])
	{
		if (wp->mypicturebox[i]->x() < 50 ) // "IF it hits the left side" ...
		{
			wp->right[i] = true;
		}
		else //GO LEFT
		{
			wp->mypicturebox[i]->position((wp->mypicturebox[i]->x() - wp->speedX[i]),
			                              (wp->mypicturebox[i]->y() ));
		}
	}
}
/* =================================================*/
/* Widgets callback */
void initialize_objects(void* w) // Randomly assigns values to indexes of the arrays. Prepares to pass to callback.
{
	Widgets* widgets = static_cast<Widgets*>(w);
	widgets->myimage[0] = new Fl_PNG_Image("PNG\\plane.png"); // Reads the file you have to put in	  ... the same place as the code
	//widgets->myimage[1] = new Fl_PNG_Image("PNG\\.png");
	widgets->myimage[2] = new Fl_PNG_Image("PNG\\balloons.png");
	widgets->myimage[3] = new Fl_PNG_Image("PNG\\bicycle.png");
	widgets->myimage[4] = new Fl_PNG_Image("PNG\\bird.png");
	widgets->myimage[5] = new Fl_PNG_Image("PNG\\car.png");
	widgets->myimage[6] = new Fl_PNG_Image("PNG\\diver.png");
	widgets->myimage[7] = new Fl_PNG_Image("PNG\\dog.png");
	widgets->myimage[8] = new Fl_PNG_Image("PNG\\fish.png");
	widgets->myimage[9] = new Fl_PNG_Image("PNG\\helicopter.png");
	widgets->myimage[10] = new Fl_PNG_Image("PNG\\person.png");
	widgets->myimage[11] = new Fl_PNG_Image("PNG\\rocketship.png");
	widgets->myimage[12] = new Fl_PNG_Image("PNG\\spaceship.png");
	widgets->myimage[13] = new Fl_PNG_Image("PNG\\UFO.png");
	widgets->myimage[14] = new Fl_PNG_Image("PNG\\cat.png");
	for (int i = 0; i < widgets->qty; i++)
	{
		widgets->mypicturebox[i] = new Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize); // Make it the right size, empty ... where is image within the box? It is centered in the box
		widgets->right[i] = (rand() % 2 + 0); // randomize between 0 and 1 (true and false)
		widgets->down[i] = (rand() % 2 + 0);
		widgets->speedY[i] = (rand() % 10 + 1);
		widgets->speedX[i] = (rand() % 10 + 1);
	}
}
void callback(void* w)
{
	Widgets* wp = static_cast<Widgets*>(w);
	for (int i = 0; i < wp->qty; i++)
	{
		wp->imgysize;
		wp->imgxsize;
		wp->mypicturebox[i]->image(wp->myimage[wp->selection]); // Display or change the image
		right_left(wp, i);
		up_down(wp, i);
		wp->mypicturebox[i]->parent()->redraw();
	}
	Fl::repeat_timeout(SPEED, callback, w);
}



class PicBox : public Fl_Box
{
public:
	PicBox (int x, int y, int w, int h, const char* t) :
			Fl_Box ( x, y, w, h, t), 
			
			widgets(widgets)
			  	  {}
	
	int handle (int e)
	
	{
		
		switch (e)
		{
		case FL_PUSH :
			cout << "redrawing screen" << endl;
			parent() -> redraw();
			break;
	
		}
	}
	
private:
	Widgets* widgets;
	
	
};



class PicWindow : public Fl_Double_Window
{
public:
	static void background_choice(Fl_Widget* w, void* );
	static void thingy_choice(Fl_Widget* w, void*);
	PicWindow (int w, int h, const char* t, Widgets* widgets, OutputStreamPtr bgs, OutputStreamPtr objs) :
			Fl_Double_Window (w, h, t),
			backimage("resource/bunny.jpg"), //*** REMINDER: INSERT WELCOME SCREEN ***
			picBox(0, 50, dimxsize, dimysize, "Welcome!"),
			background(100, 10, 100, 25, "Background"),
			thingy(300, 10, 100, 25, "Objects"),
			widgets(widgets),
			BGsound(bgs),
			OBJsound(objs)
			

	{
		
		thingy.callback(thingy_choice, this);
		thingy.add("Airplane");
		//thingy.add("Alien");
		thingy.add("Balloons");
		thingy.add("Bicycle");
		thingy.add("Bird");
		thingy.add("Car");
		thingy.add("Cat");
		thingy.add("Diver");
		thingy.add("Dog");
		thingy.add("Fish");
		thingy.add("Helicopter");
		thingy.add("People");
		thingy.add("Rocketship");
		thingy.add("Satelite");
		thingy.add("UFO");
		picBox.image(backimage);
		/* Background Selector */
		background.callback(background_choice, this);
		background.add("Ocean");
		background.add("Park");
		background.add("Road");
		background.add("Sky");
		background.add("Space");
	}
private:


	
	Widgets* widgets;
	Fl_Input_Choice background;
	Fl_Input_Choice thingy;
	PicBox picBox;
	Fl_JPEG_Image backimage;
	OutputStreamPtr BGsound;
	OutputStreamPtr OBJsound;

};




/* Background selector */
void PicWindow::background_choice(Fl_Widget* w, void* data)
{

	
	PicWindow* pw = static_cast<PicWindow*>(data);
	if ( string(pw->background.value()) == "Ocean" )
	{
		
		pw->picBox.image(new Fl_JPEG_Image ("images_CSproject\\ocean.jpg"));
		pw->BGsound->stop();
		pw->BGsound = OpenSound(pw->widgets->audiereDevice, "Sounds\\Backgrounds\\Ocean.wav");
		pw->BGsound->setRepeat(true);
		pw->BGsound->setVolume(0.2);
		pw->BGsound->play();
		
	}
	else if ( string(pw->background.value()) == "Park" )
	{
		pw->picBox.image(new Fl_JPEG_Image ("images_CSproject\\park.jpg"));
		pw->BGsound->stop();
		pw->BGsound = OpenSound(pw->widgets->audiereDevice, "Sounds\\Backgrounds\\Park.wav");
		pw->BGsound->setVolume(0.7);
		pw->BGsound->setRepeat(true);
		
		pw->BGsound->play();
	}
	else if ( string(pw->background.value()) == "Road" )
	{
		pw->picBox.image(new Fl_JPEG_Image ("images_CSproject\\road.jpg"));
		pw->BGsound->stop();
		pw->BGsound = OpenSound(pw->widgets->audiereDevice, "Sounds\\Backgrounds\\Highway.wav");
		pw->BGsound->setRepeat(true);
		pw->BGsound->setVolume(0.2);
		pw->BGsound->play();
		;
	}
	else if ( string(pw->background.value()) == "Sky" )
	{
		pw->picBox.image(new Fl_JPEG_Image ("images_CSproject\\sky.jpg"));
		pw->BGsound->stop();
		pw->BGsound = OpenSound(pw->widgets->audiereDevice, "Sounds\\Backgrounds\\Sky.wav");
		pw->BGsound->setRepeat(true);
		pw->BGsound->setVolume(2.0);
		pw->BGsound->play();
		
	}
	else if ( string(pw->background.value()) == "Space" )
	{
		pw->picBox.image(new Fl_JPEG_Image ("images_CSproject\\space.jpg"));
		
	}
	pw->redraw();

}
/* Thingy selector */
void PicWindow::thingy_choice(Fl_Widget* w, void* data)
{
	PicWindow* pw = static_cast<PicWindow*>(data);
	if ( string(pw->thingy.value()) == "Airplane" )
	{
		pw->widgets->selection = 0;
		pw->widgets->SpeedChange(2, 0, 10, 4); // SpeedChange(speedY_max, speedY_min, speedX_max, speedX_min)
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) , rand() % 100 + 200);  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
		
	}
	/*
	else if ( string(pw->thingy.value()) == "Alien" )
	{
		pw->widgets->selection = 1;
	}
	*/
	else if ( string(pw->thingy.value()) == "Balloons" )
	{
		pw->widgets->selection = 2;
		pw->widgets->SpeedChange(6, 3, 2, 0); // SpeedChange(speedY_max, speedY_min, speedX_max, speedX_min, x pixels for image, y pixels for image)
	}
	else if ( string(pw->thingy.value()) == "Bicycle" )
	{
		pw->widgets->selection = 3;
		pw->widgets->SpeedChange(1, 0, 5, 1);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) ,  (rand() % 30 + 350)  );  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
	}
	else if ( string(pw->thingy.value()) == "Bird" )
	{
		pw->widgets->selection = 4;
		pw->widgets->SpeedChange(10, 3, 10, 3);
	}
	else if ( string(pw->thingy.value()) == "Car" )
	{
		pw->widgets->selection = 5;
		pw->widgets->SpeedChange(1, 0, 10, 5);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) ,  (rand() % 100 + 350)  );
		}
	}
	else if ( string(pw->thingy.value()) == "Diver" )
	{
		pw->widgets->selection = 6;
		pw->widgets->SpeedChange(2, 1, 2, 1);
	}
	else if ( string(pw->thingy.value()) == "Dog" )
	{
		pw->widgets->selection = 7;
		pw->widgets->SpeedChange(5, 0, 10, 5);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) , (rand() % 100 + 300) );  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
	}
	else if ( string(pw->thingy.value()) == "Fish" )
	{
		pw->widgets->selection = 8;
		pw->widgets->SpeedChange(1, 1, 3, 1);
	}
	else if ( string(pw->thingy.value()) == "Helicopter" )
	{
		pw->widgets->selection = 9;
		pw->widgets->SpeedChange(2, 0, 10, 4);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) , (rand() % 100 + 150) );  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
	}
	else if ( string(pw->thingy.value()) == "People" )
	{
		pw->widgets->selection = 10;
		pw->widgets->SpeedChange(1, 0, 4, 1);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) ,  (rand() % 30 + 300)  );  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
	}
	else if ( string(pw->thingy.value()) == "Rocketship" )
	{
		pw->widgets->selection = 11;
		pw->widgets->SpeedChange(10, 3, 2, 0);
		for (int i = 0; i < pw->widgets->qty; i++)
		{
			pw->widgets->mypicturebox[i]->position ( (rand() % 800) ,  (rand() % 300 + 700)  );  //Fl_Box((rand() % 800), (rand() % 600) ,  widgets->imgxsize, widgets->imgysize);
		}
	}
	else if ( string(pw->thingy.value()) == "Satelite" )
	{
		pw->widgets->selection = 12;
		pw->widgets->SpeedChange(2, 1, 2, 1);
	}
	else if ( string(pw->thingy.value()) == "UFO" )
	{
		pw->widgets->selection = 13;
		pw->widgets->SpeedChange(10, 7, 10, 7);
	}
	else if ( string(pw->thingy.value()) == "Cat" )
	{
		pw->widgets->selection = 14;
		pw->widgets->SpeedChange(1, 0, 5, 3);
	}
	pw->redraw();
}
/* Exits program*/
void exitProgram (Fl_Widget*, void*)
{
	if (!fl_choice ("Exit program?", "Nope", "Ok", 0L)) return;
	cout << "Exiting program" << endl;
	exit(0);
}


int main()
{

	Widgets widgets;
	create_sound_bank(&widgets);
	
	widgets.selection = 16; /* Initial object selection */
	widgets.audiereDevice = OpenDevice();
	
	srand(time(0));
	

		OutputStreamPtr BGsound(OpenSound(widgets.audiereDevice, widgets.bgsoundarr[3].c_str() , false));
		if (!BGsound)
		{
			cout << "Open sound file failed" << endl;// failure
		}
		OutputStreamPtr OBJsound(OpenSound(widgets.audiereDevice, widgets.bgsoundarr[3].c_str() , false));
		if (!OBJsound)
		{
			cout << "Open sound file failed" << endl;// failure
		}
		//BGsound = OpenSound(widgets.audiereDevice, "Sounds\\Objects\\Dog.wav", true);
			//BGsound->play();
	

	
	//play_sound(&widgets);
	PicWindow mainmenu (dimxsize, dimysize, "Main Menu", &widgets, BGsound, OBJsound);
	/* Loads the selected options into the window */
	/* Exit program button */
	Fl_Button* quit = new Fl_Button (650, 10, 125, 30, "Exit");
	quit -> callback ((Fl_Callback*)exitProgram);
	widgets.qty = 5;
	widgets.imgxsize = 0 ;
	widgets.imgysize = 0 ;
	initialize_objects(&widgets);
	callback(&widgets);
	mainmenu.show();
	Fl::run();
}

