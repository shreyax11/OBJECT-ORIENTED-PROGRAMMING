#include<iostream>
#include<fstream>
using namespace std;

int main() 
{
    ofstream fout("data.txt");
    char ch, choice;

    do 
    {
        cout << "Enter a line:\n";

        while(cin.get(ch)) 
        {
            fout.put(ch);
            if(ch == '\n')
                break;
        }

        cout << "Do you want to enter more? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while(choice == 'y' || choice == 'Y');

    fout.close();

    ifstream fin("data.txt");

    int chars = 0, words = 0, lines = 0;
    bool inWord = false;

    while(fin.get(ch)) 
    {

        if(ch == '\n')
            lines++;

        if(ch == ' ' || ch == '\n' || ch == '\t') 
        {
            inWord = false;
        }
        else 
        {
            chars++;
            if(!inWord) 
            {
                words++;
                inWord = true;
            }
        }
    }

    fin.close();

    cout << "\nCharacters: " << chars;
    cout << "\nWords: " << words;
    cout << "\nLines: " << lines;

    return 0;
}