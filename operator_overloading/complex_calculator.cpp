#include<iostream>
using namespace std;

class Complex
{
    float real, imag;

public:
    Complex(int r=0, int i=0)
    {
        real = r;
        imag = i;
    }

    // >> operator overloading
    friend istream& operator>>(istream &in, Complex &c)
    {
        cout<<"Enter real part: ";
        in>>c.real;
        cout<<"Enter imaginary part: ";
        in>>c.imag;
        return in;
    }

    // << operator overloading
    friend ostream& operator<<(ostream &out, Complex &c)
    {
        if(c.imag < 0)
            out<<c.real<<" "<<c.imag<<"i";
        else
            out<<c.real<<" + "<<c.imag<<"i";
        return out;
    }

    Complex operator+(Complex b)
    {
        return Complex(real + b.real, imag + b.imag);
    }

    Complex operator-(Complex b)
    {
        return Complex(real - b.real, imag - b.imag);
    }

    Complex operator*(Complex b)
    {
        return Complex((real*b.real)-(imag*b.imag),
                       (real*b.imag)+(imag*b.real));
    }

    Complex operator/(Complex b)
    {
        float d = (b.real*b.real)+(b.imag*b.imag);
        float r = ((real*b.real)+(imag*b.imag))/d;
        float i = ((imag*b.real)-(real*b.imag))/d;
        return Complex(r,i);
    }

    Complex conjugate()
    {
        return Complex(real,-imag);
    }
};

int main()
{
    Complex C1,C2,result;
    int option;

    cout<<"Complex 1:\n";
    cin>>C1;

    cout<<"Complex 2:\n";
    cin>>C2;

    do
    {
        cout<<"\n****COMPLEX MENU****\n";
        cout<<"1.Addition\n";
        cout<<"2.Subtraction\n";
        cout<<"3.Multiplication\n";
        cout<<"4.Division\n";
        cout<<"5.Conjugate\n";
        cout<<"6.Exit\n";

        cout<<"Enter your choice: ";
        cin>>option;

        switch(option)
        {
            case 1:
                result = C1 + C2;
                cout<<"SUM:\n"<<result<<endl;
                break;

            case 2:
                result = C1 - C2;
                cout<<"DIFFERENCE:\n"<<result<<endl;
                break;

            case 3:
                result = C1 * C2;
                cout<<"PRODUCT:\n"<<result<<endl;
                break;

            case 4:
                result = C1 / C2;
                cout<<"QUOTIENT:\n"<<result<<endl;
                break;

            case 5:
                result = C1.conjugate();
                cout<<"Conjugate: "<<result<<endl;
                break;

            case 6:
                exit(0);

            default:
                cout<<"Invalid option\n";
        }

    }while(1);

    return 0;
}