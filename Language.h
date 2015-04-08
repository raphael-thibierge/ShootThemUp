//
//  Language.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 08/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>


class Language{
    
public:
    
    Language(std::string language);
    ~Language();
    
    std::string getMessage(std::string message);
    
    void loadFrench();
    
    void loadEnglish();
    
    
};

#endif
