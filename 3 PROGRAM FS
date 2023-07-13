#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include<cstdio>

using namespace std;

class Student
{
public:
    char name[10];
    char usn[10];
    char age[5];
    char sem[5];
    char branch[5];
    char buffer[100];
};

fstream file;
Student s;

void writeRecord()
{
    file.open("program_3.txt", ios::app);
    if (!file)
    {
        cout << "Cannot open the file in append mode";
        exit(1);
    }

    cout << "\nEnter the student name: ";
    cin >> s.name;
    cout << "Enter the USN: ";
    cin >> s.usn;
    cout << "Enter the age: ";
    cin >> s.age;
    cout << "Enter the sem: ";
    cin >> s.sem;
    cout << "Enter the branch: ";
    cin >> s.branch;

    strcpy(s.buffer, s.name);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.usn);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.age);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.sem);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.branch);
    strcat(s.buffer, "\n");
    file << s.buffer;
    file.close();
}

void search()
{
    char usn[10];
    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\nUnable to open the file in read mode";
        exit(0);
    }

    cout << "\nEnter the record's USN you want to search: ";
    cin >> usn;

    while (!file.eof())
    {
        file.getline(s.name, 15, '|');
        file.getline(s.usn, 15, '|');
        file.getline(s.age, 5, '|');
        file.getline(s.sem, 5, '|');
        file.getline(s.branch, 5, '\n');

        if (strcmp(s.usn, usn) == 0)
        {
            cout << "\nRecord found";
            cout << "\nname\tusn\tage\tsem\tbranch";
            cout << "\n" << s.name << "\t" << s.usn << "\t";
            cout << s.age << "\t" << s.sem << "\t" << s.branch;
            file.close();
            getchar();
            return;
        }
    }

    cout << "\nRecord not found";
    file.close();
    getchar();
    return;
}

void displayFile()
{
    int i;
    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\ncannot open the file in read mode";
        getchar();
        exit(1);
    }

    i = 0;
    printf("\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH\n");
    while (!file.eof())
    {
        file.getline(s.name, 15, '|');
        file.getline(s.usn, 15, '|');
        file.getline(s.age, 5, '|');
        file.getline(s.sem, 5, '|');
        file.getline(s.branch, 5, '\n');
        printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s", s.name, s.usn, s.age, s.sem, s.branch);
        i++;
    }

    file.close();
    getchar();
}

void modify()
{
    char usn[10];
    int i;
    Student s[100];

    file.open("program_3.txt", ios::in);
    if (!file)
    {
        cout << "\nUnable to open the file in input mode";
        exit(1);
    }

    cout << "\nEnter the USN: ";
    cin >> usn;

    i = 0;
    while (!file.eof())
    {
        file.getline(s[i].name, 15, '|');
        file.getline(s[i].usn, 15, '|');
        file.getline(s[i].age, 5, '|');
        file.getline(s[i].sem, 5, '|');
        file.getline(s[i].branch, 5, '\n');
        i++;
    }
    i--;

    for (int j = 0; j < i; j++)
    {
        if (strcmp(usn, s[j].usn) == 0)
        {
            cout << "\nThe old values of the record with USN " << usn << " are:";
            cout << "\nName: " << s[j].name;
            cout << "\nUSN: " << s[j].usn;
            cout << "\nAge: " << s[j].age;
            cout << "\nSem: " << s[j].sem;
            cout << "\nBranch: " << s[j].branch;
            cout << "\nEnter the new values:";
            cout << "\nName: ";
            cin >> s[j].name;
            cout << "USN: ";
            cin >> s[j].usn;
            cout << "Age: ";
            cin >> s[j].age;
            cout << "Sem: ";
            cin >> s[j].sem;
            cout << "Branch: ";
            cin >> s[j].branch;
            break;
        }
    }

    if (i == 0)
    {
        cout << "\nThe record with USN " << usn << " is not present";
        getchar();
        return;
    }

    file.close();

    file.open("program_3.txt", ios::out);
    if (!file)
    {
        cout << "\nUnable to open the file in output mode";
        getchar();
        return;
    }

    for (int j = 0; j < i; j++)
    {
        file << s[j].name << '|' << s[j].usn << '|' << s[j].age
             << '|' << s[j].sem << '|' << s[j].branch << '\n';
    }

    file.close();
}

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "\n0: Exit";
        cout << "\n1: Write to file";
        cout << "\n2: Display the file";
        cout << "\n3: Modify the file";
        cout << "\n4: Search";
        cout << "\n\nEnter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            writeRecord();
            break;
        case 2:
            displayFile();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 0:
            exit(0);
        default:
            cout << "\nInvalid input...";
            break;
        }
    }

    return 0;
}
