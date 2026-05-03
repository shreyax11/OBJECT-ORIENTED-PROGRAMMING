#include<iostream>
using namespace std;
const int SIZE = 10;
class String
{
	char str[SIZE];
	int l;

	public:

		friend istream & operator >> (istream &is, String &s);
		friend ostream & operator << (ostream &os, String s);
		
		int length()
		{
			l=0;
			for(int i=0; str[i]!='\0'; i++)
				l++;
			return l;
		}

		String reverse()
		{
			String str2;
			int len= this->length();
			for(int i=0; str[i] != '\0'; i++)
			{
				str2.str[i]=str[len-i-1];
			}
			return str2;
		}

		String operator+(String s)
		{
			String temp;
			int i=0, j=0;
			while(str[i]!='\0')
			{
				temp.str[i]=str[i];
				i++;
			}
			
			while(s.str[j]!='\0')
			{
				temp.str[i]=s.str[j];
				i++;
				j++;
			}
			temp.str[i]='\0';
			return temp;
		}

		bool operator ==(String s)
		{
			int i=0;
			while(str[i] != '\0' && s.str[i] != '\0')
			{
				if(str[i] != s.str[i])
					return false;
				i++;
			}
			if(str[i]=='\0' && s.str[i] =='\0')
				return true;
			else 
				return false;
		}

		bool operator >(String s)
		{
			int i=0;
			for(i=0; str[i] != '\0' && s.str[i]!='\0';i++)
			{
				if(str[i]>s.str[i])
					return true;
				return false;
			}
			return false;
		}
		
};
istream & operator >> (istream &is, String &s)
{
	cout<<"enter the string:";
	is>>s.str;
	return is;
}
ostream & operator << (ostream &os, String s)
{
	cout<<"the string is :\n";
	os<<s.str;
	return os;
}
int main()
{
	int length,ch;
	String s1,s2,s3;
	do
	{
		cout<<"\n\n--STRING MENU--\n";
		cout<<"1.String length\n2.String reverse\n3.String concatination\n4.Compare string\n5.Exit\n";
		cout<<"Enter your choice:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
                //cout<<"enter the string:";
				cin>>s1;
				length=s1.length();
				cout<<"the length of string is "<<length<<endl<<endl;
				break;
			case 2:
                //cout<<"enter the string:";
                cin>>s1;
				s2=s1.reverse();
				cout<<"After reverse:\n";
				cout<<s2;
				cout<<endl;
				break;
			case 3:
                //cout<<"enter the string 01 : ";
				cin>>s1;
				//cout<<"enter the string 02 : ";
				cin>>s2;
				int len1 , len2;
				len1=s1.length();
				len2=s2.length();
				if((len1+len2)<SIZE)
				{
					s3=s1+s2;
					cout<<"after concatination:\n";
					cout<<s3;
				}
				else
					cout<<"Concatination is not possible\n";
				break;
			case 4:
                //cout<<"enter the string 01 : ";
				cin>>s1;
				cout<<s1<<endl;
                //cout<<"enter the string 02 : ";
				cin>>s2;
				cout<<s2<<endl;
				//int len1 , len2;
				len1=s1.length();
				len2=s2.length();
				cout<<"\nComparing the string 01 and string 02 :\n";
				if(s1==s2)
				{	
					cout<<"Both strings are equal\n";
					cout<<"The length is "<<len1<<endl;
				}
				else if(s1> s2)
					cout<<s1<<" is greater"<<endl;
				else 
					cout<<s2<<" is greater"<<endl;
				break;
			default:
				cout<<"Invalid choice..";	
		}
	}while(1);
	return 0;
}
