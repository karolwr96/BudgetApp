#include "UserManager.h"

int UserManager::getIdLoggedInUser() {
    return idLoggedInUser;
}

User UserManager::enterTheDataOfNewUser() {
    User newUser;
    string login, password, name, surname;

    newUser.setId(getIdForNewUser());

    cout << endl << "Enter login: ";
    login = AuxiliaryFunctions::loadLine();

    if (!doesLoginExists(login)) {
        newUser.setLogin(login);
    } else {
        do {
            cout << endl << "The provided login already exists, please try again." << endl;
            cout << "Enter login: ";
            login = AuxiliaryFunctions::loadLine();
        }  while (doesLoginExists(login));
    }
    newUser.setLogin(login);

    cout << "Enter password: ";
    password = AuxiliaryFunctions::loadLine();
    newUser.setPassword(password);

    cout << "Enter name: ";
    name = AuxiliaryFunctions::loadLine();
    newUser.setName(name);

    cout << "Enter surname: ";
    surname = AuxiliaryFunctions::loadLine();
    newUser.setSurname(surname);
    return newUser;
}

void UserManager::userRegistration() {
    User newUser = enterTheDataOfNewUser();

    users.push_back(newUser);
    xmlUsers.addUserToFile(newUser);

    cout << endl << "Account has been submited." << endl << endl;
    system("pause");
    return;
}

void UserManager::showAllUsers() {
    for (unsigned int i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << endl;
    }
    system("pause");
    return;
}

int UserManager::getIdForNewUser() {
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExists(string login) {
    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login)
            return true;
    }
    return false;
}

void UserManager::loginUser() {
    int userId;
    string login, password, truePassword;
    bool isLoginTrue = false;

    cout << endl << "Enter login: ";
    login = AuxiliaryFunctions::loadLine();

    cout << "Enter password: ";
    password = AuxiliaryFunctions::loadLine();

    for (unsigned int i = 0; i < users.size(); i++) {
        if (login == users[i].getLogin()) {
            isLoginTrue = true;
            truePassword = users[i].getPassword();
            userId = users[i].getId();
            break;
        }
    }

    if (isLoginTrue && password == truePassword) {
        cout << endl << "Login successful." << endl << endl;
        idLoggedInUser = userId;
        system("pause");
        return;
    } else {
        cout << endl << "Wrong login or password" << endl << endl;
        system("pause");
        return;
    }
}

void UserManager::logOutUser() {
    idLoggedInUser = 0;
    return;
}

void UserManager::changePasswordLoggedInUser() {
    string userLogin;
    cout << endl << "Enter new password: ";
    string newPassword = AuxiliaryFunctions::loadLine();

    cout << "Enter your new password again: ";
    string newPasswordAgain = AuxiliaryFunctions::loadLine();

    if (newPasswordAgain == newPassword) {
        for (unsigned int i = 0; i < users.size(); i++) {
            if (idLoggedInUser == users[i].getId()) {
                users[i].setPassword(newPassword);
                userLogin = users[i].getLogin();
                break;
            }
        }
        xmlUsers.changePasswordInFile(newPassword, userLogin);
        cout << "Password has been changed." << endl << endl;
        system("pause");
        return;
    }
    else {
        cout << "Passwords are not the same." << endl << endl;
        system("pause");
        return;
    }


}




