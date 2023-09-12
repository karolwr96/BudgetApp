#ifndef DATEFUNCTIONS_H
#define DATEFUNCTIONS_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <string>

using namespace std;

class DateFunctions {
public :

static string loadCurrentDate();
static string checkFormat(string dataToCheck);

};

#endif
