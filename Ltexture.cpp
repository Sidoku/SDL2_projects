#include "Ltexture.h"
#include <SDL2/SDL_image.h>

Ltexture::Ltexture()
{
    //Initialize
	mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Ltexture::~Ltexture()
{
	//Deallocate
	free();
}

bool Ltexture::loadFromFile( std::string path, SDL_Renderer* gRenderer )
{
    //Remove preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if ( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Clear old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void Ltexture::free()
{
    //Free texture if it exists
    if ( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Ltexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Ltexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending mode
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Ltexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Ltexture::render( int x, int y , SDL_Rect* clip, SDL_Renderer* gRenderer)
{
    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, NULL );
}

int Ltexture::getWidth()
{
    return mWidth;
}

int Ltexture::getHeight()
{
    return mHeight;
}