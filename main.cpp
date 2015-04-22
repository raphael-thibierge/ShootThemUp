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
//
int main(int argc, const char * argv[]) {

    GameModel model;

    ViewsController controller;
    controller.init(&model);

    while (controller.treatEvent()) {
        model.nextStep();
        controller.showView();
    }

    return 0;
}
