#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

#include "ChangeOfBallance.h"
#include "Income.h"
#include "Expense.h"
#include "DateFunctions.h"
#include "AuxiliaryFunctions.h"
#include "UserManager.h"
#include "XmlFileWithBalanceChange.h"

using namespace std;

class BudgetManager {
    const int ID_LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    XmlFileWithBalanceChange xmlIncomes;
    XmlFileWithBalanceChange xmlExpenses;

    double roundingNumber(string numberToRound);
    double inputNumber();

    void sortIncomeVector(vector <Income> &changeOfDataVector);
    void sortExpenseVector(vector <Expense> &changeOfDataVector);
    void showTotalBalance(double revenues, double outlay);

public:
    BudgetManager(int idLoggedInUser) : ID_LOGGED_IN_USER(idLoggedInUser) {
        incomes = xmlIncomes.loadIncomesFromXmlFile(ID_LOGGED_IN_USER);
        expenses = xmlExpenses.loadExpensesFromXmlFile(ID_LOGGED_IN_USER);
    };
    void addIncome();
    void addExpense();
    void showAllIncomes();
    void showAllExpenses();
    void showBalanceSheetForCurrentMonth();
};

#endif
