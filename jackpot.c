#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int wallet = 100;

void Initialize() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    system("cls");
    srand(time(NULL));
}

void Greeting() {
    printf("Herzlich willkommen!\n");
    printf("Drücke eine beliebige Taste, damit es losgeht!\n\n");
    getch();
}

int CountWallet() {
    int bet;

    while (1) { // Endlosschleife, die erst durch eine gültige Eingabe unterbrochen wird
        printf("Du hast %d Credits zur Verfügung.\n", wallet);
        printf("Wie viel möchtest du setzen? ");
        fflush(stdin); // Eingabepuffer löschen
        scanf("%d", &bet);

        if (bet <= wallet && bet > 0) { // Sicherstellen, dass der Einsatz positiv ist
            wallet -= bet;
            printf("Gut. %d Credits wurden gesetzt!\n\n", bet);
            return bet;
        } else {
            printf("Ungültige Eingabe. Bitte einen gültigen Betrag setzen!\n");
        }
    }
}


void GameLoop() {
    char slotpool[5] = {'x', '+', '$', '?', '§'};
    int anzahl_Zeichen = sizeof(slotpool) / sizeof(slotpool[0]);
    char ausgabe[3];

    int bet = CountWallet();
    for (int i = 0; i < 3; i++) {
        int random_index = rand() % anzahl_Zeichen; // Zufälligen Index berechnen
        char slot = slotpool[random_index];
        ausgabe[i] = slot;

        printf("| %c ", ausgabe[i]);
        fflush(stdout);
        if (i == 2) {
            printf("|");
        } else {
            sleep(1);
        }
    }
    printf("\n\n");

    if (ausgabe[0] == ausgabe[1] && ausgabe[0] == ausgabe[2]) {
        wallet += bet * 2;
        printf("JACKPOT!\n");
    } else if ((ausgabe[0] == ausgabe[1] && ausgabe[0] != ausgabe[2]) ||
               (ausgabe[0] == ausgabe[2] && ausgabe[0] != ausgabe[1]) ||
               (ausgabe[1] == ausgabe[2] && ausgabe[1] != ausgabe[0])) {
        wallet += bet;
        printf("Du bekommst deinen Gewinn zurück!\n");
    } else {
        printf("Verloren!\n");
    }
    printf("Dein neues Guthaben beträgt %d.\n", wallet);
}

int AskReplay() {
    char wiederholen;
    if (wallet > 0) {
        printf("Gib j ein, für noch einen Versuch! ");
        fflush(stdout);
        scanf(" %c", &wiederholen);
        return (wiederholen == 'j');
    } else {
        printf("Du hast all dein Geld verspielt und bist bankrott!\n");
        return 0;
    }
}

int main() {
    Initialize();
    Greeting();

    do {
        GameLoop();
    } while (AskReplay());

    return 0;
}
