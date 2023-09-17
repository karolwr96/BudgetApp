#include "Menu.h"

char Menu::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << " .: Main Menu :." << endl << endl;
    cout << "1. User registration." << endl;
    cout << "2. Login." << endl;
    cout << "3. Show all users." << endl << endl;
    cout << "9. Exit from the programm." << endl << endl;
    cout << "Your choice: ";
    choice = AuxiliaryFunctions::loadCharacter();
    return choice;
}

void Menu::closeTheProgram() {
    system("cls");
    cout << "Thanks for using our programm!" << endl;
    exit(0);
}

char Menu::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " .: User Menu :." << endl << endl;
    cout << "1. Add income." << endl;
    cout << "2. Show all incomes." << endl;
    cout << "2. Add expense." << endl;
    cout << "3. Balance for the current month." << endl;
    cout << "4. Previous month's balance." << endl;
    cout << "5. Balance for the selected period." << endl << endl;

    cout << "6. Change the password." << endl;
    cout << "7. Log out." << endl;
    cout << "8. Exit from the programm." << endl << endl;
    cout << "Your choice: ";
    choice = AuxiliaryFunctions::loadCharacter();
    return choice;
}

