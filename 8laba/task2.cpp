#include <stdio.h>
#include <string.h>

#define STR_LEN 80
#define MAX_BOOKS 100

typedef struct {
    char author[STR_LEN];     
    char title[STR_LEN];      
    char publisher[STR_LEN];  
    int year;                 
} Book;



int inputBooks(Book *books, int maxN) {
    int n;
    printf("Введiть кiлькiсть книг (не бiльше %d): ", maxN);
    scanf("%d", &n);
    if (n > maxN) {
        n = maxN;
    }

    else if (n <= 0) {
        printf("n має бути > 0");
        return -1;
    }
    getchar(); 

    for (int i = 0; i < n; i++) {
        Book *b = books + i;  

        printf("\nКнига #%d\n", i + 1);

        printf("Автор: ");
        fgets(b->author, STR_LEN, stdin);
        b->author[strcspn(b->author, "\n")] = '\0'; 

        printf("Назва книги: ");
        fgets(b->title, STR_LEN, stdin);
        b->title[strcspn(b->title, "\n")] = '\0';

        printf("Видавництво: ");
        fgets(b->publisher, STR_LEN, stdin);
        b->publisher[strcspn(b->publisher, "\n")] = '\0';

        printf("Рiк видання: ");
        scanf("%d", &b->year);
        getchar(); 
    }
    return n;
}


void sortBooksByAuthor(Book *books, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            Book *b1 = books + j;
            Book *b2 = books + j + 1;   // compare first book with the next one

            if (strcmp(b1->author, b2->author) > 0) {   // if in alphabetical order 1'st author is bigger than the 2'nd (Anthony > Brian)
                Book tmp = *b1;
                *b1 = *b2;
                *b2 = tmp;
            }
        }
    }
}



void printBooksTable(const Book *books, int n) {
    printf("\n========== ТАБЛИЦЯ КНИГ (відсортовано за автором) ==========\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-25s | %-25s | %-15s | %-4s |\n",
           "№", "Автор", "Назва книги", "Видавництво", "Рiк");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        const Book *b = books + i; 

        printf("| %-3d | %-25s | %-25s | %-15s | %-4d |\n",
               i + 1, b->author, b->title, b->publisher, b->year);
    }

    printf("----------------------------------------------------------------------------------------\n");
}


int main(void) {
    Book books[MAX_BOOKS];

    int n = inputBooks(books, MAX_BOOKS);   
    sortBooksByAuthor(books, n);          
    printBooksTable(books, n);             

    return 0;
}