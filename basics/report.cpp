#include<iostream>
#include<string>
using namespace std;

class Report
{
    int admno;
    string name;
    string subject[5];
    float marks[5];
    float avg;

public:
    void readinfo()
    {
        cout<<"Enter admission number: ";
        cin>>admno;

        cout<<"Enter name: ";
        cin>>name;

        float sum = 0;

        for(int i=0;i<5;i++)
        {
            cout<<"Enter subject name: ";
            cin>>subject[i];

            cout<<"Enter marks: ";
            cin>>marks[i];

            sum += marks[i];
        }

        avg = sum/5;
    }

    void displayinfo()
    {
        cout<<"\n--- REPORT ---\n";
        cout<<"Adm No: "<<admno<<endl;
        cout<<"Name: "<<name<<endl;

        for(int i=0;i<5;i++)
            cout<<subject[i]<<" : "<<marks[i]<<endl;

        cout<<"Average: "<<avg<<endl;
    }
};

int main()
{
    Report r;
    r.readinfo();
    r.displayinfo();
    return 0;
}