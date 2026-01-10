//implementation of a class box , having 3 private member variables
// length l,breath b, height h
//and member functions are 
//getdata(),showdata(),volume(),compare()

#include <iostream>
using namespace std;
class Box {
    int l, b, h;
public:
    void getData() {
        cout << "Enter l b h: ";
        cin >> l >> b >> h;
    }
    void showData() {
        cout << "l = " << l << " b = " << b << " h = " << h << endl;
    }
    int volume() {
        return l * b * h;
    }
    void compare(Box other) {
        if (volume() > other.volume())
            cout << "Box 1 has greater volume\n";
        else if (volume() < other.volume())
            cout << "Box 2 has greater volume\n";
        else
            cout << "Both boxes have equal volume\n";
    }
};
int main() {
    Box b1, b2;
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Get data of Box 1\n";
        cout << "2. Get data of Box 2\n";
        cout << "3. Show data of both boxes\n";
        cout << "4. Show volume of both boxes\n";
        cout << "5. Compare volumes\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            b1.getData();
            break;
        case 2:
            b2.getData();
            break;
        case 3:
            cout << "Box 1: ";
            b1.showData();
            cout << "Box 2: ";
            b2.showData();
            break;
        case 4:
            cout << "Volume of Box 1 = " << b1.volume() << endl;
            cout << "Volume of Box 2 = " << b2.volume() << endl;
            break;
        case 5:
            b1.compare(b2);
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);
    return 0;
}
