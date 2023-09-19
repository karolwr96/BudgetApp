#ifndef XMLFILEWITHBALANCECHANGE_H
#define XMLFILEWITHBALANCECHANGE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "Income.h"
#include "Expense.h"
#include "ChangeOfBallance.h"

using namespace std;

class XmlFileWithBalanceChange {
    CMarkup xmlIncomes;
    CMarkup xmlExpenses;
    void loadFilesToProgramm();

public :
    XmlFileWithBalanceChange() {
        loadFilesToProgramm();
    }
    void addIncomeToFile(Income newIncome);
    void addExpenseToFile(Expense newExpense);
    vector <Income> loadIncomesFromXmlFile(int idLoggedInUser);
    vector <Expense> loadExpensesFromXmlFile(int idLoggedInUser);
};

#endif
