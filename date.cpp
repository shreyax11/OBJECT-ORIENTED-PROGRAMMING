#include <iostream>
using namespace std;
//can use const in code
//sp that some details which is standard 
//they can't be changed
class Date
{
private:
    int day, year;
public:
    // enum stores only integer values, not strings
    enum Month { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    Month month;

    // Constructor
    Date(int d=1, int m=1, int y=2000)
    {
        day = d;
        month = Month(m);
        year = y;
    }

    // Leap year check 
    bool isLeapYear() 
    {
        if (year % 400 == 0)
            return true;
        else if (year % 100 == 0)
            return false;
        else if (year % 4 == 0)
            return true;
        else
            return false;
    }

    // Days in month 
    int daysInMonth() 
    {
        if (month == APR || month == JUN || month == SEP || month == NOV)
            return 30;
        else if (month == FEB)
        {
            if (isLeapYear())
                return 29;
            else
                return 28;
        }
        else
            return 31;
    }
    //date validation
    bool isValidDate() 
    {
        if (year < 1)
            return false;
        if (month < JAN || month > DEC)
            return false;

        if (day < 1 || day > daysInMonth())
            return false;

        return true;
    }   


    // Increment date logic
    void incrementDate()
    {
        day++;
        if (day > daysInMonth())
        {
            day = 1;
            month = Month(month + 1);
            if (month > DEC)
            {
                month = JAN;
                year++;
            }
        }
    }

    // Decrement date logic
    void decrementDate()
    {
        day--;
        if (day < 1)
        {
            month = Month(month - 1);
            if (month < JAN)
            {
                month = DEC;
                year--;
            }
            day = daysInMonth();
        }
    }

    // Unary operator overloading
    Date& operator++()        // Pre-increment
    {
        incrementDate();
        return *this;
    }

    Date operator++(int)      // Post-increment
    {
        Date temp = *this;
        incrementDate();
        return temp;
    }

    Date& operator--()        // Pre-decrement
    {
        decrementDate();
        return *this;
    }

    Date operator--(int)      // Post-decrement
    {
        Date temp = *this;
        decrementDate();
        return temp;
    }

    // enum stores only values, not strings
    // So string array is used to map enum value to month name

    // static is used so that the array is created only once
    // const is used to prevent modification of month names

    string monthName() 
    {
        static string m[] ={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        return m[month];
    }

    // One date formatting function
    void displayFormat(int choice) 
    {
        if (choice == 1)
            cout << day << "-" << month << "-" << year << endl;
        else if (choice == 2)
            cout << day << "-" << monthName() << "-" << year << endl;
        else if (choice == 3)
            cout << day << "/" << month << "/" << year << endl;
        else if (choice == 4)
            cout << day << "/" << monthName() << "/" << year << endl;
        else
            cout << "Invalid format choice\n";
    }
};

int main()
{
    int d, m, y;
    cout << "Enter date (DD-MM-YYYY): ";
    cin >> d >> m >> y;
    Date dt(d, m, y);
    int choice, formatChoice;
    do
    {
        cout << "\n----- MAIN MENU -----\n";
        cout << "1. Pre Increment (++date)\n";
        cout << "2. Post Increment (date++)\n";
        cout << "3. Pre Decrement (--date)\n";
        cout << "4. Post Decrement (date--)\n";
        cout << "5. Display Date in Different Format\n";
        cout << "6. Check Date Valid or Not\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                ++dt;
                cout << "After Pre Increment: ";
                dt.displayFormat(2);
                break;
            case 2:
                dt++;
                cout << "After Post Increment: ";
                dt.displayFormat(2);
                break;
            case 3:
                --dt;
                cout << "After Pre Decrement: ";
                dt.displayFormat(2);
                break;
            case 4:
                dt--;
                cout << "After Post Decrement: ";
                dt.displayFormat(2);
                break;
            case 5:
                cout << "\n--- FORMAT MENU ---\n";
                cout << "1. DD-MM-YYYY\n";
                cout << "2. DD-Mon-YYYY\n";
                cout << "3. DD/MM/YYYY\n";
                cout << "4. DD/Mon/YYYY\n";
                cout << "Enter format choice: ";
                cin >> formatChoice;
                dt.displayFormat(formatChoice);
                break;
            case 6:
                if (!dt.isValidDate())
                {
                    cout << "Invalid date entered\n";
                    return 0;
                }   
                else
                    cout << "The date is valid\n";
                break;
            case 7:
                cout << "Program exited\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 7);
    return 0;
}
