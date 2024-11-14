/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Ltexture.cpp"

#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 426;

//Walking animation constant
const int WALKING_ANIMATION_FRAMES = 4;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window being rendered to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
Ltexture gSpriteSheetTexture;
Ltexture gBackgroundTexture;
Ltexture gModulatedTexture;

//Current displayed texture
SDL_Texture* gTexture = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Load individual image
SDL_Surface* loadSurface( std::string path );

//Images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Scene sprites
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO < 0 ) )
	{
		printf("SDL could not be intialized! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL)
			{
				printf( "Renderer could not be created, SDL_Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !(IMG_Init( imgFlags ) & imgFlags ) ) // bitwise & only checks for PNG loading bit
				{
					printf( "SDL_image could not be initialized! SDL_Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	newTexture = IMG_LoadTexture( gRenderer, path.c_str() );
	if ( newTexture == NULL)
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

	return newTexture;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load front alpha texture
	if( !gModulatedTexture.loadFromFile( "Images/colors.png", gRenderer ) )
	{
		printf( "Failed to load front texture!\n" );
		success = false;
	}
	else
	{
		//Set standard alpha blending
		gModulatedTexture.setBlendMode( SDL_BLENDMODE_BLEND );
	}

	//Load background texture
	if( !gBackgroundTexture.loadFromFile( "Images/background.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

	if ( !gSpriteSheetTexture.loadFromFile( "Images/foo.png", gRenderer ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[ 0 ].x = 0;
		gSpriteClips[ 0 ].y = 0;
        gSpriteClips[ 0 ].w = 64;
        gSpriteClips[ 0 ].h = 205;

        gSpriteClips[ 1 ].x = 64;
        gSpriteClips[ 1 ].y = 0;
        gSpriteClips[ 1 ].w = 64;
        gSpriteClips[ 1 ].h = 205;
        
        gSpriteClips[ 2 ].x = 128;
        gSpriteClips[ 2 ].y = 0;
        gSpriteClips[ 2 ].w = 64;
        gSpriteClips[ 2 ].h = 205;

        gSpriteClips[ 3 ].x = 192;
        gSpriteClips[ 3 ].y = 0;
        gSpriteClips[ 3 ].w = 64;
        gSpriteClips[ 3 ].h = 205;
	}
	
	
	return success;
}

SDL_Surface* loadSurface( std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface =  NULL;

	//Load image at specified path
	//SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() ); //Load BMP image format
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0);
		if ( optimizedSurface == NULL)
		{
			printf( "Unable to optimize iamge %s! SDL Error: %s\n",path.c_str(), SDL_GetError() );
		}
		
		//Deallocate old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return optimizedSurface;
}

void close()
{
	//Free loaded image
	gSpriteSheetTexture.free();
	gBackgroundTexture.free();
	gModulatedTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gRenderer = NULL;
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf("Failed to initialize\n");
	}
	else
	{
		//Load media
		if( !loadMedia())
		{
			printf( "Failed to load media\n");
		}
		else
		{
			//Event handler
			SDL_Event e;

			//Modulation components
			Uint8 r = 255;
			Uint8 g = 255;
			Uint8 b = 255;
			Uint8 a = 255;

			//Current animation frame
			int frame = 0;

			//Main loop flag
			bool quit = false;

			while( !quit )
			{
				//Handle events on queue
				while ( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if ( e.type == SDL_QUIT)
					{
						quit = true;
					}
					//On keypress change the rgb values
					else if ( e.type == SDL_KEYDOWN )
					{
						switch ( e.key.keysym.sym )
						{
						//Increase red
						case SDLK_q:
							r += 32;
							break;
						
						//Increase green
						case SDLK_w:
							g += 32;
							break;
						
						//Increase blue
						case SDLK_e:
							b += 32;
							break;

						//Decrease red
                        case SDLK_a:
                            r -= 32;
                            break;
                            
                        //Decrease green
                        case SDLK_s:
                            g -= 32;
                            break;
                            
                        //Decrease blue
                        case SDLK_d:
                            b -= 32;
                            break;

						//Increase alpha on 1
						case SDLK_1:
							//Cap if over 255
							if ( a + 32 > 255 )
							{
								a = 255;
							}
							//Increment otherwise
							else
							{
								a += 32;
							}
							break;

						//Decrease alpha on 0
						case SDLK_0:
							//Cap if below 0
							if ( a - 32 < 0)
							{
								a = 0;
							}
							//Decrement otherwise
							else
							{
								a -= 32;
							}
							break;

						default:
							break;
						}
					}
				}

				//Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

				//Render current frame
				SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ]; //frame updates only every 4 frames
				gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip, gRenderer );

				// //Render background
				// gBackgroundTexture.render( 0, 0 , NULL , gRenderer);

				// //Render front blended
				// gModulatedTexture.setColor( r, g, b );
				// gModulatedTexture.setAlpha( a );
				// gModulatedTexture.render( 0, 0, NULL, gRenderer );

                //Update screen
                SDL_RenderPresent( gRenderer );

				//Go to next frame
				++frame;

				//Cycle animation
				if ( frame / 4 >= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}	
			}
		}
	}

	//Free resources
	close();

	return 0;
}
