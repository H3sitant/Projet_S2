// SkyBurger.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CtrlrJeux.h"
#include <thread>
#include <conio.h>
#include <Windows.h>
#include <ctime>
CtrlrJeux ctrlrJeux;
void Afficher()
{
    cout << "Afficher" << endl;
    ctrlrJeux.Afficher();
}
void clear_screen(char fill = ' ') {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}
int main()
{
    //thread t1(Afficher);
    int touche;
    bool exit = false;
    while (!exit)
    {
        if (_kbhit()) {
            touche = _getch();
            switch (touche)
            {
            case 75:
            case 97:
                //cout << "gauche" << endl;
                ctrlrJeux.ActionDeplacer(gauche);
                break;
            case 77:
            case 100:
                //cout << "droite" << endl;
                ctrlrJeux.ActionDeplacer(droite);
                break;
            case 27:
                exit = true;
                break;
                //pause = p
            case 112:
                ctrlrJeux.setActif(!ctrlrJeux.getActif());
            default:
                break;
            }
            //system("cls");
            //clear_screen();
            ctrlrJeux.Afficher();
        }
        if ((clock()) % 3000 == 0) {
            ctrlrJeux.genererCondiment();
        }
        if ((clock()) % 500 == 0) {
            //system("cls");
            //clear_screen();
            ctrlrJeux.faireTomberCondiments();
            ctrlrJeux.Afficher();
        }
        //ctrlrJeux.setActif(false);
        //t1.join();
    }
}

