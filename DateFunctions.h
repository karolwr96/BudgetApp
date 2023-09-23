#ifndef DATEFUNCTIONS_H
#define DATEFUNCTIONS_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <string>

#include "AuxiliaryFunctions.h"

using namespace std;

class DateFunctions {
public :
    static int loadCurrentDate();
    static string checkFormat(string dataToCheck);
    static int howManyDaysAreInMonth(string yearInString, string monthInString);
    static int loadCurrentYear();
    static int loadCurrentMonth();
    static int loadCurrentDay();
    static int loadStartDateOfCurrentMonth();
    static int loadEndDateOfCurrentMonth();
    static int loadStartDateOfPreviousMonth();
    static int loadEndDateOfPreviousMonth();

    static string inputYear();
    static string inputMonth(string enteredYear);
    static string inputDay(string enteredYear, string enteredMonth);
    static int enterDateFromKeyboard();
    static void printDateInCorrectFormat(int date);
};

#endif
