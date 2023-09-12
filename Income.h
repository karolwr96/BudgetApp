#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "ChangeOfBallance.h"

using namespace std;

class Income : public ChangeOfBallance {
    int incomeId;

public:
   void setIncomeId(int id);
   int getIncomeId();
};

#endif
