#include <iostream>
#include <cstring>
using namespace std;

int lastPos(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 == 0 || len1 > len2) return -1;

    int last = -1;

    for (int i = 0; i <= len2 - len1; i++) {
        bool ok = true;
        for (int j = 0; j < len1; j++) {
            if (s2[i + j] != s1[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            last = i;  
        }
    }

    return last;
}

void inputString(char*& s, int maxLen, const char* msg) {
    s = new char[maxLen];
    cout << msg;
    cin.getline(s, maxLen);
}

int main() {
    const int MAX_LEN = 200;
    char* s1 = nullptr;
    char* s2 = nullptr;


    inputString(s1, MAX_LEN, "Введiть пiдрядок s1: ");
    inputString(s2, MAX_LEN, "Введiть рядок s2: ");

    cout << "\ns1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";

    int pos = lastPos(s1, s2);

    if (pos == -1)
        cout << "\nПiдрядок не знайдено.\n";
    else {
        cout << "\nОстаннє входження починається з iндексу " 
             << pos << " (нумерацiя з 0)\n";
        cout << "Або з позицiї " << (pos + 1) << " (нумерацiя з 1 для людини).\n";
    }

    delete [] s1;
    delete [] s2;

    return 0;
}