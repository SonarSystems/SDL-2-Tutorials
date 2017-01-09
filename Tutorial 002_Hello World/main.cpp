#include <iostream>

#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    
    // Check that the window was successfully created
    if ( NULL == window )
    {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }
    
    SDL_Event windowEvent;
    
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
    }
    
    SDL_DestroyWindow( window );
    SDL_Quit( );
    
    return EXIT_SUCCESS;
}
