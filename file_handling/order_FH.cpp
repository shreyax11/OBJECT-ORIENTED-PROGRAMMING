#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Order 
{
public:
    string name;
    int qty;
    float price;

    void input() 
    {
        cout<<"Enter name qty price: ";
        cin >> name >> qty >> price;
    }

    float total() 
    {
        return qty * price;
    }

    void save() 
    {
        ofstream fout("order.txt", ios::app);
        fout << name << " " << qty << " " << price << endl;
        fout.close();
    }

    void showAll() 
    {
        ifstream fin("order.txt");

        if(!fin) 
        {
            cout << "No data found\n";
            return;
        }

        Order o;

        cout << "\n-------------------------------------\n";
        cout << setw(10) << "Name" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total\n";
        cout << "-------------------------------------\n";

        while(fin >> o.name >> o.qty >> o.price) {
            cout << setw(10) << o.name << setw(10) << o.qty << setw(10) << o.price << setw(10) << o.total() << endl;
        }

        fin.close();
    }

    void showUnpaid() {
        ifstream fin("order.txt");

        if(!fin) {
            cout << "No data found\n";
            return;
        }

        Order o;
        bool found = false;

        cout << "\n------ UNPAID ORDERS (>250) ------\n";
        cout << setw(10) << "Product" << setw(15) << "Unpaid Amount\n";
        cout << "------------------------------\n";

        while(fin >> o.name >> o.qty >> o.price) {
            float t = o.total();

            if(t > 250) {
                cout << setw(10) << o.name << setw(15) << t << endl;
                found = true;
            }
        }

        if(!found)
            cout << "No unpaid orders\n";

        fin.close();
    }
};

int main() {
    Order o;
    int choice;

    do {
        cout<<"\n---- ORDER MENU ----";
        cout<<"\n1.Add\n2.Display\n3.Unpaid\n4.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice == 1) {
            o.input();
            o.save();
        }
        else if(choice == 2) {
            o.showAll();
        }
        else if(choice == 3) {
            o.showUnpaid();
        }

    } while(choice != 4);

    return 0;
}