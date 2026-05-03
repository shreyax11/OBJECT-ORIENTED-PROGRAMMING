#include <iostream>
#include <fstream>
using namespace std;

class File {
    string fname;
    ifstream fin;
    ofstream fout;
    fstream f;

public:

    void getFileName() {
        cout << "Enter file name: ";
        getline(cin, fname);
    }

    // write using put()
    void write() {
        fout.open(fname);

        string s;
        cout << "Enter text: ";
        getline(cin, s);

        for (int i = 0; i < s.length(); i++) {
            fout.put(s[i]);
        }

        fout.close();
    }

    void append() {
        fout.open(fname, ios::app);

        string s;
        cout << "Enter text to append: ";
        getline(cin, s);

        fout.put('\n');
        for (int i = 0; i < s.length(); i++) {
            fout.put(s[i]);
        }

        fout.close();
    }

    void read() {
        fin.open(fname);

        if (!fin) {
            cout << "File not found!\n";
            return;
        }

        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }

        fin.close();
    }

    void position() {
        f.open(fname);

        cout << "tellg = " << f.tellg() << endl;
        cout << "tellp = " << f.tellp() << endl;

        f.close();
    }

    void move() {
        f.open(fname);

        int g, p;
        cout << "Enter seekg: ";
        cin >> g;

        cout << "Enter seekp: ";
        cin >> p;

        f.seekg(g);
        f.seekp(p);

        cout << "tellg = " << f.tellg() << endl;
        cout << "tellp = " << f.tellp() << endl;

        f.close();
    }
};

int main() {
    File obj;
    int ch;

    obj.getFileName();

    do {
        cout << "\n1.Write\n2.Append\n3.Read\n4.Position\n5.Move\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        cin.ignore();   

        switch (ch) {
            case 1: obj.write(); break;
            case 2: obj.append(); break;
            case 3: obj.read(); break;
            case 4: obj.position(); break;
            case 5: obj.move(); break;
        }

    } while (ch != 0);

    return 0;
}