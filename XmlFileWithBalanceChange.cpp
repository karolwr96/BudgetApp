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

    xmlIncomes.AddElem("Income");
    xmlIncomes.IntoElem();
    xmlIncomes.AddElem("UserId", newIncome.getUserId());
    xmlIncomes.AddElem("IncomeId", 2);
    xmlIncomes.AddElem("Date", newIncome.getDate());
    xmlIncomes.AddElem("Item", newIncome.getItem());
    xmlIncomes.AddElem("Amount", newIncome.getAmount());

    xmlIncomes.Save("incomes.xml");
    return;
}

vector <Income> XmlFileWithBalanceChange::loadIncomesFromXmlFile(int idLoggedInUser) {
    Income loadedIncome;
    vector <Income> incomesFromFile;

    xmlIncomes.ResetPos();
    xmlIncomes.FindElem();
    xmlIncomes.IntoElem();

    while ( xmlIncomes.FindElem("Income") ) {
        xmlIncomes.FindChildElem("UserId");
        if ( xmlIncomes.GetChildData() == to_string(idLoggedInUser)) {
            loadedIncome.Income::setUserId(stoi(xmlIncomes.GetChildData()));

            xmlIncomes.FindChildElem("IncomeId");
            loadedIncome.setIncomeId(stoi(xmlIncomes.GetChildData()));

            xmlIncomes.FindChildElem("Date");
            loadedIncome.setDate(xmlIncomes.GetChildData());

            xmlIncomes.FindChildElem("Item");
            loadedIncome.setItem(xmlIncomes.GetChildData());

            xmlIncomes.FindChildElem("Amount");
            loadedIncome.setAmount(stof(xmlIncomes.GetChildData()));

            incomesFromFile.push_back(loadedIncome);
        }
    }
    return incomesFromFile;
}

