#include "XmlFileWithUsers.h"

void XmlFileWithUsers::loadFileToProgramm() {
    bool fileExists = xmlUsers.Load("users.xml");

    if (!fileExists) {
        xmlUsers.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlUsers.AddElem("Users");
        xmlUsers.Save("users.xml");
    }
};

void XmlFileWithUsers::addUserToFile(User newUser) {
    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    xmlUsers.IntoElem();

    xmlUsers.AddElem("User");
    xmlUsers.IntoElem();
    xmlUsers.AddElem("UserId", newUser.getId());
    xmlUsers.AddElem("Login", newUser.getLogin());
    xmlUsers.AddElem("Password", newUser.getPassword());
    xmlUsers.AddElem("Name", newUser.getName());
    xmlUsers.AddElem("Surname", newUser.getSurname());

    xmlUsers.Save("users.xml");
    return;
}

vector <User> XmlFileWithUsers::loadUsersFromXmlFile() {
    User loadedUser;
    vector <User> usersFromFile;

    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    xmlUsers.IntoElem();

    while ( xmlUsers.FindElem("User") ) {
        xmlUsers.FindChildElem("UserId");
        loadedUser.setId(stoi(xmlUsers.GetChildData()));

        xmlUsers.FindChildElem("Login");
        loadedUser.setLogin(xmlUsers.GetChildData());

        xmlUsers.FindChildElem("Password");
        loadedUser.setPassword(xmlUsers.GetChildData());

        xmlUsers.FindChildElem("Name");
        loadedUser.setName(xmlUsers.GetChildData());

        xmlUsers.FindChildElem("Surname");
        loadedUser.setSurname(xmlUsers.GetChildData());

        usersFromFile.push_back(loadedUser);
    }
    return usersFromFile;
}

void XmlFileWithUsers::changePasswordInFile(string newPassword, string userLogin) {
    xmlUsers.ResetPos();
    xmlUsers.FindElem();
    xmlUsers.IntoElem();
    while ( xmlUsers.FindElem("User") ) {
        xmlUsers.FindChildElem("Login");
        if ( xmlUsers.GetChildData() == userLogin ) {
            xmlUsers.FindChildElem("Password");
            xmlUsers.IntoElem();
            xmlUsers.SetData(newPassword);
            break;
        }
    }
    xmlUsers.Save("users.xml");
}
