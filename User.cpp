#include "User.h"

void User::setId(int newId) {
    if (newId >= 0)
        userId = newId;
    return;
}

void User::setLogin(string newLogin) {
    login = newLogin;
    return;
}

void User::setPassword(string newPassword) {
    password = newPassword;
    return;
}

void User::setName(string newName) {
    name = newName;
    return;
}

void User::setSurname(string newSurname) {
    surname = newSurname;
    return;
}

int User::getId() {
    return userId;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}
