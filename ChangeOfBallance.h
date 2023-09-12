#ifndef CHANGEOFBALLANCE_H
#define CHANGEOFBALLANCE_H

#include <iostream>

using namespace std;

class ChangeOfBallance {

protected:
    int userId;
    string date;
    string item;
    float amount;

public:
    void setUserId(int id);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmountmount);

    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
};

#endif
