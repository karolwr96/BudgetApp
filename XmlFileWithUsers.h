#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "User.h"

using namespace std;

class XmlFileWithUsers {
    CMarkup xmlUsers;
    void loadFileToProgramm();

public :
    XmlFileWithUsers() {
        loadFileToProgramm();
    }
    vector <User> loadUsersFromXmlFile();
    void addUserToFile(User newUser);
    void changePasswordInFile(string newPassword, string userLogin);
};

#endif
