#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "ChangeOfBallance.h"

using namespace std;

class Expense : public ChangeOfBallance {
    int expenseId;
public:
    void setExpenseId(int id);
    int getExpenseId();
};

#endif
