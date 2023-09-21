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
    xmlIncomes.AddElem("Amount", to_string(newIncome.getAmount()));

    xmlIncomes.Save("incomes.xml");
    return;
}

void XmlFileWithBalanceChange::addExpenseToFile(Expense newExpense) {
    xmlExpenses.ResetPos();
    xmlExpenses.FindElem();
    xmlExpenses.IntoElem();

    xmlExpenses.AddElem("Expense");
    xmlExpenses.IntoElem();
    xmlExpenses.AddElem("UserId", newExpense.getUserId());
    xmlExpenses.AddElem("ExpenseId", 2);
    xmlExpenses.AddElem("Date", newExpense.getDate());
    xmlExpenses.AddElem("Item", newExpense.getItem());
    xmlExpenses.AddElem("Amount", to_string(newExpense.getAmount()));

    xmlExpenses.Save("expenses.xml");
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
            loadedIncome.setDate(stoi(xmlIncomes.GetChildData()));

            xmlIncomes.FindChildElem("Item");
            loadedIncome.setItem(xmlIncomes.GetChildData());

            xmlIncomes.FindChildElem("Amount");
            loadedIncome.setAmount(stof(xmlIncomes.GetChildData()));

            incomesFromFile.push_back(loadedIncome);
        }
    }
    return incomesFromFile;
}

vector <Expense> XmlFileWithBalanceChange::loadExpensesFromXmlFile(int idLoggedInUser) {
    Expense loadedExpense;
    vector <Expense> expensesFromFile;

    xmlExpenses.ResetPos();
    xmlExpenses.FindElem();
    xmlExpenses.IntoElem();

    while ( xmlExpenses.FindElem("Expense") ) {
        xmlExpenses.FindChildElem("UserId");
        if ( xmlExpenses.GetChildData() == to_string(idLoggedInUser)) {
            loadedExpense.ChangeOfBallance::setUserId(stoi(xmlExpenses.GetChildData()));

            xmlExpenses.FindChildElem("ExpenseId");
            loadedExpense.setExpenseId(stoi(xmlExpenses.GetChildData()));

            xmlExpenses.FindChildElem("Date");
            loadedExpense.setDate(stoi(xmlExpenses.GetChildData()));

            xmlExpenses.FindChildElem("Item");
            loadedExpense.setItem(xmlExpenses.GetChildData());

            xmlExpenses.FindChildElem("Amount");
            loadedExpense.setAmount(stof(xmlExpenses.GetChildData()));

            expensesFromFile.push_back(loadedExpense);
        }
    }
    return expensesFromFile;
}
