#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SENTENCE_LENGTH = 1000;
const int MAX_WORDS = 100;
const int MAX_WORD_LENGTH = 100;

int splitWords(char s[], char words[][MAX_WORD_LENGTH]) {
    int w = 0, i = 0, k = 0;

    while(s[i] != '\0') {
        if (s[i] != ' ' && s[i] != '\t') {
            words[w][k++] = s[i];
        } else {
            if (k > 0) {
                words[w][k] = '\0';
                w++;
                k = 0;
            }
        }
        i++;
    }
    
    if (k > 0) {
        words[w][k] = '\0';
        w++;
    }

    return w;
}

void printSentence(char words[][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        cout << words[i];
        if (i < count - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    char *s = new char[MAX_SENTENCE_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {0};

    cout << "Введіть речення:" << endl;
    cin.getline(s, MAX_SENTENCE_LENGTH);

    int count = splitWords(s, words);

    if (count < 2) {
        cout << "Недостатньо слів.\n";
        delete[] s;
        return 0;
    }

    int a, b;
    cout << "Введіть номери для обміну: ";
    cin >> a >> b;

    if (a < 1 || a > count || b < 1 || b > count) {
        cout << "Невірні номери\n";
        delete[] s;
        return 0;
    }

    char temp[MAX_WORD_LENGTH];
    strcpy(temp, words[a - 1]);
    strcpy(words[a - 1], words[b - 1]);
    strcpy(words[b - 1], temp);

    cout << "Результат:" << endl;
    printSentence(words, count);

    delete[] s;
    return 0;


}