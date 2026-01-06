#include <iostream>
using namespace std;

class Area
{
public:
    void circle(float r)
    {
        cout << "Area of Circle = " << 3.14 * r * r << endl;
    }

    void rectangle(float l, float b)
    {
        cout << "Area of Rectangle = " << l * b << endl;
    }

    void triangle(float b, float h)
    {
        cout << "Area of Triangle = " << 0.5 * b * h << endl;
    }
};

int main()
{
    Area a;
    int ch;
    cout << "1.Circle \n2.Rectangle \n3.Triangle\n";
    cout << "Enter choice: ";
    cin >> ch;
    if (ch == 1)
    {
        float r;
        cin >> r;
        a.circle(r);
    }
    else if (ch == 2)
    {
        float l, b;
        cin >> l >> b;
        a.rectangle(l, b);
    }
    else if (ch == 3)
    {
        float b, h;
        cin >> b >> h;
        a.triangle(b, h);
    }
    return 0;
}
