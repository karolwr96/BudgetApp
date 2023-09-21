#ifndef CHANGEOFBALLANCE_H
#define CHANGEOFBALLANCE_H

#include <iostream>

using namespace std;

class ChangeOfBallance {

protected:
    int userId;
    int date;
    string item;
    float amount;

public:
    void setUserId(int id);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
