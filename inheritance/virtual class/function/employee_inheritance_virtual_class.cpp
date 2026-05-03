#include<iostream>
using namespace std;

class Person
{
protected:
    string personName;
    int personAge;

public:
    void getPerson()
    {
        cout<<"Enter Name: ";
        cin>>personName;
        cout<<"Enter Age: ";
        cin>>personAge;
    }

    void showPerson()
    {
        cout<<"Name: "<<personName<<endl;
        cout<<"Age: "<<personAge<<endl;
    }
};

class Employee : virtual public Person
{
protected:
    int employeeID;

public:
    void getEmployee()
    {
        getPerson();
        cout<<"Enter Employee ID: ";
        cin>>employeeID;
    }

    void showEmployee()
    {
        showPerson();
        cout<<"Employee ID: "<<employeeID<<endl;
    }
};

class Manager : virtual public Person
{
protected:
    int managerID;

public:
    void getManager()
    {
        getPerson();
        cout<<"Enter Manager ID: ";
        cin>>managerID;
    }

    void showManager()
    {
        showPerson();
        cout<<"Manager ID: "<<managerID<<endl;
    }
};

class TeamLead : public Employee, public Manager
{
    float bonusAmount;

public:
    void getTeamLead()
    {
        cout<<"Enter Employee Details\n";
        getEmployee();

        cout<<"Enter Manager Details\n";
        getManager();

        cout<<"Enter Bonus: ";
        cin>>bonusAmount;
    }

    void showTeamLead()
    {
        cout<<"\nTeam Lead Details\n";
        showEmployee();
        showManager();
        cout<<"Bonus: "<<bonusAmount<<endl;
    }
};

int main()
{
    TeamLead lead;
    lead.getTeamLead();
    lead.showTeamLead();

    return 0;
}