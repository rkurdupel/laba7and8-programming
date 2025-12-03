#include <iostream>
#include <cstring>
using namespace std;


void inputString(char*& str, int maxLen, const char* msg) {
    str = new char[maxLen];
    cout << msg;
    cin.getline(str, maxLen);
}

bool isPerfectStudent(int marks[5]) {
    for (int i = 0; i < 5; i++) {
        if (marks[i] != 5) return false;
    }
    return true;
}

int main() {
    const int MAX_LEN = 100;
    int N;

    cout << "Введіть кількість студентів N: ";
    cin >> N;
    cin.ignore(10000, '\n'); 

    char** surnames = new char*[N];     
    char** recordNums = new char*[N];   
    int marks[N][5];                    

    int perfectCount = 0;

    for (int i = 0; i < N; i++) {
        cout << "\nСтудент " << (i + 1) << ":\n";

        inputString(surnames[i], MAX_LEN, "Прізвище та ініціали: ");
        inputString(recordNums[i], MAX_LEN, "№ залікової книжки: ");

        cout << " Введіть 5 оцінок через пробіл: ";
        for (int j = 0; j < 5; j++) {
            cin >> marks[i][j];
        }
        cin.ignore(10000, '\n'); 

        if (isPerfectStudent(marks[i])) {
            perfectCount++;
            cout << "Круглий відмінник\n";
        } else {
            cout << "Не всі оцінки 5\n";
        }
    }

    cout << "\nКількість круглих відмінників: " << perfectCount << endl;

    
    for (int i = 0; i < N; i++) {
        delete[] surnames[i];
        delete[] recordNums[i];
    }
    delete[] surnames;
    delete[] recordNums;

    return 0;
}
