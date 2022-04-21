#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window )
    {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, 0 );

    SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );

    SDL_RenderClear( renderer );

    SDL_RenderPresent( renderer );

    SDL_Event event;

    while ( true )
    {
        if ( SDL_PollEvent( &event ) )
        {
            if ( SDL_QUIT == event.type )
            { break; }

            if ( SDL_MOUSEMOTION == event.type )
            {
                int x, y;
                SDL_GetMouseState( &x, &y );

                std::cout << x << " : " << y << std::endl;
            }

            if ( SDL_MOUSEBUTTONDOWN == event.type )
            {
                if ( SDL_BUTTON_LEFT == event.button.button )
                { std::cout << "Left mouse button is down" << std::endl; }
                else if ( SDL_BUTTON_RIGHT == event.button.button )
                { std::cout << "Right mouse button is down" << std::endl; }
                else if ( SDL_BUTTON_MIDDLE == event.button.button )
                { std::cout << "Middle mouse button is down" << std::endl; }
            }

            if ( SDL_MOUSEBUTTONUP == event.type )
            {
                if ( SDL_BUTTON_LEFT == event.button.button )
                { std::cout << "Left mouse button is up" << std::endl; }
                else if ( SDL_BUTTON_RIGHT == event.button.button )
                { std::cout << "Right mouse button is up" << std::endl; }
                else if ( SDL_BUTTON_MIDDLE == event.button.button )
                { std::cout << "Middle mouse button is up" << std::endl; }
            }

            if ( SDL_MOUSEWHEEL == event.type )
            {
                if ( event.wheel.y > 0 ) // scroll up
                { std::cout << "Mouse wheel is scrolling up" << std::endl; }
                else if ( event.wheel.y < 0 ) // scroll down
                { std::cout << "Mouse wheel is scrolling down" << std::endl; }

                if ( event.wheel.x > 0 ) // scroll right
                { std::cout << "Mouse wheel is scrolling right" << std::endl; }
                else if ( event.wheel.x < 0 ) // scroll left
                { std::cout << "Mouse wheel is scrolling left" << std::endl; }
            }

            if ( SDL_KEYDOWN == event.type )
            {
                //std::cout << "Key is down" << std::endl;

                if ( SDLK_a == event.key.keysym.sym )
                { std::cout << "A is down - Move left" << std::endl; }
                else if ( SDLK_s == event.key.keysym.sym )
                { std::cout << "S is down - Move down" << std::endl; }
                else if ( SDLK_d == event.key.keysym.sym )
                { std::cout << "D is down - Move right" << std::endl; }
                else if ( SDLK_w == event.key.keysym.sym )
                { std::cout << "W is down - Move up" << std::endl; }
            }
            else if ( SDL_KEYUP == event.type )
            {
                //std::cout << "Key is up" << std::endl;
                if ( SDLK_a == event.key.keysym.sym )
                { std::cout << "A is up - Stop moving left" << std::endl; }
                else if ( SDLK_s == event.key.keysym.sym )
                { std::cout << "S is up - Stop moving down" << std::endl; }
                else if ( SDLK_d == event.key.keysym.sym )
                { std::cout << "D is up - Stop moving right" << std::endl; }
                else if ( SDLK_w == event.key.keysym.sym )
                { std::cout << "W is up - Stop moving up" << std::endl; }
            }
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}
