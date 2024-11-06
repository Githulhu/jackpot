#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int wallet = 100;

void Initialize()
{
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    system("cls");

    srand(time(NULL));
}

void greeting() {

    printf("Herzlich willkommen!\n");
    printf("Drücke eine beliebige Taste, damit es losgeht!\n\n");
    getch();
}

int CountWallet()
{
    int bet;

    printf("Du hast %d Credits zur Verfügung.\n", wallet);
    printf("Wie viel möchtest du setzen? ");
    fflush(stdin);
    scanf("%d", &bet);

    wallet = wallet - bet;

    return bet;
}

int main()
{
    Initialize();
    greeting();

    char slotpool[5] = {'x', '+', '$', '?', '§'};
    int anzahl_Zeichen = sizeof(slotpool) / sizeof(slotpool[0]);
    char ausgabe[3];
    char wiederholen = 'n';

    do {
        int bet = CountWallet();

        for(int i=0;i<3;i++)
        {

            int random_index = rand() %5; // Zufälligen Index berechnen (von 0 bis 5 - 1)
            char slot = slotpool[random_index];
            ausgabe[i] = slot;

            printf("| %c ", ausgabe[i]);
            fflush(stdout);
            if(i==2)
                {
                    printf("|");
                    break;
                } else
                    sleep(1);
        }
        printf("\n\n");
        if(ausgabe[0] == ausgabe[1] && ausgabe[0] == ausgabe[2]) {
            printf("JACKPOT!\n");
            printf("Dein neues Guthaben beträgt %d.", wallet);
            wallet = walle + bet * 2;
            }
            else if
                ((ausgabe[0] == ausgabe[1] && ausgabe[0] != ausgabe[2]) ||
                (ausgabe[0] == ausgabe[2] && ausgabe[0] != ausgabe[1]) ||
                (ausgabe[1] == ausgabe[2] && ausgabe[1] != ausgabe[0]))
                {
                    printf("Du bekommst deinen Gewinn zurück!\n");
                    wallet = wallet + bet;
                    printf("Dein neues Guthaben beträgt %d.", wallet);
                }
                else
                {
                    printf("Verloren!\n");
                    printf("Dein neues Guthaben beträgt %d.", wallet);
                }

        printf("\n\n");

        printf("Gib j ein, für noch einen Versuch! ");
        fflush(stdout);
        scanf(" %c", &wiederholen);
        printf("\n");
    } while (wiederholen == 'j');

    return 0;
}
