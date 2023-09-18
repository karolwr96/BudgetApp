#include "BudgetManager.h"

void::BudgetManager::addIncome() {
    Income newIncome;
    char choice;

    cout << endl << "1. Add today's expense." << endl;
    cout << "2. Add an expense with a another date." << endl << endl;

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
    newIncome.setIncomeId (123);

    incomes.push_back(newIncome);

    xmlIncomes.addIncomeToFile(newIncome);
    cout << endl << "Income added successfully." << endl;
    system("pause");

    return;
}

void BudgetManager::showAllIncome() {
    for (unsigned int i = 0; i < incomes.size(); i++) {
        cout << "Income id " << incomes[i].getIncomeId() << endl;
        cout << "User id "<< incomes[i].getUserId() << endl;
        cout << "Date "<< incomes[i].getDate() << endl;
        cout << "Item "<< incomes[i].getItem() << endl;
        cout << "Amount "<< incomes[i].getAmount() << endl;
        cout << endl;
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

        cout << "Please enter the amount of income: " << endl;
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
