#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class coseq {
public:
    string list[4][50];
    string olist[50];
    int c1[4], c2[4];

    void readFiles();
    void sortList(int i);
    void mergeLists();
};

void coseq::readFiles() {
    fstream fp;
    string name;
    
    for (int i = 1; i <= 3; i++) {
        c1[i] = 0;
        switch (i) {
            case 1:
                fp.open("n1.txt", ios::in);
                break;
            case 2:
                fp.open("n2.txt", ios::in);
                break;
            case 3:
                fp.open("n3.txt", ios::in);
                break;
        }
        
        while (getline(fp, name)) {
            list[i][++c1[i]] = name;
        }
        
        fp.close();
        sortList(i);
    }
}

void coseq::sortList(int i) {
    for (int j = 1; j <= c1[i]; j++) {
        for (int k = j + 1; k <= c1[i]; k++) {
            if (list[i][j] > list[i][k]) {
                swap(list[i][j], list[i][k]);
            }
        }
    }
}

void coseq::mergeLists() {
    int avail[4] = { 0 };
    int t = -1;
    
    for (int i = 1; i <= 3; i++) {
        c2[i] = 1;
        avail[i] = 1;
    }
    
    while (true) {
        int smallestList = 0;
        string smallestStr;
        
        for (int i = 1; i <= 3; i++) {
            if (avail[i]) {
                if (smallestList == 0 || list[i][c2[i]] < smallestStr) {
                    smallestList = i;
                    smallestStr = list[i][c2[i]];
                }
            }
        }
        
        if (smallestList == 0) {
            break;
        }
        
        c2[smallestList]++;
        if (c2[smallestList] > c1[smallestList]) {
            avail[smallestList] = 0;
        }
        
        if (olist[t] != smallestStr) {
            olist[++t] = smallestStr;
        }
    }
    
    cout << "\nMerged list:\n";
    for (int i = 0; i <= t; i++) {
        cout << olist[i] << "\n";
    }
}

int main() {
    coseq c;
    c.readFiles();
    c.mergeLists();

    return 0;
}
