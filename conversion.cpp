#include <iostream>
using namespace std;

// Length Class
class Length
{
    float value;
public:
    void getData()
    {
        cout << "Enter length value: ";
        cin >> value;
    }
    void mToKm() 
    { 
        cout << "Meter to Kilometer = " << value / 1000 << endl; 
    }
    void kmToM() 
    { 
        cout << "Kilometer to Meter = " << value * 1000 << endl; 
    }
    void cmToM() 
    { 
        cout << "Centimeter to Meter = " << value / 100 << endl; 
    }
    void mToCm() 
    { 
        cout << "Meter to Centimeter = " << value * 100 << endl; 
    }
    void kmToCm() 
    { 
        cout << "Kilometer to Centimeter = " << value * 100000 << endl; 
    }
};

// Temperature Class 
class Temperature
{
    float value;

public:
    void getData()
    {
        cout << "Enter temperature value: ";
        cin >> value;
    }

    void cToF() 
    { 
        cout << "Celsius to Fahrenheit = " << (value * 9 / 5) + 32 << endl; 
    }
    void fToC() 
    { 
        cout << "Fahrenheit to Celsius = " << (value - 32) * 5 / 9 << endl; 
    }
    void cToK() 
    { 
        cout << "Celsius to Kelvin = " << value + 273.15 << endl; 
    }
    void kToC() 
    { 
        cout << "Kelvin to Celsius = " << value - 273.15 << endl; 
    }
    void fToK() 
    { 
        cout << "Fahrenheit to Kelvin = " << (value - 32) * 5 / 9 + 273.15 << endl;
    }
    void kToF() 
    { 
        cout << "Kelvin to Fahrenheit = " << (value - 273.15) * 9 / 5 + 32 << endl; 
    }
};

// Weight Class 
class Weight
{
    float value;
public:
    void getData()
    {
        cout << "Enter weight value: ";
        cin >> value;
    }

    void kgToG() 
    { 
        cout << "Kilogram to Gram = " << value * 1000 << endl; 
    }
    void gToKg() 
    { 
        cout << "Gram to Kilogram = " << value / 1000 << endl; 
    }
};
// Liquid Class 
class Liquid
{
    float value;
public:
    void getData()
    {
        cout << "Enter liquid value: ";
        cin >> value;
    }
    void lToMl() 
    { 
        cout << "Liter to Milliliter = " << value * 1000 << endl; 
    }
    void mlToL() 
    { 
        cout << "Milliliter to Liter = " << value / 1000 << endl; 
    }
};

int main()
{
    Length len;
    Temperature temp;
    Weight wt;
    Liquid liq;
    int Choice, subChoice;
    do
    {
        cout << "\n===== UNIT CONVERTER =====" << endl;
        cout << "1. Length Conversion" << endl;
        cout << "2. Temperature Conversion" << endl;
        cout << "3. Weight Conversion" << endl;
        cout << "4. Liquid Conversion" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "\n-- Length Menu --" << endl;
            cout << "1. Meter to Km\n2. Km to Meter\n3. Cm to Meter\n4. Meter to Cm\n5. Km to Cm\n";
            cout << "Enter choice: ";
            cin >> subChoice;
            len.getData();
            switch (subChoice)
            {
            case 1: 
                len.mToKm(); 
                break;
            case 2: 
                len.kmToM(); 
                break;
            case 3: 
                len.cmToM(); 
                break;
            case 4: 
                len.mToCm(); 
                break;
            case 5: 
                len.kmToCm(); 
                break;
            default: 
                cout << "Invalid choice!" << endl;
            }
            break;
        case 2:
            cout << "\n-- Temperature Menu --" << endl;
            cout << "1. C to F\n2. F to C\n3. C to K\n4. K to C\n5. F to K\n6. K to F\n";
            cout << "Enter choice: ";
            cin >> subChoice;
            temp.getData();
            switch (subChoice)
            {
            case 1: 
                temp.cToF(); 
                break;
            case 2: 
                temp.fToC(); 
                break;
            case 3: 
                temp.cToK(); 
                break;
            case 4: 
                temp.kToC(); 
                break;
            case 5: 
                temp.fToK(); 
                break;
            case 6: 
                temp.kToF(); 
                break;
            default: 
                cout << "Invalid choice!" << endl;
            }
            break;
        case 3:
            cout << "\n-- Weight Menu --" << endl;
            cout << "1. Kg to Gram\n2. Gram to Kg\n";
            cout << "Enter choice: ";
            cin >> subChoice;
            wt.getData();
            switch (subChoice)
            {
            case 1: 
                wt.kgToG(); 
                break;
            case 2: 
                wt.gToKg(); 
                break;
            default: 
                cout << "Invalid choice!" << endl;
            }
            break;
        case 4:
            cout << "\n-- Liquid Menu --" << endl;
            cout << "1. Liter to Ml  \n2. Ml to Liter\n";
            cout << "Enter choice: ";
            cin >> subChoice;
            liq.getData();
            switch (subChoice)
            {
            case 1: 
                liq.lToMl(); 
                break;
            case 2: 
                liq.mlToL(); 
                break;
            default: 
                cout << "Invalid choice!" << endl;
            }
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (Choice != 5);
    return 0;
}
