#include <iostream>
#include <fstream>
using namespace std;

class Student 
{
    int roll;
    char name[20];
    float marks;

public:
    void input() 
    {
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() 
    {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    int getRoll() 
    {
        return roll;
    }
};

class File 
{
    fstream f;
    string fname;

public:
    void getFileName() 
    {
        cout << "Enter file name: ";
        cin >> fname;
    }
    void add() 
    {
        getFileName();
        f.open(fname, ios::app | ios::binary);

        if (!f) 
        {
            cout << "File error!\n";
            return;
        }

        Student s;
        s.input();
        f.write((char*)&s, sizeof(s));

        f.close();
    }
    void displayAll() 
    {
        getFileName();
        f.open(fname, ios::in | ios::binary);

        if (!f) 
        {
            cout << "File not found!\n";
            return;
        }

        Student s;
        while (f.read((char*)&s, sizeof(s))) 
        {
            s.display();
            cout << "------\n";
        }

        f.close();
    }
    void search() 
    {
        getFileName();
        f.open(fname, ios::in | ios::binary);

        if (!f) 
        {
            cout << "File not found!\n";
            return;
        }

        int r;
        cout << "Enter roll: ";
        cin >> r;

        Student s;
        bool found = false;

        while (f.read((char*)&s, sizeof(s))) 
        {
            if (s.getRoll() == r) 
            {
                cout<<"Record found:\n";
                s.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Record not found!\n";

        f.close();
    }

    void update() 
    {
        getFileName();
        f.open(fname, ios::in | ios::out | ios::binary);
        
        if (!f) 
        {
            cout << "File not found!\n";
            return;
        }
        int r;
        cout << "Enter roll to update: ";
        cin >> r;

        Student s;
        bool found = false;

        while (f.read((char*)&s, sizeof(s))) 
        {
            if (s.getRoll() == r) 
            {

                cout << "Enter new data:\n";
                s.input();

                f.seekp(-sizeof(s), ios::cur);
                f.write((char*)&s, sizeof(s));

                found = true;
                break;
            }
        }

        if (!found)
            cout << "Record not found!\n";

        f.close();
    }
    void countRecords() 
    {
        getFileName();
        f.open(fname, ios::in | ios::binary);

        if (!f) 
        {
            cout << "File not found!\n";
            return;
        }

        Student s;
        int count = 0;

        while (f.read((char*)&s, sizeof(s))) 
            count++;

        cout << "Total students = " << count << endl;

        f.close();
    }
};

int main() 
{
    File obj;
    int ch;

    do {
        cout<<"\n--- STUDENT MENU ---";
        cout << "\n1.Add\n2.Display\n3.Search\n4.Update\n5.Count\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1: obj.add(); break;
            case 2: obj.displayAll(); break;
            case 3: obj.search(); break;
            case 4: obj.update(); break;
            case 5: obj.countRecords(); break;
        }

    } while (ch != 0);

    return 0;
}