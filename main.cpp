
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "ViewsController.h"


int main(int, char const**)
{
    GameModel model;
    
    sf::RenderWindow window (sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Shoot Them Up");
    window.setFramerateLimit(60);
    //window.useVerticalSync(true);
    
    ViewsController controller(&window);
    if (!controller.init(&model))
        return EXIT_FAILURE;
    
    
    while (window.isOpen())
    {
        while (controller.treatEvent()) {
            
            model.nextStep();
            controller.showView();
            
        }
        window.close();
    }

    return EXIT_SUCCESS;
}
