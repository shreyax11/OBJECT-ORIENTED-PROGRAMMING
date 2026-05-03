#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 3)
    {
        char c1, c2;
        ifstream fin1, fin2;

        cout<<"The name of the command : "<<argv[0]<<endl;
        cout<<"Number of arguments: "<<argc<<endl;
        cout<<"The first argument: "<<argv[1]<<endl;
        cout<<"The second argument: "<<argv[2]<<endl;

        string file1 = argv[1];
        string file2 = argv[2];

        fin1.open(file1);
        fin2.open(file2);
        
        if(!fin1 || !fin2)
        {
            cout<<"File does not exist"<<endl;
            exit(0);
        }
        else
        {
            while(fin1.get(c1) && fin2.get(c2))
            {
                if(c1 != c2)
                {
                    cout<<"Files are NOT same"<<endl;
                    exit(0);
                }
            }
            cout<<"Files are same"<<endl;
            fin1.close();
            fin2.close();
        }
    }
    else
    {
        cout<<"ERROR\n";
        exit(0);
    }
    return 0;
}