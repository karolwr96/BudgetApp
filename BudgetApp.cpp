#include "BudgetApp.h"

void BudgetApp::showOptionsFromMainMenu() {
    while (true) {
        if (!userManager.getIdLoggedInUser()) {
            char choice = menu.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                userManager.userRegistration();
                break;
            case '2':
                userManager.loginUser();
                if (userManager.getIdLoggedInUser() > 0) {
                    budgetManager = new BudgetManager(userManager.getIdLoggedInUser());
                }
                break;
            case '3':
                userManager.showAllUsers();
                break;
            case '0':
                menu.closeTheProgram();
                break;
            default:
                cout << endl << "There is no option like this on the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            char choice = menu.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                budgetManager->addIncome();
                break;
            case '2':
                budgetManager->addExpense();
                break;
            case '3':
                budgetManager->showAllIncomes();
                break;
            case '4':
                budgetManager->showAllExpenses();
                break;
            case '8':
                userManager.changePasswordLoggedInUser();
                break;
            case '9':
                userManager.logOutUser();
                delete budgetManager;
                budgetManager = NULL;
                break;
            case '0':
                menu.closeTheProgram();
                break;
            default:
                cout << endl << "There is no option like this on the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return;
}









