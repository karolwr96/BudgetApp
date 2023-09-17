#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#include "ChangeOfBallance.h"
#include "Income.h"
#include "Expense.h"
#include "DateFunctions.h"
#include "AuxiliaryFunctions.h"
#include "UserManager.h"

using namespace std;

class BudgetManager {
    const int ID_LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    double roundingNumber(string numberToRound);
    double inputNumber();

public:
public :
    BudgetManager(int idLoggedInUser) : ID_LOGGED_IN_USER(idLoggedInUser) {
    };
    void addIncome();
    void showAllIncome();
};

#endif
