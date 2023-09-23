#include "BudgetManager.h"

void::BudgetManager::addIncome() {
    Income newIncome;
    char choice;

    cout << endl << "1. Add today's income." << endl;
    cout << "2. Add an income with a another date." << endl << endl;

    cout << "Your choice: ";
    cin >> choice ;

    switch (choice) {
    case '1':
        newIncome.setDate(DateFunctions::loadCurrentDate());
        break;
    case '2':
        newIncome.setDate(DateFunctions::enterDateFromKeyboard());
        break;
    default:
        cout << endl << "There is no option like this on the menu." << endl << endl;
        system("pause");
        break;
    }

    cout << endl <<  "Please enter the source of income: " << endl;
    newIncome.setItem(AuxiliaryFunctions::loadLine());

    cout << endl;
    newIncome.setAmount(inputNumber());

    newIncome.setUserId(ID_LOGGED_IN_USER);
    newIncome.setIncomeId(xmlIncomes.getLastIncomeId() + 1);
    xmlIncomes.setLastIncomeId(xmlIncomes.getLastIncomeId() + 1);

    incomes.push_back(newIncome);

    xmlIncomes.addIncomeToFile(newIncome);
    cout << endl << "Income added successfully." << endl;
    system("pause");

    return;
}

void BudgetManager::addExpense() {
    Expense newExpense;
    char choice;

    cout << endl << "1. Add today's expense." << endl;
    cout << "2. Add an expense with a another date." << endl << endl;

    cout << "Your choice: ";
    cin >> choice ;

    switch (choice) {
    case '1':
        newExpense.setDate(DateFunctions::loadCurrentDate());
        break;
    case '2':
        newExpense.setDate(DateFunctions::enterDateFromKeyboard());
        break;
    default:
        cout << endl << "There is no option like this on the menu." << endl << endl;
        system("pause");
        break;
    }

    cout << endl <<  "Please enter the source of expense: " << endl;
    newExpense.setItem(AuxiliaryFunctions::loadLine());

    cout << endl;
    newExpense.setAmount(inputNumber());

    newExpense.setUserId(ID_LOGGED_IN_USER);
    newExpense.setExpenseId(xmlExpenses.getLastExpenseId() + 1);
    xmlExpenses.setLastExpenseId((xmlExpenses.getLastExpenseId() + 1));

    expenses.push_back(newExpense);

    xmlExpenses.addExpenseToFile(newExpense);
    cout << endl << "Expense added successfully." << endl;
    system("pause");
    return;
}
void BudgetManager::showAllIncomes() {
    if (incomes.empty()) {
        cout << "No data." << endl << endl;
        system("pause");
        return;
    } else {
        cout << endl << ANSI_BOLD << "Revenues: " << ANSI_RESET << endl;
        sortIncomeVector(incomes);
        for (unsigned int i = 0; i < incomes.size(); i++) {
            DateFunctions::printDateInCorrectFormat(incomes[i].getDate());
            cout << endl << "Item: " << incomes[i].getItem() << endl;
            cout << "Amount: " << incomes[i].getAmount() << endl;
            cout << endl;
        }
    }
    system("pause");
    return;
}

void BudgetManager::showAllExpenses() {
    if (expenses.empty()) {
        cout << "No data." << endl << endl;
        system("pause");
        return;
    } else {
        sortExpenseVector(expenses);
        cout << endl << ANSI_BOLD << "Expenses: " << ANSI_RESET << endl;
        for (unsigned int i = 0; i < expenses.size(); i++) {
            DateFunctions::printDateInCorrectFormat(expenses[i].getDate());
            cout << endl << "Item: " << expenses[i].getItem() << endl;
            cout << "Amount: " << expenses[i].getAmount() << endl;
            cout << endl;
        }
    }
    system("pause");
    return;
}

double BudgetManager::roundingNumber(string numberToRound) {
    string roundedNumber = "";
    stringstream ss;

    string sum = numberToRound;
    double amount = stof(sum);

    ss << fixed << setprecision(2) << amount;
    roundedNumber += ss.str();

    amount  = stof(roundedNumber);
    return amount;
}

