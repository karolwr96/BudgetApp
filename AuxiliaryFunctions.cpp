#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::loadLine() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char AuxiliaryFunctions::loadCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        } else {
            cout << "This is not a single character. Please retype." << endl;
        }
    }
    return character;
}
