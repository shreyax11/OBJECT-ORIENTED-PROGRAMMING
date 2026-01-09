#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

class student
{
	int roll;
	char name[20];
	int maths, physics, chemistry;
	public:
		void print_line(char ch,int n)
		{
			for(int i = 0; i < n; i++)
				cout<<ch;
			cout<<endl;
		}
		void get_data()
		{
			cout<<"Enter the Roll.no: ";
			cin>>roll;
			cout<<"Enter the name: ";
			cin>>name;
			cout<<"Enter the marks out of 100"<<endl;
			cout<<"maths: ";
			cin>>maths;
			cout<<"physics: ";
			cin>>physics;
			cout<<"chemistry: ";
			cin>>chemistry;
		}
		int total()
		{
			return maths+physics+chemistry;
		}
		int avg()
		{
			int a;
			a = total();
			return a/3;
		}
		int percentage()
		{
			int a,b;
			a = total();
			b = (a*100)/300;
			return b;
		}
		/*string result()
    	{// Pass if marks in each subject >=35
        	if(maths >= 35 && physics >= 35 && chemistry >= 35)
        	    return "PASS";
        	else
        	    return "FAIL";
    	}*/
		void display_report()
		{
			print_line('=',70);
			cout<<setw(40)<<"REPORT CARD"<<endl;
			print_line('=',70);
			cout<<"Roll.No: "<<roll<<endl;
			cout<<"Name of student: "<<name<<endl;
			print_line('-',70);
			cout<<setw(6)<<"S.No"<<setw(15)<<"Subject"<<setw(20)<<"Max Marks"<<setw(20)<<"Obtained Marks"<<endl;
			print_line('-',70);
			cout<<setw(6)<<1<<setw(15)<<"Maths"<<setw(20)<<100<<setw(20)<<maths<<endl;
			cout<<setw(6)<<2<<setw(15)<<"Physics"<<setw(20)<<100<<setw(20)<<physics<<endl;
			cout<<setw(6)<<3<<setw(15)<<"Chemistry"<<setw(20)<<100<<setw(20)<<chemistry<<endl;
			print_line('-',70);
			cout<<"Total Marks: "<<total()<<endl;
			cout<<"Average Marks: "<<avg()<<endl;
			cout<<"Percentage: "<<percentage()<<"%"<<endl;
			//cout<<"Result: "<<result()<<endl; 
			print_line('=',70);
		}
};

int main()
{
	int n;
	cout<<"Enter the number of students:";
	cin>>n;
	student s[n];
	int ch,count=0;
	do
	{
		cout<<"*--MENU--*"<<endl;
		cout<<"1.Enter student details\n2.print report card\n3.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				while(count<n)
				{
					s[count].get_data();
					count++;
				}
				if(count > n)
					cout<<"\n Maximum "<<n<<" student allowed"<<endl;
				break;
			case 2:
				if(count == 0)
					cout<<"\n No student data available"<<endl;
				else
				{
					for(int i = 0; i<count;i++)
					{
						system("CLS");
						s[i].display_report();
						cout<<"Press any button to continue"<<endl;
						getch();
					}
				}
				break;
			case 3:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(1);
	return 0;
}
