#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main() {
     SetConsoleOutputCP(1252); SetConsoleCP(1252); system("cls");

    char slotpool[5] = {'x', '+', '$', '?', '§'};
    int anzahl_Zeichen = sizeof(slotpool) / sizeof(slotpool[0]);
    srand(time(NULL)); // Beim Ausführen des Skripts wird immer eine zufällige Zahl generiert
    char ausgabe[3];
    char wiederholen = "n";

    printf("Herzlich willkommen!\n");
    printf("Drücke eine beliebige Taste, damit es losgeht!\n");
    getch();

    do {
        for(int i=0;i<3;i++) {

            int random_index = rand() %5; // Zufälligen Index berechnen (von 0 bis 5 - 1)
            char *slot = slotpool[random_index];
            ausgabe[i] = slot;

            printf("| %c ", ausgabe[i]);
            fflush(stdout);
            if(i==2) {
                    printf("|");
                    break;
            } else
            sleep(3);
        }
        printf("\n\n");
        if(ausgabe[0] == ausgabe[1] && ausgabe[0] == ausgabe[2]) {
            printf("JACKPOT!");
            }
            else if(ausgabe[0] == ausgabe[1] ^ ausgabe[1] == ausgabe[2]){
                printf("Du bekommst deinen Gewinn zurück!");
                }
                else
                    printf("Verloren!");

        printf("\n\n");

        printf("Gib j ein, für noch einen Versuch! ");
        fflush(stdout);
        scanf(" %c", &wiederholen);
        printf("\n");
    } while (wiederholen == 'j');

    return 0;
}
