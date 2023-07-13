#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    string usn;
    string age;
    string sem;
    string branch;
    string buffer;
};

void writeRecord()
{
    ofstream file;
    Student s;
    int k, n;
    file.open("program_4.txt", ios::app);
    if (!file)
    {
        cout << "\nCannot open the file in append mode\n";
        exit(0);
    }
    cout << "How many records: ";
    cin >> n;
    for (k = 0; k < n; k++)
    {
        cout << "\nEnter the student name: ";
        cin >> s.name;
        cout << "Enter the usn: ";
        cin >> s.usn;
        cout << "Enter the age: ";
        cin >> s.age;
        cout << "Enter the sem: ";
        cin >> s.sem;
        cout << "Enter the branch: ";
        cin >> s.branch;
        file << k << "|" << s.name << "|" << s.usn << "|"
             << s.age << "|" << s.sem << "|" << s.branch << "\n";
    }
    file.close();
}

void displayFile()
{
    ifstream file;
    Student s;
    string rrn;
    file.open("program_4.txt");
    if (!file)
    {
        cout << "\nCannot open the file in input mode\n";
        exit(1);
    }
    cout << "\nRRN\tName\t\tUSN\t\tAge\t\tSem\t\tBranch\n";
    while (getline(file, s.buffer))
    {
        sscanf(s.buffer.c_str(), "%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]",
               &s.name[0], &s.usn[0], &s.age[0], &s.sem[0], &s.branch[0]);
        cout << s.buffer << endl;
    }
    file.close();
}

void search()
{
    ifstream file;
    Student s;
    string rrn;
    string rrn1;
    int i = 0;
    Student std[100];
    cout << "\nEnter the RRN to be searched: ";
    cin >> rrn;
    file.open("program_4.txt");
    if (!file)
    {
        cout << "\nCannot open the file in input mode";
        exit(0);
    }
    cout << "\nRRN\tName\t\tUSN\t\tAge\t\tSem\t\tBranch\n";
    while (getline(file, s.buffer, '|'))
    {
        rrn1 = s.buffer;
        getline(file, s.name, '|');
        getline(file, s.usn, '|');
        getline(file, s.age, '|');
        getline(file, s.sem, '|');
        getline(file, s.branch, '\n');
        if (rrn == rrn1)
        {
            cout << rrn1 << "|" << s.name << "|" << s.usn << "|"
                 << s.age << "|" << s.sem << "|" << s.branch << endl;
            cout << "\nRecord found\n";
            file.close();
            return;
        }
    }
    cout << "\nRecord not found\n";
    file.close();
}

int main()
{
    int choice;
    while (1)
    {
        cout << "\n0: Exit";
        cout << "\n1: Insert";
        cout << "\n2: Search";
        cout << "\n3: Display";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            writeRecord();
            break;
        case 2:
            search();
            break;
        case 3:
            displayFile();
            break;
        case 0:
            exit(0);
        default:
            cout << "\nInvalid option";
            break;
        }
    }
    return 0;
}
