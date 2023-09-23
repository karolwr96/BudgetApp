#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryFunctions.h"
#include "XmlFileWithUsers.h"
#include <conio.h>

using namespace std;

class UserManager {
    int idLoggedInUser;
    vector <User> users;
    XmlFileWithUsers xmlUsers;

    User enterTheDataOfNewUser();
    int getIdForNewUser();
    bool doesLoginExists(string login);
    string takePasswdFromUser();

public :
    UserManager() {
        idLoggedInUser = 0;
        users = xmlUsers.loadUsersFromXmlFile();
    }
    void userRegistration();
    void loginUser();
    int getIdLoggedInUser();
    void changePasswordLoggedInUser();
    void logOutUser();
    void showAllUsers();
};

#endif
