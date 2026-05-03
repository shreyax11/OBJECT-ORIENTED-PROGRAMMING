#include<iostream>
using namespace std;

class Book 
{
    string name, author, type, id;
    static int txtCount;
    static int refCount;

public:
    void input() 
    {
        cout<<"Enter name, author, type(text/reference): ";
        cin >> name >> author >> type;

        if(type == "text") 
        {
            txtCount++;
            id = "TXT00" + to_string(txtCount);
        }
        else 
        {
            refCount++;
            id = "REF00" + to_string(refCount);
        }
    }

    void display() 
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

int Book::txtCount = 0;
int Book::refCount = 0;

int main() {
    Book b[3];

    for(int i=0;i<3;i++)
        b[i].input();

    for(int i=0;i<3;i++)
        b[i].display();
}