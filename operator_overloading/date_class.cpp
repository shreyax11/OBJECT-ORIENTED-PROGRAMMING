
#include<iostream>
using namespace std;

class Date
{
	int d,m,y;
	public:
		Date()
		{
			d = 1;
			m = 1;
			y = 2000;
		}	
		void getdata();
		void showdata();
		void showdata(int ch);
		int days_month();
		bool is_leap_year();
		void date_format();
		string monthname();
		Date operator ++();
		Date operator ++(int);	
		Date operator --();
		Date operator --(int);	
};
void Date::getdata()
{
	cout<<"\nFORMAT: DD-MM-YYYY";
	cout<<"\nEnter date:";
	cin>>d;
	cout<<"\nEnter month:";
	cin>>m;
	cout<<"\nEnter year:";
	cin>>y;
	if(d<1 || d>days_month() || m<1 || m>12)
	{
		cout<<"\nInvalid date."<<endl;
		cout<<"\nSet default date."<<endl;
		d = 1;
		m = 1;
		y = 2000;
	}
	
}
void Date::showdata()
{
	cout<<"\nDATE: "<<d<<"-"<<m<<"-"<<y<<endl;
}
void Date::showdata(int ch)
{
	cout<<"\nDATE: "<<d<<"-"<<monthname()<<"-"<<y<<endl;
}
int Date::days_month()
{
	if(m == 1 ||m == 3 ||m == 5 ||m == 7 ||m == 8 ||m == 10 ||m == 12)
		return 31;
	else if(m == 2)
	{
		if(is_leap_year())
			return 29;
		else
			return 28;
	}
	else
		return 30;
}
bool Date::is_leap_year()
{
	if(y%400 == 0 || (y%100!=0 && y%4==0))
		return true;
	return false;
}
void Date::date_format()
{
	int ch;
	cout<<"\nSelect the format"<<endl;
	cout<<"\n1.DD-MM-YYYY\n2.DD-MONTH-YYYY"<<endl;
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			showdata();
			break;
		case 2:
			showdata(ch);
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
	}
}
string Date::monthname()
{
	string month[] = {"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEPT","OCT","NOV","DEC"};
	return month[m];
}
Date Date::operator ++()
{
	d++;
	if(d>days_month())
	{
		m++;
		d = 1;
		if(m>12)
		{
			y++;
			m = 1;
		}
	}
	return *this;
}
Date Date::operator ++(int)
{
	Date d1;
	d1 = *this;
	d++;
	if(d>days_month())
	{
		m++;
		d = 1;
		if(m>12)
		{
			y++;
			m = 1;
		}
	}
	return d1;
}
Date Date::operator --()
{
	d--;
	if(d<1)
	{
		m--;
		d = days_month();
		if(m<1)
		{
			y--;
			m = 12;
		}
	}
	return *this;
}
Date Date::operator --(int)
{
	Date d1;
	d1 = *this;
	d--;
	if(d<1)
	{
		m--;
		d = days_month();
		if(m<1)
		{
			y--;
			m = 12;
		}
	}
	return d1;
}

int main()
{
	Date d1,d2;
	int ch,c;
	do
	{
		cout<<"\n*--MENU--*"<<endl;
		cout<<"\n1.Enter date\n2.Display date\n3.Increase date\n4.Decrease date\n5.Days in a month\n6.Is leap year\n7.Exit"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				d1.getdata();
				break;
			case 2:
				d1.date_format();
				break;
			case 3:
				cout<<"\n1.Pre increment\n2.Post increment"<<endl;
				cout<<"Enter your choice:";
				cin>>c;
				switch(c)
				{
					case 1:
						d2 = ++d1;
						break;
					case 2:
						d2 = d1++;
						break;
					default:
						cout<<"Invalid choice";
				}
				cout<<"\nLeft date: ";
				d2.showdata(ch);
				cout<<"\nRight date: ";
				d1.showdata(ch);
				break;
			case 4:
				cout<<"\n1.Pre decrement\n2.Post decrement"<<endl;
				cout<<"Enter your choice:";
				cin>>c;
				switch(c){
					case 1:
						d2 = --d1;
						break;
					case 2:
						d2 = d1--;
						break;
					default:
						cout<<"Invalid choice";
				}
				cout<<"\nLeft date: ";
				d2.showdata(ch);
				cout<<"\nRight date: ";
				d1.showdata(ch);
				break;
			case 5:
				cout<<"\nThis month has "<<d1.days_month()<<" days"<<endl;
				break;
			case 6:
				if(d1.is_leap_year())
					cout<<"\nThis is a leap year"<<endl;
				else
					cout<<"\nThis is not a leap year"<<endl;
				break;
			case 7:
				exit(0);
			default:
				cout<<"\nInvalid choice"<<endl;
		}
	}while(1);
	return 0;
}
