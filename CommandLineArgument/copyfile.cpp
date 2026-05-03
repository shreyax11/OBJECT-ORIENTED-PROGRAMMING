#include<iostream>
#include<fstream>
using namespace std;

int  main(int argc, char* argv[])
{
	if(argc == 3)
	{
		int size,i;
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
		fout.open(file2);
		if(!fin)
		{
			cout<<"Source file does not exist"<<endl;
			exit(0);
		}
		else
		{
			fin.seekg(0,ios::beg);
			while(fin.get(c))
			{
				fout.put(c);
			}
			fin.close();
			fout.close();
			cout<<"Copied successfully"<<endl;
			fin.open(file2);
			cout<<"\nThe content of the file:"<<endl;
			while(fin.get(c))
			{
				cout<<c;		
			}
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