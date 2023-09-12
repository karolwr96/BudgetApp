#include "BudgetManager.h"

void::BudgetManager::addIncome() {

    Income newIncome;

    //cout << "1. Add today's expense." << endl;
    //cout << "2. Add an expense with a another date." << endl;

    cout << DateFunctions::loadCurrentDate() << endl;

    newIncome.setDate(DateFunctions::loadCurrentDate());

    cout << "Please enter the source of income: " << endl;


    newIncome.setItem(AuxiliaryFunctions::loadLine());

    cout << "Please enter the amount of income: " << endl;

    float amount;
    cin >> amount;

    newIncome.setAmount(amount);
    newIncome.setUserId(1);

    newIncome.setIncomeId (123);

    incomes.push_back(newIncome);
    return;
}

void BudgetManager::showAllIncome() {
    for (unsigned int i = 0; i < incomes.size(); i++) {
        cout << "Income id " << incomes[i].getIncomeId() << endl;
        cout << "User id "<< incomes[i].getUserId() << endl;
        cout << "Date "<< incomes[i].getDate() << endl;
        cout << "Item "<< incomes[i].getItem() << endl;
        cout << "IAmount "<< incomes[i].getAmount() << endl;
        cout << endl;
    }
    system("pause");
    return;

}
