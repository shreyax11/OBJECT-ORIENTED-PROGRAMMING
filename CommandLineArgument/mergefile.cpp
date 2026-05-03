#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 4)
    {
        char c;
        ifstream fin1, fin2;
        ofstream fout;

        cout<<"The name of the command : "<<argv[0]<<endl;
        cout<<"Number of arguments: "<<argc<<endl;
        cout<<"The first argument: "<<argv[1]<<endl;
        cout<<"The second argument: "<<argv[2]<<endl;
        cout<<"The third argument: "<<argv[3]<<endl;

        string file1 = argv[1];
        string file2 = argv[2];
        string file3 = argv[3];

        fin1.open(file1);
        fin2.open(file2);
        fout.open(file3);

        if(!fin1 || !fin2)
        {
            cout<<"Source file does not exist"<<endl;
            exit(0);
        }
        else
        {
            fin1.seekg(0, ios::beg);
            while(fin1.get(c))
            {
                fout.put(c);
            }
            fin2.seekg(0, ios::beg);
            while(fin2.get(c))
            {
                fout.put(c);
            }
            fin1.close();
            fin2.close();
            fout.close();
            cout<<"Merged successfully"<<endl;
            fin1.open(file3);
            cout<<"\nThe content of the file:"<<endl;
            while(fin1.get(c))
            {
                cout<<c;
            }
            fin1.close();
        }
    }
    else
    {
        cout<<"ERROR\n";
        exit(0);
    }

    return 0;
}