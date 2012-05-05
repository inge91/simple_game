#ifndef TEST_H
#define TEST_H

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include "test.h"
#include "timer.h"
#include "character.h"
#include "object.h"


//The screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;

// All functions
bool collision_detection(int x1,  int y1, int w1, int h1,
                         int x2, int y2, int w2, int h2);
SDL_Surface* load_image(std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination,
                    SDL_Rect* clip  );
bool init();



#endif // TEST_H
