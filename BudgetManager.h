#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "DateFunctions.h"

using namespace std;

class BudgetManager {
vector <Income> incomes;
vector <Expense> expenses;

public:
    void addIncome();
};

#endif
