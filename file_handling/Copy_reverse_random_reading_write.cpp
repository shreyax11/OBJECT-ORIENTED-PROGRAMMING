#include <iostream>
#include <fstream>
using namespace std;

class File 
{
    ifstream fin;
    ofstream fout;

public:

    string getFileName() 
    {
        string name;
        cout<<"Enter file name: ";
        getline(cin, name);
        return name;
    }

    void copy() 
    {
        cout << "File 1 (Source):\n";
        string f1 = getFileName();

        cout << "File 2 (Destination):\n";
        string f2 = getFileName();

        fin.open(f1);
        fout.open(f2);

        if (!fin) 
        {
            cout << "Source file not found!\n";
            return;
        }

        char ch;
        while (fin.get(ch)) 
        {
            fout.put(ch);
        }

        cout << "File copied successfully!\n";

        fin.close();
        fout.close();
    }

    void display() 
    {
        cout << "Display File:\n";
        string fname = getFileName();

        fin.open(fname);

        if (!fin) 
        {
            cout << "File not found!\n";
            return;
        }

        char ch;
        while (fin.get(ch)) 
        {
            cout << ch;
        }

        fin.close();
    }

    void reverse() 
    {
        cout << "Reverse File:\n";
        string fname = getFileName();

        fin.open(fname);

        if (!fin) 
        {
            cout << "File not found!\n";
            return;
        }

        fin.seekg(0, ios::end);
        int pos = fin.tellg();
        char ch;
        for (int i = pos - 1; i >= 0; i--) 
        {
            fin.seekg(i);
            fin.get(ch);
            cout << ch;
        }

        fin.close();
    }

    // random read
    void randomRead()
    {
        cout << "Random Read:\n";
        string fname = getFileName();

        fin.open(fname);

        if (!fin)
        {
            cout << "File not found!\n";
            return;
        }

        fin.seekg(0, ios::end);
        int last = fin.tellg();

        cout << "Last position = " << last << endl;

        int pos;
        cout << "Enter position: ";
        cin >> pos;

        if (pos >= last)
        {
            cout << "Invalid position!\n";
            fin.close();
            return;
        }

        fin.seekg(pos);

        char ch;
        cout << "Data from position:\n";

        while(fin.get(ch))
            cout << ch;

        fin.close();
    }

    // random write
    void randomWrite()
{
    cout << "Random Write:\nEnter file name: ";
    string fname = getFileName();

    fstream f;
    f.open(fname, ios::in | ios::out);

    if (!f)
    {
        cout << "File not found!\n";
        return;
    }

    f.seekp(0, ios::end);
    int last = f.tellp();

    cout << "Last position = " << last << endl;

    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos > last)
    {
        cout << "Invalid position!\n";
        f.close();
        return;
    }

    f.seekp(pos);

    char ch;
    cout << "Enter content (press Enter to stop):\n";

    cin.get();  
    while(cin.get(ch) && ch!='\n')
        f.put(ch);

    cout << "Written successfully!\n";

    f.close();
}
};

int main() {
    File obj;
    int ch;

    do {
        cout << "\n1.Copy\n2.Display\n3.Reverse\n4.Random Read\n5.Random Write\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
            case 1: obj.copy(); break;
            case 2: obj.display(); break;
            case 3: obj.reverse(); break;
            case 4: obj.randomRead(); break;
            case 5: obj.randomWrite(); break;
        }

    } while (ch != 0);

    return 0;
}