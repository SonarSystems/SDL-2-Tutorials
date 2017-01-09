#include <iostream>

#include <SDL2/SDL.h>

int main( int argc, char *argv[] )
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
    }
    
    return EXIT_SUCCESS;
}
