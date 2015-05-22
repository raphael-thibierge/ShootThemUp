//
//  main.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 19/03/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include <iostream>
#include "ViewsController.h"

using namespace std;

int main(int argc, const char * argv[]) {

    GameModel model;

    sf::RenderWindow window (sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Shoot Them Up");
    window.SetFramerateLimit(60);
    window.UseVerticalSync(true);

    ViewsController controller(&window);
    if (!controller.init(&model))
        return EXIT_FAILURE;


    while (window.IsOpened())
    {
        while (controller.treatEvent()) {

            model.nextStep();
            controller.showView();

        }
        window.Close();
    }

    return 0;
}
