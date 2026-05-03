#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        char c;
        int count = 0;
        ifstream fin;

        cout<<"The name of the command : "<<argv[0]<<endl;
        cout<<"Number of arguments: "<<argc<<endl;
        cout<<"The argument: "<<argv[1]<<endl;

        string file = argv[1];
        fin.open(file);

        if(!fin)
        {
            cout<<"File does not exist"<<endl;
            exit(0);
        }
        else
        {
            while(fin.get(c))
            {
                count++;
            }
            cout<<"Total characters = "<<count<<endl;
            fin.close();
        }
    }
    else
    {
        cout<<"ERROR\n";
        exit(0);
    }
    return 0;
}