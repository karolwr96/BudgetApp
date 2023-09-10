#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>

#include "AuxiliaryFunctions.h"

using namespace std;

class Menu {
public:
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void closeTheProgram();
};

#endif
