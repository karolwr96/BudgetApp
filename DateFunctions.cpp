#include "DateFunctions.h"

int DateFunctions::loadCurrentDate() {
    string currentDate = "", currentYear = "", currentMonth = "", currentDay = "";

    SYSTEMTIME st;
    GetSystemTime(&st);

    currentYear = to_string(st.wYear);
    currentMonth = to_string(st.wMonth);
    currentDay = to_string(st.wDay);

    currentMonth = checkFormat(currentMonth);
    currentDay = checkFormat(currentDay);

    currentDate = currentYear + currentMonth + currentDay;
    int dateToReturn = stoi(currentDate);
    return dateToReturn;
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

int DateFunctions::loadCurrentYear() {
    int currentYear;

    SYSTEMTIME st;
    GetSystemTime(&st);
    currentYear = (st.wYear);
    return currentYear;
}

int DateFunctions::loadCurrentMonth() {
    int currentMonth;

    SYSTEMTIME st;
    GetSystemTime(&st);
    currentMonth = (st.wMonth);
    return currentMonth;
}

int DateFunctions::loadCurrentDay() {
    int currentDay;

    SYSTEMTIME st;
    GetSystemTime(&st);
    currentDay = (st.wDay);
    return currentDay;
}

int DateFunctions::loadStartDateOfCurrentMonth() {
    string startDateOfCurrenMonth = "";
    int yearOfCurrentMonth = loadCurrentYear();
    int currentMonth = loadCurrentMonth();

    startDateOfCurrenMonth = to_string(yearOfCurrentMonth) + checkFormat(to_string(currentMonth)) + "01";
    return stoi(startDateOfCurrenMonth);
}

int DateFunctions::loadEndDateOfCurrentMonth() {
    string endDateOfCurrenMonth = "";
    int yearOfCurrentMonth = loadCurrentYear();
    int currentMonth = loadCurrentMonth();
    int endDayOfCurrentMonth = howManyDaysAreInMonth(to_string(yearOfCurrentMonth), to_string(currentMonth));

    endDateOfCurrenMonth = to_string(yearOfCurrentMonth) + checkFormat(to_string(currentMonth)) + checkFormat(to_string(endDayOfCurrentMonth));
    return stoi(endDateOfCurrenMonth);
}

int DateFunctions::loadStartDateOfPreviousMonth() {
    string startPreviousMonth = "";
    int previousMonth, yearOfPreviousMonth, startDateOfPreviousMonth;

    if(loadCurrentMonth() == 12) {
        previousMonth = 01;
        yearOfPreviousMonth = loadCurrentYear() - 1;
    } else {
        previousMonth = loadCurrentMonth() - 1;
        yearOfPreviousMonth = loadCurrentYear();
    }

    startPreviousMonth = to_string(yearOfPreviousMonth) + checkFormat(to_string(previousMonth)) + "01";
    startDateOfPreviousMonth = stoi(startPreviousMonth);
    return startDateOfPreviousMonth;
}

int DateFunctions::loadEndDateOfPreviousMonth() {
    string endDateOfPreviousMonth = "";
    int previousMonth, yearOfPreviousMonth, lastDayOfPreviousMonth;

    if(loadCurrentMonth() == 12) {
        previousMonth = 01;
        yearOfPreviousMonth = loadCurrentYear() - 1;
    } else {
        previousMonth = loadCurrentMonth() - 1;
        yearOfPreviousMonth = loadCurrentYear();
    }
    lastDayOfPreviousMonth = howManyDaysAreInMonth(to_string(yearOfPreviousMonth), to_string(previousMonth));
    endDateOfPreviousMonth = to_string(yearOfPreviousMonth) + checkFormat(to_string(previousMonth)) + checkFormat(to_string(lastDayOfPreviousMonth));

    return stoi(endDateOfPreviousMonth);
}

int DateFunctions::howManyDaysAreInMonth(string yearInString, string monthInString) {
    int year,month, numberOfDays;
    year = stoi(yearInString);
    month = stoi(monthInString);

    if (month == 4 || month == 6 || month == 9 || month == 11)
        numberOfDays = 30;

    else if (month == 02) {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (!leapYear)
            numberOfDays = 28;
        else
            numberOfDays = 29;
    } else
        numberOfDays = 31;
    return numberOfDays;
}

string DateFunctions::inputYear() {
    string year;
    bool isYearOk;
    do {
        isYearOk = true;
        cout << "Please enter the year:" << endl;
        year = AuxiliaryFunctions::loadLine();
        for (unsigned int i = 0; i < year.length(); i++) {
            if (!isdigit(year[i])) {
                isYearOk = false;
                break;
            }
        }
        if (year.length() > 4) {
            isYearOk = false;
        }
        if(!isYearOk) {
            cout << "The year was entered incorrectly. Please try again." << endl << endl;
        } else if(stoi(year) > loadCurrentYear() && isYearOk) {
            cout << "A year greater than the current one was introduced. Please try again." << endl << endl;
            isYearOk = false;
        } else if(stoi(year) < 2000 && isYearOk) {
            cout << "The program supports dates from 2000.01.01. Please try again." << endl << endl;
            isYearOk = false;
        }

    } while (!isYearOk);
    return year;
}

string DateFunctions::inputMonth(string enteredYear) {
    string month;
    bool isMonthOk;
    do {
        isMonthOk = true;
        cout << "Please enter the month:" << endl;
        month = AuxiliaryFunctions::loadLine();
        for (unsigned int i = 0; i < month.length(); i++) {
            if (!isdigit(month[i])) {
                isMonthOk = false;
                break;
            }
        }
        if (month.length() > 2) {
            isMonthOk = false;
        }
        if(!isMonthOk) {
            cout << "The month was entered incorrectly. Please try again. Please try again." << endl << endl;
        } else if((stoi(month) <= 0 || stoi(month) > 12) && isMonthOk) {
            cout << "Month must be greater than 0 and less than or equal to 12. Please try again." << endl << endl;
            isMonthOk = false;
        } else if(stoi(enteredYear) == loadCurrentYear() && stoi(month) > loadCurrentMonth() && isMonthOk) {
            cout << "A month greater than the current one was introduced. Please try again." << endl << endl;
            isMonthOk = false;
        }
    } while (!isMonthOk);
    month = checkFormat(month);
    return month;
}

string DateFunctions::inputDay(string enteredYear, string enteredMonth) {
    string day;
    bool isDayOk;
    do {
        isDayOk = true;
        cout << "Please enter the day:" << endl;
        day = AuxiliaryFunctions::loadLine();
        for (unsigned int i = 0; i < day.length(); i++) {
            if (!isdigit(day[i])) {
                isDayOk = false;
                break;
            }
        }
        if (day.length() > 2) {
            isDayOk = false;
        }
        if(!isDayOk) {
            cout << "The day was entered incorrectly. Please try again. Please try again." << endl << endl;
        } else if((stoi(day) <= 0 || stoi(day) > howManyDaysAreInMonth(enteredYear, enteredMonth)) && isDayOk) {
            cout << "Day must be greater than 0 and less than or equal to the number of days of the month. Please try again." << endl << endl;
            isDayOk = false;
        } else if(stoi(enteredYear) == loadCurrentYear() && stoi(enteredMonth) == loadCurrentMonth() && stoi(day) > loadCurrentDay() && isDayOk) {
            cout << "A day greater than the current one was introduced. Please try again." << endl << endl;
            isDayOk = false;
        }
    } while (!isDayOk);
    day = checkFormat(day);
    return day;
}

int DateFunctions::enterDateFromKeyboard() {
    string year = "", month = "", day = "", date = "";
    year = inputYear();
    month = inputMonth(year);
    day = inputDay(year, month);
    date = year + month + day;

    int dateToReturn = stoi(date);
    return dateToReturn;
}

void DateFunctions::printDateInCorrectFormat(int date) {
    string dateToPrint = to_string(date);
    cout << "Date: ";
    for (unsigned int i = 0; i < 4; i++) {
        cout << dateToPrint[i];
    }
    cout << "-";
    for (unsigned int i = 4; i < 6; i++) {
        cout << dateToPrint[i];
    }
    cout << "-";
    for (unsigned int i = 6; i <= 7; i++) {
        cout << dateToPrint[i];
    }
    return;
}
