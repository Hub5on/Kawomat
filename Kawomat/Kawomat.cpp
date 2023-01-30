#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <iomanip>
#include <limits>
#include <cstddef>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

static void baner() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    cout << "   _   __                                    _" << endl;
    cout << "  | | / /                                   | |" << endl;
    cout << "  | |/ /  __ ___      _____  _ __ ___   __ _| |_" << endl;
    cout << "  |    \\ / _` \\ \\ /\\ / / _ \\| '_ ` _ \\ / _` | __|" << endl;
    cout << "  | |\\  \\ (_| |\\ V  V / (_) | | | | | | (_| | |_" << endl;
    cout << "  \\_| \\_/\\__,_| \\_/\\_/ \\___/|_| |_| |_|\\__,_|\\__|" << endl << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "Automat przyjmuje monety w następujących nominałach:" << endl;
    cout << "0.10zł, 0.20zł, 0.50zł, 1zł, 2zł, 5zł\n\n\n";
}
static void menu() {

    cout << "Wybierz napój:\n\n";
    cout << "-->     1. Mała czarna                   1.80zł\n";
    cout << "-->     2. Duża czarna                   2.00zł\n";
    cout << "-->     3. Mała z mlekiem                2.10zł\n";
    cout << "-->     4. Duża z mlekiem                2.30zł\n";
    cout << "-->     5. Capuccino z czekoladą         2.50zł\n";
    cout << "-->     6. Gorąca czekolada              2.30zł\n";
    cout << "-->     7. Late Macchiato                3.60zł\n";
    cout << "-->     8. Espresso                      3.10zł\n";

}
int main()
{
    int wybor = 0;
    double cena = 0, kwota = 0, moneta = 0, reszta = 0;
    char przycisk = 'x';
    int cukier = 0;
    bool czyPowrot = true;

    cout << setprecision(2) << fixed;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_CTYPE, "Polish");

    while (czyPowrot) {
        baner();
        cout << "Pozostała kwota: " << reszta << "zł" << endl << endl;
        menu();


        cout << "Wybór:";
        cukier = 0;
        kwota = 0;
        while (!(cin >> wybor) || (wybor > 8) || (wybor < 1)) {
            system("CLS");
            baner();
            menu();
            cin.clear();
            cin.ignore();
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\nWprowadzono nieprawidłowy numer napoju. Wprowadź jeszcze raz.";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "\n\nWybór:";
        }
        switch (wybor) {
        case 1:
            cena = 1.80;
            break;
        case 2:
            cena = 2.00;
            break;
        case 3:
            cena = 2.10;
            break;
        case 4:
            cena = 2.30;
            break;
        case 5:
            cena = 2.50;
            break;
        case 6:
            cena = 2.30;
            break;
        case 7:
            cena = 3.60;
            break;
        case 8:
            cena = 3.10;
            break;
        }
        system("CLS");
        while ((przycisk != 'p') && (przycisk != 'P')) {
            baner();
            cout << "Wybierz ilość cukru (1g - 0.10zł): " << endl << "A lub D aby wybrać ilość, P aby zaakceptować" << endl << endl;


            cout << "|";
            for (int x = 0; x < cukier * 2; x++) {
                cout << (char)22;
            }
            cout << "| " << cukier << " g cukru";


            char ch = _getch();


            if ((cukier < 5) && (ch == 'd') || (ch == 'D'))
            {
                cukier++;
                system("CLS");
            }
            else if ((cukier > 0) && (ch == 'a') || (ch == 'A')) {
                cukier--;
                system("CLS");
            }
            if (ch == 'p' || ch == 'P') {
                przycisk = ch;
            }
            system("CLS");
        }
        przycisk = 'x';
        system("CLS");
        baner();

        kwota = cena;
        kwota = kwota + (cukier * 0.10);
        cukier = 0;
        while (kwota > 0.10) {

            if (reszta == kwota) {
                kwota = kwota - reszta;
                reszta = 0;
                break;
            }
            if (reszta > 0 && reszta < kwota) {
                kwota = kwota - reszta;
                reszta = 0;
            }
            else if (reszta > 0 && reszta > kwota) {
                kwota = kwota - reszta;
                reszta = kwota;
                kwota = 0;
                break;
            }
            cout << "Do zapłaty pozostało: " << kwota << "zł\n";
            cout << "Wrzuć monetę: ";
            while (!(cin >> moneta) || (moneta != 0.10) && (moneta != 0.20) && (moneta != 0.50) && (moneta != 1) && (moneta != 2) && (moneta != 5)) {
                system("CLS");
                baner();
                cout << "Do zapłaty pozostało: " << kwota << "zł\n";
                cout << "Wrzuć monetę: ";
                cin.clear();
                cin.ignore();
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nNie poprawny nominał lub wprowadzono tekst. Wprowadź monetę jeszcze raz.";
                SetConsoleTextAttribute(hConsole, 7);
                cout << "\n\nWrzuć monetę: ";
            }


            kwota = kwota - moneta;

            system("CLS");
            baner();
        }
        system("CLS");
        reszta = fabs(kwota);


        int dlugosc_paska = 21;
        for (int i = 0; i < dlugosc_paska; i++)
        {
            system("CLS");
            baner();
            cout << "Przygotowywanie napoju..." << endl << endl;

            for (int x = 0; x < i; x++) {
                cout << (char)35;
            }
            for (int z = 0; z < 20 - i; z++) {
                cout << (char)22;
            }
            cout << " " << i * 5 << "%" << endl;

            Sleep(250);

        }
        system("CLS");
        baner();
        cout << "Pozostało " << reszta << "zł, chcesz kupić jeszcze raz? (T/N)" << endl;

        char powrot = _getch();
        if (powrot == 'T' || powrot == 't') {
            czyPowrot = true;
        }
        else if (powrot == 'N' || powrot == 'n') {
            czyPowrot = false;
        }
        system("CLS");
    }
}