double BudgetManager::inputNumber() {
    string sum;
    bool isFormatOk;

    do {
        sum = "";
        isFormatOk = true;

        cout << "Please enter the amount: " << endl;
        sum = AuxiliaryFunctions::loadLine();
        sum = AuxiliaryFunctions::changeCommaToDot(sum);

        string checkedNumberWithoutDots = "";
        int commaCounter = 0;

        for (unsigned int i = 0; i < sum.length(); i++) {
            if (sum[i] != '.') {
                checkedNumberWithoutDots += sum[i];
            } else {
                commaCounter++;
                if (commaCounter > 1) {
                    isFormatOk = false;
                    break;
                }
            }
        }
        for (unsigned int i = 0; i < checkedNumberWithoutDots.length(); i++) {
            if (!isdigit(checkedNumberWithoutDots[i])) {
                isFormatOk = false;
                break;
            }
        }
        if(!isFormatOk) {
            cout << "Incorrect format of the entered amount. Please try again." << endl << endl;
        }
    } while(!isFormatOk);

    double amount = roundingNumber(sum);
    return amount;
}

void BudgetManager::sortIncomeVector(vector <Income> &changeOfDataVector) {
    sort(std::begin(changeOfDataVector), std::end(changeOfDataVector),
    [](ChangeOfBallance& left, ChangeOfBallance& right) {
        return left.getDate() < right.getDate();
    });
}

void BudgetManager::sortExpenseVector(vector <Expense> &changeOfDataVector) {
    sort(std::begin(changeOfDataVector), std::end(changeOfDataVector),
    [](ChangeOfBallance& left, ChangeOfBallance& right) {
        return left.getDate() < right.getDate();
    });
}

void BudgetManager::showTotalBalance(double revenues, double outlay) {
    double sum = revenues - outlay;
    cout << "Total income: " << revenues << endl;
    cout << "Total expenses: " << outlay << endl;
    cout << endl << "Balance: " << sum << endl << endl;
    return;
}

void BudgetManager::showBalanceSheet(int startingDate, int endingDate) {
    if (incomes.empty() & expenses.empty()) {
        cout << "No data." << endl << endl;
        system("pause");
        return;
    } else {
        double revenues = 0, outlay = 0;

        sortIncomeVector(incomes);
        sortExpenseVector(expenses);

        cout << endl << ANSI_BOLD << "Revenues: " << ANSI_RESET << endl;
        for (unsigned int i = 0; i < incomes.size(); i++) {
            if ((incomes[i].getDate() >= startingDate) & (incomes[i].getDate() <= endingDate)) {
                DateFunctions::printDateInCorrectFormat(incomes[i].getDate());
                revenues += incomes[i].getAmount();
                cout << endl << "Item: " << incomes[i].getItem() << endl;
                cout << "Amount: " << incomes[i].getAmount() << endl;
                cout << endl;
            }
        }
        cout << endl << ANSI_BOLD << "Expenses: " << ANSI_RESET << endl;
        for (unsigned int i = 0; i < expenses.size(); i++) {
            if ((expenses[i].getDate() >= startingDate) & (expenses[i].getDate() <= endingDate)) {
                DateFunctions::printDateInCorrectFormat(expenses[i].getDate());
                outlay += expenses[i].getAmount();
                cout << endl << "Item: " << expenses[i].getItem() << endl;
                cout << "Amount: " << expenses[i].getAmount() << endl;
                cout << endl;
            }
        }
        cout << "Balance from: " << endl;
        DateFunctions::printDateInCorrectFormat(startingDate);
        cout << " to" << endl;
        DateFunctions::printDateInCorrectFormat(endingDate);
        cout << endl << endl;
        showTotalBalance(revenues,outlay);
        system("pause");
    }
    return;
}

void BudgetManager::showBalanceSheetForCurrentMonth() {
    int startingDate = DateFunctions::loadStartDateOfCurrentMonth();
    int endingDate = DateFunctions::loadEndDateOfCurrentMonth();
    showBalanceSheet(startingDate, endingDate);
    return;
}

void BudgetManager::showBalanceSheetForPreviousMonth() {
    int startingDate = DateFunctions::loadStartDateOfPreviousMonth();
    int endingDate = DateFunctions::loadEndDateOfPreviousMonth();
    showBalanceSheet(startingDate, endingDate);
    return;
}

void BudgetManager::showBalanceSheetForSelectedPeriod() {
    cout << "Please enter the starting date of the interval:" << endl;
    int startingDate = DateFunctions::enterDateFromKeyboard();
    cout << endl << "Please enter the ending date of the interval:" << endl;
    int endingDate = DateFunctions::enterDateFromKeyboard();

    if (startingDate > endingDate) {
        swap(startingDate, endingDate);
    }
    showBalanceSheet(startingDate, endingDate);
    return;
}
