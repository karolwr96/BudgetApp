#include "XmlFileWithBalanceChange.h"

void XmlFileWithBalanceChange::loadFilesToProgramm() {
    bool fileWithIncomesExists = xmlIncomes.Load("incomes.xml");
    bool fileWithExpensesExists = xmlExpenses.Load("expenses.xml");

    if (!fileWithIncomesExists) {
        xmlIncomes.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlIncomes.AddElem("Incomes");
        xmlIncomes.Save("incomes.xml");
    }

    if (!fileWithExpensesExists) {
        xmlExpenses.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlExpenses.AddElem("Expenses");
        xmlExpenses.Save("expenses.xml");
    }
    return;
}

void XmlFileWithBalanceChange::addIncomeToFile(Income newIncome) {
    xmlIncomes.ResetPos();
    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();

    xmlIncomes.AddElem("UserId", 2);
    xmlIncomes.IntoElem();
    xmlIncomes.AddElem("IncomeId", 2);
    xmlIncomes.AddElem("Date", newIncome.getDate());
    xmlIncomes.AddElem("Item", newIncome.getItem());
    xmlIncomes.AddElem("Amount", newIncome.getAmount());

    xmlIncomes.Save("incomes.xml");
    return;
}
/*
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
}*/
