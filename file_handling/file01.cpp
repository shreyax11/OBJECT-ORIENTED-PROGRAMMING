#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string file1name, file2name;
    int choice;
    char ch;

    ifstream fin;
    ofstream fout;

    do
    {
        cout<<"\n---- FILE MENU ----\n";
        cout<<"1.DISPLAY FILE\n2.COPY FILE\n3.DISPLAY FILE IN REVERSE ORDER\n4.EXIT\n";
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\nEnter file name: ";
                cin>>file1name;

                fin.open(file1name);

                if(!fin)
                {
                    cout<<"ERROR....FILE CAN'T BE OPEN\n";
                    break;
                }

                while(!fin.eof())
                {
                    fin.get(ch);
                    if(!fin.eof())
                        cout<<ch;
                }

                fin.close();
                break;

            case 2:
                cout<<"\nEnter source file name: ";
                cin>>file1name;

                cout<<"Enter destination file name: ";
                cin>>file2name;

                fin.open(file1name);
                fout.open(file2name);

                if(!fin)
                {
                    cout<<"ERROR....SOURCE FILE CAN'T BE OPEN\n";
                    break;
                }

                while(!fin.eof())
                {
                    fin.get(ch);
                    //we are using if because:
                    //duplicate character was appearing like in file1 content is file1 when we copy the content in file2 
                    //it was file11 tp avoid that we use this
                    if(!fin.eof())
                        fout.put(ch);
                }

                fin.close();
                fout.close();

                cout<<"File copied successfully\n";
                break;

            case 3:
                cout<<"\nEnter file name: ";
                cin>>file1name;

                fin.open(file1name);

                if(!fin)
                {
                    cout<<"ERROR....FILE CAN'T BE OPEN\n";
                    break;
                }

                fin.seekg(0, ios::end);
                int size = fin.tellg();

                for(int i=1;i<=size;i++)
                {
                    fin.seekg(-i, ios::end);
                    fin.get(ch);
                    cout<<ch;
                }

                fin.close();
                break;

            case 4:
                cout<<"EXITING THE PROGRAM..\n";
                break;

            default:
                cout<<"INVALID CHOICE...\n";
        }

    } while(choice != 4);

    return 0;
}