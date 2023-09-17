#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::loadLine() {
    cin.sync();
    string output = "";
    getline(cin, output);
    return output;
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

string AuxiliaryFunctions::changeCommaToDot(string inscription) {
    string formattedText = "";
    for (unsigned int i = 0; i < inscription.length(); i++) {
        if (inscription[i] == ',') {
            inscription[i] = '.';
        }
        formattedText += inscription[i];
    }
    return formattedText;
}
