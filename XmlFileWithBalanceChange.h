#ifndef XMLFILEWITHBALANCECHANGE_H
#define XMLFILEWITHBALANCECHANGE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class XmlFileWithBalanceChange {
    CMarkup xmlIncomes;
    CMarkup xmlExpenses;
    void loadFilesToProgramm();

public :
    XmlFileWithBalanceChange() {
        loadFilesToProgramm();
    }
    // vector <User> loadUsersFromXmlFile();
    void addIncomeToFile(Income newIncome);
    void addExpenseToFile(Expense newExpense);


};

#endif
