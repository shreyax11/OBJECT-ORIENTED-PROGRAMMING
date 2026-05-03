#include <iostream>
using namespace std;

// SHALLOW CLASS
class Shallow 
{
public:
    int* data;
    Shallow(int value) 
    {
        data = new int(value);
        cout << "Shallow Constructor\n";
    }
    // No copy constructor → default shallow copy
    void show() 
    {
        cout << "Address stored in pointer: " << data 
             << "  Value: " << *data << endl;
    }
    ~Shallow() 
    {
        cout << "Shallow Destructor\n";
        delete data;
        //tcache = thread cache (used by memory allocator)
        //this will cause double free error when both objects are destroyed
        //and show statement:
        //free(): double free detected in tcache 2
        //Aborted
    }
};

// DEEP CLASS
class Deep 
{
public:
    int* data;
    Deep(int value) 
    {
        data = new int(value);
        cout << "Deep Constructor\n";
    }
    // Deep Copy Constructor
    Deep(const Deep &original) 
    {
        data = new int(*(original.data));
        cout << "Deep Copy Constructor\n";
    }
    void show() 
    {
        cout << "Address stored in pointer: " << data 
             << "  Value: " << *data << endl;
    }
    ~Deep() 
    {
        cout << "Deep Destructor\n";
        delete data;
    }
};
int main() 
{
    int choice;
    do 
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Demonstrate Shallow Copy\n";
        cout << "2. Demonstrate Deep Copy\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) 
        {
            case 1: 
            {
                cout << "\n--- SHALLOW COPY DEMO ---\n";
                Shallow s1(10);
                Shallow s2 = s1;  // shallow copy
                cout << "\nBefore modification:\n";
                s1.show();
                s2.show();
                *s2.data = 50;   // modify one
                cout << "\nAfter modifying s2:\n";
                s1.show();
                s2.show();
                break;
            }
            case 2: 
            {
                cout << "\n--- DEEP COPY DEMO ---\n";
                Deep d1(10);
                Deep d2 = d1;   // deep copy
                cout << "\nBefore modification:\n";
                d1.show();
                d2.show();
                *d2.data = 50;   // modify one
                cout << "\nAfter modifying d2:\n";
                d1.show();
                d2.show();
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 3);
    return 0;
}