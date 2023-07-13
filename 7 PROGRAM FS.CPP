#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void writeLists()
{
    ofstream out1, out2;
    int m, n;
    char name[20];

    out1.open("file1.txt", ios::out);
    out2.open("file2.txt", ios::out);

    if (!out1 || !out2)
    {
        cout << "Unable to open one of the list files\n";
        return;
    }

    cout << "Enter the number of names you want to enter in file1: ";
    cin >> m;

    cout << "\nEnter the names in ascending order:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        out1 << name << '\n';
    }

    cout << "\nEnter the number of names you want to enter in file2: ";
    cin >> n;

    cout << "\nEnter the names in ascending order:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        out2 << name << '\n';
    }

    out1.close();
    out2.close();
}

int main()
{
    char list1[100][20];
    char list2[100][20];
    int m, n;

    writeLists();

    ifstream in1("file1.txt");
    ifstream in2("file2.txt");
    ofstream out3("file3.txt");

    if (!in1 || !in2 || !out3)
    {
        cout << "Unable to open one of the files\n";
        return 0;
    }

    cout << "\nLIST-1 CONTENTS\n";
    m = 0;
    while (in1.getline(list1[m], 20, '\n'))
    {
        cout << list1[m] << '\n';
        m++;
    }

    cout << "\nLIST-2 CONTENTS\n";
    n = 0;
    while (in2.getline(list2[n], 20, '\n'))
    {
        cout << list2[n] << '\n';
        n++;
    }

    m--;
    n--;

    cout << "\nElements common to both files are:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(list1[i], list2[j]) == 0)
            {
                out3 << list1[i] << '\n';
                cout << list1[i] << '\n';
            }
        }
    }

    in1.close();
    in2.close();
    out3.close();

    return 0;
}
