#include "ChangeOfBallance.h"

void ChangeOfBallance::setUserId(int id) {
    userId = id;
    return;
}

void ChangeOfBallance::setDate(string newDate) {
    date = newDate;
    return;
}

void ChangeOfBallance::setItem(string newItem) {
    item = newItem;
    return;
}

void ChangeOfBallance::setAmount(float newAmount) {
    amount = newAmount;
    return;
}

int ChangeOfBallance::getUserId() {
    return userId;
}

string ChangeOfBallance::getDate() {
    return date;
}

string ChangeOfBallance::getItem() {
    return item;
}

float ChangeOfBallance::getAmount() {
    return amount;
}
