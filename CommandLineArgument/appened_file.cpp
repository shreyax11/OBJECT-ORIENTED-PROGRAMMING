#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 3)
    {
        char c;
        ifstream fin;
        ofstream fout;

        cout<<"The name of the command : "<<argv[0]<<endl;
        cout<<"Number of arguments: "<<argc<<endl;
        cout<<"The first argument: "<<argv[1]<<endl;
        cout<<"The second argument: "<<argv[2]<<endl;

        string file1 = argv[1];
        string file2 = argv[2];

        fin.open(file1);
        fout.open(file2, ios::app);  // append mode

        if(!fin)
        {
            cout<<"File does not exist"<<endl;
            exit(0);
        }
        else
        {
            while(fin.get(c))
            {
                fout.put(c);
            }

            fin.close();
            fout.close();

            cout<<"Appended successfully"<<endl;
        }
    }
    else
    {
        cout<<"ERROR\n";
        exit(0);
    }
    return 0;
}