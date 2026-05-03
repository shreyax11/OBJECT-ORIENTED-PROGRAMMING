#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
protected:
    string name;
    int rollno;
    string course;
    char section;

public:
    void print_line(char ch, int n)
    {
        for (int i = 0; i < n; i++)
            cout << ch;
        cout << endl;
    }

    void getStudentdata()
    {
        cout << "Enter the name of the student: ";
        getline(cin, name);

        cout << "Enter the course of the student: ";
        getline(cin, course);

        cout << "Enter the roll no. of the student: ";
        cin >> rollno;

        cout << "Enter the section of the student: ";
        cin >> section;
    }

    void display()
    {
        print_line('=', 70);
        cout << setw(40) << "report card" << endl;
        print_line('=', 70);
        cout << "Roll no:" << rollno << endl;
        cout << "Name of the student:" << name << endl;
        cout << "Course: " << course << endl;
        cout << "Section: " << section << endl;
        print_line('-', 70);
    }
};

class Academic : virtual public Student
{
protected:
    string sub1, sub2, sub3;
    int m1, m2, m3;
    float total, percentage;

public:
    void getAcademicdata()
    {
        cin.ignore();  // needed before getline after cin

        cout << "Enter the subject name: ";
        getline(cin, sub1);
        cout << "Enter the marks: ";
        cin >> m1;

        cin.ignore();
        cout << "Enter the subject name: ";
        getline(cin, sub2);
        cout << "Enter the marks: ";
        cin >> m2;

        cin.ignore();
        cout << "Enter the subject name: ";
        getline(cin, sub3);
        cout << "Enter the marks: ";
        cin >> m3;

        total = 300.0;
        percentage = ((m1 + m2 + m3) / total) * 100;
    }
};

class Sports : virtual public Student
{
protected:
    string sportsname;
    string performance;

public:
    void getSportsdata()
    {
        cin.ignore();  // needed before getline
        cout << "Enter the sports name: ";
        getline(cin, sportsname);

        cout << "Enter the performance: ";
        getline(cin, performance);
    }
};

class Result : public Academic, public Sports
{
public:
    void display()
    {
        Student::display();

        cout << setw(40) << "Academic report" << endl;
        print_line('-', 70);

        cout << setw(6) << "S NO." << setw(15) << "subject"
             << setw(20) << "max marks" << setw(20) << "obtained marks" << endl;

        print_line('-', 70);

        cout << setw(6) << 1 << setw(15) << sub1 << setw(20) << 100 << setw(20) << m1 << endl;
        cout << setw(6) << 2 << setw(15) << sub2 << setw(20) << 100 << setw(20) << m2 << endl;
        cout << setw(6) << 3 << setw(15) << sub3 << setw(20) << 100 << setw(20) << m3 << endl;

        print_line('-', 70);

        cout << "total marks:" << m1 + m2 + m3 << endl;
        cout << "average marks:" << (m1 + m2 + m3) / 3.0 << endl;  // fixed
        cout << "percentage:" << percentage << "%" << endl;

        print_line('-', 70);

        cout << setw(40) << "sports report" << endl;
        print_line('-', 70);

        cout << setw(6) << "S NO." << setw(15) << "Sports name" << setw(20) << "Performance" << endl;
        cout << setw(6) << "1" << setw(15) << sportsname << setw(20) << performance << endl;

        print_line('-', 70);

        if (percentage >= 40)
            cout << "Result: PASS";
        else
            cout << "Result: FAIL";

        print_line('=', 70);
    }
};

int main()
{
    Result r;
    r.getStudentdata();
    r.getAcademicdata();
    r.getSportsdata();
    r.display();
    return 0;
}