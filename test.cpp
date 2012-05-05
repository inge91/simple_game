//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include "timer.h"
#include "character.h"
#include "object.h"

//The screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;


//The surfaces
SDL_Surface *dot = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *object =NULL;

//The event structure
SDL_Event event;


bool collision_detection(int x1,  int y1, int w1, int h1,
                         int x2, int y2, int w2, int h2)
{
    int leftSide1 = x1;
    int rightSide1 = x1 + w1;
    int upSide1 = y1;
    int downSide1 = y1 + h1;

    int leftSide2 = x2;
    int rightSide2 = x2 + w2;
    int upSide2 = y2;
    int downSide2 = y2 + h2;

    if(downSide1 <= upSide2)
    {
        return false;
    }

    if(rightSide1 <= leftSide2)
    {
        return false;
    }

    if( upSide1 >= downSide2)
    {
        return false;
    }

    if(leftSide1 >= rightSide2)
    {
        return false;
    }

    return true;
}


SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    if( TTF_Init() == -1)
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Move the Dot", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the dot image
    dot = load_image( "character.bmp" );
    object = load_image( "object.bmp" );



    //If there was a problem in loading the dot
    if( dot == NULL || object == NULL)
    {
        std::cout<<"obj is empty";
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surface
    SDL_FreeSurface( dot );
    SDL_FreeSurface( object);

    //Quit SDL
    SDL_Quit();
}





//Fill the background using input image
void fill_background(SDL_Surface* background)
{
    for (int i = 0; i < SCREEN_WIDTH; i += background->w)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j += background->h)
        {
            apply_surface(i,j,background, screen);
        }
    }

}


int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //The dot that will be used
    Character myCharacter;

    //The frame rate regulator
    Timer fps;

    // The object to find
    Object myObject;

    //Load the background
    background = load_image("background.bmp");
    fill_background(background);
    myObject.show(object, screen);

    SDL_Flip(screen);

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the dot
            myCharacter.handle_input(event);

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Move the dot
        myCharacter.move(SCREEN_HEIGHT, SCREEN_WIDTH);
        if(collision_detection(myObject.get_position_x(), myObject.get_position_y()
                               , myObject.get_width(), myObject.get_height(),
                               myCharacter.get_position_x(), myCharacter.get_position_y(),
                               myCharacter.get_width(), myCharacter.get_height()) == true)
        {
            myObject.found_object(SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        //Fill the screen white
        fill_background(background);

        //Show the dot on the screen
        myCharacter.show(dot, screen);
        myObject.show(object, screen);

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}

