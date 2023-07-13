#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
public:
    char name[10];
    char usn[10];
    char age[5];
    char sem[5];
    char branch[5];
    char buffer[45];
};

fstream file;
Student s;

void writeRecord()
{
    file.open("student.txt", ios::app);
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

    // Packing the information
    strcpy(s.buffer, s.name);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.usn);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.age);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.sem);
    strcat(s.buffer, "|");
    strcat(s.buffer, s.branch);

    int count = strlen(s.buffer);
    for (int k = 0; k < 45 - count; k++)
        strcat(s.buffer, "!");

    strcat(s.buffer, "\n");
    file << s.buffer; // Writing the packed information to the buffer
    file.close();
}

void search()
{
    char usn[10];
    char extra[45];
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "Unable to open the file in read mode";
        exit(0);
    }

    cout << "\nEnter the record's USN you want to search: ";
    cin >> usn;

    // Unpacking the record
    while (!file.eof())
    {
        file.getline(s.name, 10, '|');
        file.getline(s.usn, 10, '|');
        file.getline(s.age, 5, '|');
        file.getline(s.sem, 5, '|');
        file.getline(s.branch, 5, '!');
        file.getline(extra, 45, '\n');

        if (strcmp(s.usn, usn) == 0)
        {
            cout << "\nRecord found";
            cout << "\n" << s.name << "\t" << s.usn << "\t";
            cout << s.age << "\t" << s.sem << "\t" << s.branch;
            file.close();
            return;
        }
    }

    cout << "\nRecord not found";
    file.close();
}

void displayFile()
{
    char extra[45];
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\nCannot open the file in read mode";
        exit(1);
    }

    cout << "\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH";
    cout << "\n----\t\t---\t\t---\t\t---\t\t------";

    while (!file.eof())
    {
        file.getline(s.name, 10, '|');
        file.getline(s.usn, 10, '|');
        file.getline(s.age, 5, '|');
        file.getline(s.sem, 5, '|');
        file.getline(s.branch, 5, '!');
        file.getline(extra, 45, '\n');
        printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s", s.name, s.usn, s.age, s.sem, s.branch);
    }

    file.close();
}

void modify()
{
    char usn[10];
    char buffer[45];
    char extra[45];
    int i, j;
    Student s[20];

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "\nUnable to open the file in input mode";
        exit(1);
    }

    cout << "\nEnter the USN of the record to be modified: ";
    cin >> usn;
    cout << "\n";

    i = 0;
    while (!file.eof())
    {
        file.getline(s[i].name, 10, '|');
        file.getline(s[i].usn, 10, '|');
        file.getline(s[i].age, 5, '|');
        file.getline(s[i].sem, 5, '|');
        file.getline(s[i].branch, 5, '!');
        file.getline(extra, 45, '\n');
        i++;
    }

    i--;
    for (j = 0; j < i; j++)
    {
        if (strcmp(usn, s[j].usn) == 0)
        {
            cout << "The old values of the record with USN " << usn << " are:";
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

    if (j == i)
    {
        cout << "\nThe record with USN " << usn << " is not present";
        return;
    }

    file.close();
    file.open("student.txt", ios::out);
    if (!file)
    {
        cout << "\nUnable to open the file in output mode";
        return;
    }

    for (j = 0; j < i; j++)
    {
        strcpy(buffer, s[j].name);
        strcat(buffer, "|");
        strcat(buffer, s[j].usn);
        strcat(buffer, "|");
        strcat(buffer, s[j].age);
        strcat(buffer, "|");
        strcat(buffer, s[j].sem);
        strcat(buffer, "|");
        strcat(buffer, s[j].branch);

        int count = strlen(buffer);
        for (int k = 0; k < 45 - count; k++)
            strcat(buffer, "!");

        strcat(buffer, "\n");
        file << buffer;
    }

    file.close();
}

int main()
{
    int choice;
    while (1)
    {
//        clrscr();
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
