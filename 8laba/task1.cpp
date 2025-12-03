#include <stdio.h>
#include <cstring>
using namespace std;

#define STR_LEN 50
#define MAX_CARS 100

typedef struct {
    char brand[STR_LEN];
    char color[STR_LEN];
    char number[STR_LEN];
    int year;
    char owner[STR_LEN];
} Car;

typedef struct {
    char brand[STR_LEN];
    int count;
} BrandCount;


int inputCars(Car cars[], int maxN) {
    int n;
    printf("Введiть кiлькiсть автомобiлiв (до %d): ", maxN);
    scanf("%d", &n);
    if (n > maxN) {
        n = maxN;
    }

    for (int i = 0; i < n; i++) {
        printf("\nАвтомобiль #%d\n", i + 1);

        printf("Марка: ");
        scanf("%s", cars[i].brand);

        printf("Колiр: ");
        scanf("%s", cars[i].color);

        printf("Номер: ");
        scanf("%s", cars[i].number);

        printf("Рiк випуску: ");
        scanf("%d", &cars[i].year);

        printf("Власник: ");
        scanf("%s", cars[i].owner);
    }
    return n;
}




void printCarsTable(const Car cars[], int n) {
    printf("\n================ ТАБЛИЦЯ АВТОМОБIЛIВ ================\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-12s | %-10s | %-10s | %-6s | %-15s |\n",
           "№", "Марка", "Колiр", "Номер", "Рiк", "Власник");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-12s | %-10s | %-10s | %-6d | %-15s |\n",
               i + 1, cars[i].brand, cars[i].color, cars[i].number, cars[i].year, cars[i].owner);
    }
    printf("---------------------------------------------------------------------------------------\n");
}


int buildBrandCount(const Car cars[], int n, BrandCount bc[]) {
    int k = 0;  // unique car-brand amount

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < k; j++) {
            if (strcmp(cars[i].brand, bc[j].brand) == 0) {     // if equal ( comparing )
                pos = j;
                break;
            }
        }
        // if car-brand is not in the structure
        if (pos == -1) {
            strcpy(bc[k].brand, cars[i].brand);
            bc[k].count = 1;
            k++;
        } else { // += 1
            bc[pos].count++;
        }
    }
    return k;
}




void sortBrandCountDesc(BrandCount bc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (bc[j].count < bc[j + 1].count) {
                BrandCount tmp = bc[j];
                bc[j] = bc[j + 1];
                bc[j + 1] = tmp;
            }
        }
    }
}




void printBrandCountTable(const BrandCount bc[], int n) {
    printf("\n=========== КIЛЬКIСТЬ АВТО ЗА МАРКАМИ (спадання) ===========\n");
    printf("-------------------------------------------------------------\n");
    printf("| %-3s | %-15s | %-10s |\n", "№", "Марка", "Кiлькiсть");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-15s | %-10d |\n", i + 1, bc[i].brand, bc[i].count);
    }

    printf("-------------------------------------------------------------\n");
}



int main() {
    Car cars[MAX_CARS];
    BrandCount bc[MAX_CARS];

    int n = inputCars(cars, MAX_CARS);  
    printCarsTable(cars, n);           

    int k = buildBrandCount(cars, n, bc);   
    sortBrandCountDesc(bc, k);             

    printBrandCountTable(bc, k);            

    return 0;
}