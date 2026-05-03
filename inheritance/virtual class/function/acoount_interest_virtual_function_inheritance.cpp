#include<iostream>
using namespace std;

class Account
{
protected:
    float balance;

public:
    void getdata()
    {
        cout<<"Enter balance: ";
        cin>>balance;
    }
    virtual void interest()
    {
        cout<<"Interest calculation for account"<<endl;
    }
};

class SavingAccount : public Account
{
public:
    void interest()
    {
        float si;
        si = balance * 0.05;
        cout<<"Saving Account Interest: "<<si<<endl;
    }
};

class CurrentAccount : public Account
{
public:
    void interest()
    {
        float si;
        si = balance * 0.02;
        cout<<"Current Account Interest: "<<si<<endl;
    }
};

int main()
{
    Account *ptr;
    SavingAccount s;
    CurrentAccount c;

    int choice;

    do
    {
        cout<<"\n---- MENU ----\n";
        cout<<"1. Saving Account Interest\n";
        cout<<"2. Current Account Interest\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                ptr = &s;
                s.getdata();
                ptr->interest();
                break;

            case 2:
                ptr = &c;
                c.getdata();
                ptr->interest();
                break;

            case 3:
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}