#include <iostream>
#include <iomanip>
using namespace std;

/*

We define ostream manipulator function outside the class 
because it needs to work with cout << function syntax. 
Inside class it becomes a member function and cannot behave like a stream manipulator.

*/
ostream& line(ostream& out) 
{
    for(int i = 0; i < 50; i++)
        out << "-";
    out << endl;
    return out;
}

class Student 
{
protected:
    string name;
    int roll;

public:
    void getData() 
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> roll;
    }
    void showData() 
    {
        cout << left << setw(20) << "Name:" << name << endl;
        cout << left << setw(20) << "Roll No:" << roll << endl;
    }
};

class Result : public Student 
{
private:
    int n;
    string sub[10];
    int marks[10];
    int total = 0;

public:
    void getMarks() 
    {
        cout << "Enter number of subjects: ";
        cin >> n;
        for(int i = 0; i < n; i++) 
        {
            cout << "Enter subject name: ";
            cin >> sub[i];
            cout << "Enter marks: ";
            cin >> marks[i];
        }
    }

    void calculate() 
    {
        total = 0;
        for(int i = 0; i < n; i++) 
        {
            total += marks[i];
        }
    }
    void display() 
    {
        cout << line;
        cout << setw(30) << "REPORT CARD\n";
        cout << line;
        showData();
        cout << line;
        cout << left << setw(25) << "Subject" 
             << setw(10) << "Marks" << endl;

        cout << line;
        for(int i = 0; i < n; i++) 
        {
            cout << left << setw(25) << sub[i]
                 << setw(10) << marks[i] << endl;
        }
        cout << line;
        cout << left << setw(25) << "Total Obtained:" << total << endl;
        cout << left << setw(25) << "Total Marks:" << n * 100 << endl;
        float per = ((float)total / (n * 100)) * 100;
        cout << left << setw(25) << "Percentage:" << per << "%" << endl;

        cout << line;
    }
};

int main() 
{
    Result r;

    r.getData();
    r.getMarks();
    r.calculate();
    r.display();

    return 0;
}
