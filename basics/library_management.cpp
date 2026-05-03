#include <iostream>
using namespace std;

class Library
{
private:
    int issued;   // 0 = not issued, 1 = issued

public:
    Library()
    {
        issued = 0;   
    }
    void issue()
    {
        if (issued == 0)
        {
            issued = 1;
            cout << "Book issued\n";
        }
        else
            cout << "Book already issued\n";
    }
    void submit()
    {
        if (issued == 1)
        {
            issued = 0;
            cout << "Book returned\n";
        }
        else
            cout << "No book to return\n";
    }
    void status()
    {
        if (issued == 1)
        {
            cout << "Book is issued\n";
        }
        else
            cout << "Book available\n";
    }
};

int main()
{
    Library l;
    int ch;
    do
    {
        cout << "\nLibrary Management";
        cout << "\n1.Issue book \n2.Return book\n3.Status \n4.Exit\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                l.issue();
                break;
            case 2:
                l.submit();
                break;
            case 3:
                l.status();
                break;
            case 4:
                cout<<"exiting the library system...";
                break;
            default:
                cout<<"invalid choice..\n";
        }
    } while (ch != 4);
    return 0;
}
