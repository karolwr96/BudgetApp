#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "ChangeOfBallance.h"
#include "Income.h"
#include "Expense.h"
#include "DateFunctions.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class BudgetManager {
vector <Income> incomes;
vector <Expense> expenses;

public:
    void addIncome();
    void showAllIncome();
};

#endif
