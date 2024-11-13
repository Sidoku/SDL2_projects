#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

//Texture wrapper class
class Ltexture
{
    public:
        //Initializes variables
        Ltexture();

        ~Ltexture();

        //Loads image at specified path
        bool loadFromFile( std::string path, SDL_Renderer* gRenderer );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};