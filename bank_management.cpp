#include <iostream>
#include<iomanip>
using namespace std;

class Bank
{
    float balance = 0;

public:
    void print_line(char ch, int n)
    {
        for (int i = 0; i < n; i++)
            cout << ch;
        cout << endl;
    }
    void deposit()
    {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
    }

    void withdraw()
    {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient balance\n";
    }

    void show()
    {
        cout << "Current Balance = " << balance << endl;
    }
    void show_receipt()
    {
        print_line('=', 50);            
        cout << setw(30) << "BALANCE RECEIPT\n";
        print_line('=', 50);
        cout << "Available Balance : Rs. " << balance << endl;
        print_line('=', 50);
    }
};

int main()
{
    Bank b;
    int ch;

    do
    {
        cout<<"\n___________bank management____________";
        cout << "\n1.Deposit \n2.Withdraw \n3.Balance \n4.Show receipt \n5.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: b.deposit(); break;
        case 2: b.withdraw(); break;
        case 3: b.show(); break;
        case 4: b.show_receipt(); break;
        case 5:
            cout<<"exting...\n";
            exit(0);
            break;
        default: 
            cout<<"invalid choice...\n";
        }
    } while (1);

    return 0;
}
