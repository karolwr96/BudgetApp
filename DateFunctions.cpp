#include "DateFunctions.h"

string DateFunctions::loadCurrentDate() {
    string currentDate = "", currentYear = "", currentMonth = "", currentDay = "";

    SYSTEMTIME st;
    GetSystemTime(&st);

    currentYear = to_string(st.wYear);
    currentMonth = to_string(st.wMonth);
    currentDay = to_string(st.wDay);

    currentMonth = checkFormat(currentMonth);
    currentDay = checkFormat(currentDay);

    cout << currentYear << endl;
    cout << currentMonth << endl;
    cout << currentDay << endl;

    currentDate = currentYear + currentMonth + currentDay;

    return currentDate;
}

string DateFunctions::checkFormat(string dataToCheck) {
    string formattedData = "";

    if (dataToCheck.length() == 2) {
        formattedData = dataToCheck;
    } else if (dataToCheck.length() == 1) {
        formattedData = "0" + dataToCheck;
    }
    return formattedData;
}
/*
string changeFormatToTwoDigit(string dateToChange) {
    Date formattedDate;

    formattedDate.year = dateToChange.year;
    formattedDate.month = checkFormat(dateToChange.month);
    formattedDate.day = checkFormat(dateToChange.day);

    return formattedDate;
}
*/

