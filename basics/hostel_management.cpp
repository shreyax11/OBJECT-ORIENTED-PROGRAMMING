#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void printline(char ch = '-', int n = 70)
{
    for(int i = 0; i < n; i++)
        cout << ch;
    cout << endl;
}
class Person {
protected:
    string name;
    int age;

public:
    void inputPerson() 
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPerson() const 
    {
        cout<< setw(15) << name
             << setw(6)  << age;
    }
};

class Student : public Person 
{
private:
    int rollno;
    string branch;
    int year;

public:
    void inputStudent() 
    {
        inputPerson();

        cout << "Enter Roll No: ";
        cin >> rollno;

        int choice;
        cout << "\nSelect Branch:\n";
        cout << "1.CS 2.IT 3.EEE 4.EC 5.VLSI 6.BIOTECH 7.MT\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1: branch = "CS"; break;
            case 2: branch = "IT"; break;
            case 3: branch = "EEE"; break;
            case 4: branch = "EC"; break;
            case 5: branch = "VLSI"; break;
            case 6: branch = "BIOTECH"; break;
            case 7: branch = "MT"; break;
            default: branch = "Unknown";
        }

        cout << "Enter Year (1-4): ";
        cin >> year;
        if(year < 1 || year > 4) 
        {
            cout << "Invalid Year! Setting to 1.\n";
            year = 1;
        }
    }

    void displayStudent(float totalFee) const 
    {
        cout << setw(10) << rollno;
        displayPerson();
        cout << setw(12) << branch << setw(6)  << year << setw(12) << totalFee << endl;
    }

    int getYear() const 
    {
        return year;
    }
};

class FeeStructure 
{
private:
    float hostelFee[4] = {50000,52000,54000,56000};
    float messFee[4]   = {20000,21000,22000,23000};

public:
    float calculateTotalFee(int year) const 
    {
        return hostelFee[year-1] + messFee[year-1];
    }

    void displayAllFees() const 
    {
        cout << "\n=========== FEE STRUCTURE (ALL YEARS) ===========\n";
        printline('-', 70);
        //cout << "-------------------------------------------------\n";
        cout << setw(8)  << "Year" << setw(15) << "HostelFee" << setw(12) << "MessFee" << setw(12) << "TotalFee" << endl;
        cout << "-------------------------------------------------\n";

        for(int i = 1; i <= 4; i++) 
        {
            cout << setw(8)  << i << setw(15) << hostelFee[i-1] << setw(12) << messFee[i-1] << setw(12) << (hostelFee[i-1] + messFee[i-1]) << endl;
        }
        printline('-', 70);
        //cout << "-------------------------------------------------\n";
    }
};

class Room 
{
private:
    int roomNo;
    Student students[3];
    int studentCount;

public:
    Room() 
    {
        studentCount = 0;
    }

    void setRoomNo(int r) 
    {
        roomNo = r;
    }

    void addStudents() 
    {
        if(studentCount >= 3) 
        {
            cout << "Room already full!\n";
            return;
        }

        int n;
        cout << "How many students to add in Room "
             << roomNo << " (Max "
             << 3 - studentCount << "): ";
        cin >> n;

        if(n < 1 || n > (3 - studentCount)) 
        {
            cout << "Invalid number!\n";
            return;
        }

        for(int i = 0; i < n; i++) 
        {
            cout << "\n--- Enter Student "
                 << (studentCount + 1)
                 << " Details ---\n";
            students[studentCount].inputStudent();
            studentCount++;
        }
    }

    void displayRoom(const FeeStructure &fee) const 
    {

        cout << "\nRoom No: " << roomNo << endl;
        printline('-', 70);
        //cout << "----------------------------------------------------------\n";
        cout << setw(10) << "RollNo" << setw(15) << "Name" << setw(6)  << "Age" << setw(12) << "Branch" << setw(6)  << "Year" << setw(12) << "TotalFee" << endl;
        //cout << "----------------------------------------------------------\n";
        printline('-', 70);
        for(int i = 0; i < studentCount; i++) 
        {
            float total = fee.calculateTotalFee(students[i].getYear());
            students[i].displayStudent(total);
        }

        for(int i = studentCount; i < 3; i++) 
        {
            cout << setw(10) << "-" << setw(15) << "EMPTY" << setw(6)  << "-" << setw(12) << "-" << setw(6)  << "-" << setw(12) << "-" << endl;
        }
        printline('-', 70);
        //cout << "----------------------------------------------------------\n";
    }
};

class Hostel 
{
private:
    string hostelName;
    Room rooms[5];
    FeeStructure fee;

public:
    void setHostelName(string name) 
    {
        hostelName = name;
        for(int i=0;i<5;i++)
            rooms[i].setRoomNo(i+1);
    }

    void addStudentToRoom(int index) 
    {
        rooms[index].addStudents();
    }

    void displayHostel() const 
    {
        cout << "\n=========== " << hostelName << " ===========\n";
        for(int i=0;i<5;i++)
            rooms[i].displayRoom(fee);
    }

    void showAllFeeStructure() const 
    {
        fee.displayAllFees();
    }
};

int main() 
{

    Hostel hostels[2];
    hostels[0].setHostelName("Girls Hostel A");
    hostels[1].setHostelName("Girls Hostel B");

    int choice;

    do 
    {
        cout << "\n====== HOSTEL MANAGEMENT ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display Hostel Report\n";
        cout << "3. View Fee Structure (All Years)\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) 
        {

            case 1: 
            {
                int h, r;

                cout << "Select Hostel (1-Girls Hostel A / 2-Girls Hostel B): ";
                cin >> h;

                if(h < 1 || h > 2) 
                {
                    cout << "Invalid Hostel!\n";
                    break;
                }

                cout << "Select Room (1-5): ";
                cin >> r;

                if(r < 1 || r > 5) 
                {
                    cout << "Invalid Room!\n";
                    break;
                }

                hostels[h - 1].addStudentToRoom(r - 1);
                break;
            }

            case 2:
            {
                cout<<"choose hostel detail want to see (1/2)\n";
                int ch;
                cin>>ch;
                switch(ch)
                {
                    case 1:
                        hostels[0].displayHostel();
                        break;
                    case 2:
                        hostels[1].displayHostel();
                        break;
                    default:
                        cout<<"INVALID CHOICE...\n";
                }
                break;
            }
            case 3:
                hostels[0].showAllFeeStructure();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}