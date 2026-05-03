#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream fout, even, odd;
    ifstream fin;

    int choice;

    do {
        cout<<"\n--- EVEN ODD MENU ---";
        cout<<"\n1.Add Numbers";
        cout<<"\n2.Separate Even/Odd";
        cout<<"\n3.Display Files";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice) 
        {

        case 1: 
        {
            fout.open("data.txt", ios::app);

            int n, x;
            cout<<"How many numbers: ";
            cin>>n;

            cout<<"\nEnter numbers: ";
            for(int i=0;i<n;i++) {
                cin>>x;
                fout << x << " ";
            }

            fout.close();
            break;
        }

        case 2: 
        {
            fin.open("data.txt");

            if(!fin) {
                cout<<"No data file found\n";
                break;
            }

            even.open("even.txt");
            odd.open("odd.txt");

            int x;
            while(fin >> x) 
            {
                if(x % 2 == 0)
                    even << x << " ";
                else
                    odd << x << " ";
            }

            fin.close();
            even.close();
            odd.close();

            cout<<"Separated successfully\n";
            break;
        }

        case 3: 
        {
            int x;

            cout<<"\nEven Numbers:\n";
            fin.open("even.txt");

            if(!fin) 
                cout<<"No even file\n";
            else 
            {
                while(fin >> x)
                    cout << x << " ";
                fin.close();
            }

            cout<<"\nOdd Numbers:\n";
            fin.open("odd.txt");

            if(!fin) 
                cout<<"No odd file\n";
            else 
            {
                while(fin >> x)
                    cout << x << " ";
                fin.close();
            }

            break;
        }

        case 4:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}