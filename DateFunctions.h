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

static string loadCurrentDate();
static string checkFormat(string dataToCheck);
static int howManyDaysAreInMonth(string yearInString, string monthInString);
static int loadCurrentYear();
static int loadCurrentMonth();
static int loadCurrentDay();

static string inputYear();
static string inputMonth(string enteredYear);
static string inputDay(string enteredYear, string enteredMonth);
static string enterDateFromKeyboard();
};

#endif
