#include <fstream>
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int main()
{
    char name[10][20];
    char temp[20];
    char ifilename[15], ofilename[15];
    int num, i;
//    clrscr();
    cout << "Enter how many names you want to enter" << endl;
    cin >> num;
    cout << "Enter the names" << endl;
    for (i = 0; i < num; i++)
        cin >> name[i];
    cout << "Names in reverse order" << endl;
    for (i = num - 1; i >= 0; i--)
        cout << strrev(name[i]) << endl;
    cout << "Enter the input file name which contains a list of names" << endl;
    cin >> ifilename;
    cout << "Enter the output file name where the reversed list of names has to be written" << endl;
    cin >> ofilename;
    ifstream infile(ifilename);
    ofstream outfile(ofilename);
    if (!infile)
    {
        cout << "Could not open the specified input file" << endl;
        getch();
        exit(0);
    }
    while (infile.getline(temp, 20, '\n'))
    {
        outfile << strrev(temp) << endl;
    }
    outfile.close();
    infile.close();
    cout << "Output written to file " << ofilename << endl;
    getch();
    return 0;
}
