#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
    ofstream fout;
    ifstream f1, f2, fin;

    int choice;

    do {
        cout<<"\n--- MERGE MENU ---";
        cout<<"\n1.Add Numbers (File1)";
        cout<<"\n2.Add Alphabets (File2)";
        cout<<"\n3.Merge Files";
        cout<<"\n4.Display Merged File";
        cout<<"\n5.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice) 
        {

        case 1: 
        {
            fout.open("file1.txt", ios::app);

            int n, x;
            cout<<"How many numbers: ";
            cin>>n;
            cout<<"\nEnter numbers: ";
            for(int i=0;i<n;i++) 
            {
                cin>>x;
                fout << x << " ";
            }

            fout.close();
            break;
        }

        case 2: 
        {
            fout.open("file2.txt", ios::app);

            int n;
            string s;
            cout<<"How many alphabets: ";
            cin>>n;

            cout<<"Enter alphabets: ";
            for(int i=0;i<n;i++) 
            {
                cin>>s;
                fout << s << " ";
            }

            fout.close();
            break;
        }

        case 3: 
        {
            f1.open("file1.txt");
            f2.open("file2.txt");

            if(!f1 || !f2) 
            {
                cout<<"File not found\n";
                break;
            }

            fout.open("merge.txt");
            char ch;

            while(f1.get(ch))
                fout.put(ch);

            while(f2.get(ch))
                fout.put(ch);

            f1.close();
            f2.close();
            fout.close();

            cout<<"Merged successfully\n";
            break;
        }

        case 4: 
        {
            fin.open("merge.txt");

            if(!fin) 
            {
                cout<<"No merged file\n";
                break;
            }

            char ch;

            cout<<"\nMerged Data:\n";
            while(fin.get(ch))
                cout << ch;

            fin.close();
            break;
        }

        case 5:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}