#include "SetDateCommand.h"

SetDateCommand::SetDateCommand()
{
    setAlias("setdate");
    setHelp("Enter command and follow instructions to set system date. WARNING: Actually sets your system's date!!!");
    setDesc("Prompt user to update system date.");
}

void SetDateCommand::execute(std::string arg)
{
    int month = getMonthInput();
    int day = getDayInput();
    int year = getYearInput();

    std::string newDate = formatDate(month, day, year);

    #ifdef __linux__
        System("date -set " + newDate);
    #elif __WIN32
        SYSTEMTIME currentTime;
        GetSystemTime(&currentTime);

        SYSTEMTIME newTime;
        newTime.wDayOfWeek = 1;
        newTime.wDay = day;
        newTime.wMonth = month;
        newTime.wYear = year;
        newTime.wHour = currentTime.wHour;
        newTime.wMinute = currentTime.wMinute;
        newTime.wSecond = currentTime.wSecond;
        newTime.wMilliseconds = currentTime.wMilliseconds;
        SetSystemTime(&newTime);

        ///Used for troubleshooting timeset
        //std::cout << "Error: " << GetLastError() << std::endl;
    #endif // __linux__

}

int SetDateCommand::getIntInput()
{
    bool goodInput = false;
    int userInput = 42;

    while(!goodInput)
    {
        std::cin >> userInput;

        if(std::cin.fail())
        {
            //Repeat back
            std::cout << "Incorrect Input" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else
        {
            goodInput = true;
        }
    }

    return userInput;
}

int SetDateCommand::getMonthInput()
{
    bool goodInput = false;
    int monthInput = 42;

    while(!goodInput)
    {
        std::cout << "Enter month(1-12)" << std::endl;
        monthInput = getIntInput();

        if(monthInput < 1 || monthInput > 12)
        {
            std::cout << "Invalid number for month. Enter 1-12" << std::endl;
        }
        else
        {
            goodInput = true;
        }
    }

    return monthInput;
}

int SetDateCommand::getDayInput()
{
    bool goodInput = false;
    int dayInput = 42;

    while(!goodInput)
    {
        std::cout << "Enter day(1-31)" << std::endl;
        dayInput = getIntInput();

        if(dayInput < 1 || dayInput > 31)
        {
            std::cout << "Invalid number for day. Enter 1-31" << std::endl;
        }
        else
        {
            goodInput = true;
        }
    }

    return dayInput;
}

int SetDateCommand::getYearInput()
{
    bool goodInput = false;
    int yearInput = 42;

    while(!goodInput)
    {
        std::cout << "Enter year(1000-9999)" << std::endl;
        yearInput = getIntInput();

        if(yearInput < 1000 || yearInput > 9999 )
        {
            std::cout << "Invalid number for month. This system only allows years between 1000 and 9999" << std::endl;
        }
        else
        {
            goodInput = true;
        }
    }

    return yearInput;
}

std::string SetDateCommand::intToString(int intToConvert)
{
    std::string intStr = "";

    std::ostringstream converter;

    converter << intToConvert;

    intStr = converter.str();

    return intStr;
}

std::string SetDateCommand::formatDate(int month, int day, int year)
{
    std::string date = "";

    date += intToString(year);

    if(month < 10)
    {
        date += "0";
    }

    date += intToString(month);

    if(day < 10)
    {
        date += "0";
    }

    date += intToString(day);

    return date;
}

///Used for testing time changes
void SetDateCommand::printSystemTime(SYSTEMTIME t)
{
    std::cout << t.wDayOfWeek << std::endl;
    std::cout << t.wMonth << " - " << t.wDay << " - " << t.wYear << std::endl;
    std::cout << t.wHour << ":" << t.wMinute << ":" << t.wSecond << ":" << t.wMilliseconds << std::endl;
}
