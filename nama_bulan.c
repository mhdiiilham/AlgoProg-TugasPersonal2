#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

char* converToLower(char *s)
{
    for(int i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }

    return s;
}

int countVowels(char *name) {
    int count = 0;

    for (int i = 0; i < strlen(name); i ++)
    {
        if (name[i] == 'a' || name[i] == 'i' || name[i] == 'u' || name[i] == 'e' || name[i] == 'o')
        {
            count++;
        }
    }

    return count;
}

int main() {
    char userInputChar[1];
    char userInputToLower;
    int countFoundSelected = 0;
    int numberOfMonths = 12;
    int userSelection = 0;
    char* selectedMonths[12];
    char months[][12] = {"januari", "februari", "maret", "april", "mei", "juni", "july", "agustus", "september", "oktober", "november", "desember"};
    bool isMonthExist = false;
 

    printf("Masukan huruf A-Z: ");
    scanf("%s", userInputChar);

    userInputToLower = *converToLower(userInputChar);

    for (int i=0; i < numberOfMonths; i++ ) {
        char firstCharOfTheMonthName = months[i][0];
        if (firstCharOfTheMonthName == userInputToLower) {
            isMonthExist = true;
            selectedMonths[countFoundSelected] = months[i];
            countFoundSelected++;
            printf("%d. %s\n", countFoundSelected, months[i]);
        }
    }

    if (!isMonthExist) {
        printf("huruf awalan yang anda masukan salah.\n");
        return 1;
    }


    if (countFoundSelected > 1)
    {
        do
        {
            printf("silahkan pilih bulan yang anda inginkan (masukan angka 1 - %d)\n", countFoundSelected);
            if (scanf("%d", &userSelection) != 1 || userSelection < 1 || userSelection > countFoundSelected)
            {
                printf("Input tidak valid. Mohon masukkan angka antara 1 dan %d.\n", countFoundSelected);
                // Clear input buffer in case of non-integer input
                while (getchar() != '\n');
            }
        } while (userSelection < 1 || userSelection > countFoundSelected);
    }

    printf("nama bulan: %s\n", selectedMonths[userSelection-1]);
    int totalVowel = countVowels(selectedMonths[userSelection-1]);
    int totalNonVower = strlen(selectedMonths[userSelection-1]) - totalVowel;
    printf("jumlah huruf yang berupa karakter vokal (a,i,u,e,o): %d\n", totalVowel);
    printf("jumlah huruf yang berupa karakter nonvokal: %d\n", totalNonVower);

    return 0;
}
