#include <stdio.h>

union Data {
    int angka;
    float angka_desimal;
};

int main() {
    union Data data1;
    data1.angka = 10;

    return 0;
}