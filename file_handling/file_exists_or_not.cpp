#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string fname;
    cout<<"Enter file name: ";
    getline(cin, fname);

    ifstream fin(fname);

    if(!fin)
    {
        cout<<"File does not exist\n";
        cout<<"creating....file....\n";
        
        ofstream fout(fname);

        char ch;
        cout<<"Enter content (single line):\n";

        while(cin.get(ch) && ch!='\n')
            fout<<ch;

        fout.close();

        cout<<"File created successfully\n";
    }
    else
    {
        cout<<"File exists\n";
        fin.close();
    }

    return 0;
}