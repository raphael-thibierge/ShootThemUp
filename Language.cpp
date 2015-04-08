//
//  Language.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 08/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//


#include "Language.h"

using namespace std;

Language::Language(string language){
    if (language == "English"){
        
    }
    else if (language == "French"){
        loadFrench();
    }
}


