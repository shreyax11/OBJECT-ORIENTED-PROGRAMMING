#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int roll;
    char name[20];

public:
    void getData()
    {
        cout<<"Enter roll and name: ";
        cin >> roll >> name;
    }

    void showData()
    {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
    }

    int getRoll()
    {
        return roll;
    }
};

int main()
{
    Student s;
    ofstream fout("student.dat", ios::binary);
    for(int i = 0; i < 3; i++)
    {
        s.getData();
        fout.write((char*)&s, sizeof(s));
    }
    fout.close();
    ifstream fin("student.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    int r, found = 0;
    cout << "Enter roll to delete: ";
    cin >> r;

    while(fin.read((char*)&s, sizeof(s)))
    {
        if(s.getRoll() == r)
        {
            found = 1;   // skip this record
        }
        else
        {
            temp.write((char*)&s, sizeof(s));
        }
    }

    fin.close();
    temp.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if(found)
        cout << "Record Deleted";
    else
        cout << "Record Not Found";
}