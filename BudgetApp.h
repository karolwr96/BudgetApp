#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "Menu.h"

using namespace std;

class BudgetApp {
    UserManager userManager;
    BudgetManager *budgetManager;
    Menu menu;

    void showOptionsFromMainMenu();
public:
    BudgetApp() {
        budgetManager = NULL;
        showOptionsFromMainMenu();
    };

    ~BudgetApp() {
        delete budgetManager;
        budgetManager = NULL;
    };
};

#endif
