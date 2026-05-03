/*
Write a menu driven program in C++ 
to create a class BankAccount with data members 
account number and customer name and a method to display these details. 
Create two subclasses SavingAccount and CurrentAccount that 
include getBalance() method to generate messages if balance falls below 500 or 1000 respectively.
*/


#include<iostream>
using namespace std;

class BankAccount
{
protected:
    int acc_no;
    string name;

public:
    void getDetails()
    {
        cout<<"Enter Account Number: ";
        cin>>acc_no;
        cout<<"Enter Customer Name: ";
        cin>>name;
    }

    void display()
    {
        cout<<"\nAccount Number: "<<acc_no;
        cout<<"\nCustomer Name: "<<name<<endl;
    }
};

class SavingAccount : public BankAccount
{
    float balance;

public:
    void getBalance()
    {
        getDetails();
        cout<<"Enter Balance: ";
        cin>>balance;
    }

    void checkBalance()
    {
        display();
        cout<<"Balance: "<<balance<<endl;

        if(balance < 500)
            cout<<"Warning: Balance below minimum (500)...\n";
        else
            cout<<"Balance is sufficient...\n";
    }
};

class CurrentAccount : public BankAccount
{
    float balance;

public:
    void getBalance()
    {
        getDetails();
        cout<<"Enter Balance: ";
        cin>>balance;
    }

    void checkBalance()
    {
        display();
        cout<<"Balance: "<<balance<<endl;

        if(balance < 1000)
            cout<<"Warning: Balance below minimum (1000)\n";
        else
            cout<<"Balance is sufficient\n";
    }
};

int main()
{
    int choice;
    SavingAccount s;
    CurrentAccount c;

    do
    {
        cout<<"\n----- BANK MENU -----";
        cout<<"\n1. Saving Account";
        cout<<"\n2. Current Account";
        cout<<"\n3. Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                s.getBalance();
                s.checkBalance();
                break;

            case 2:
                c.getBalance();
                c.checkBalance();
                break;

            case 3:
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }

    }while(choice != 3);

    return 0;
}