// SkyBurger.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CtrlrJeux.h"
#include "CtrlrMenu.h"
#include <thread>
#include <conio.h>
#include <Windows.h>
#include <ctime>


void Afficher()
{
    cout << "Afficher" << endl;
    /*if ((clock()) % 3000 == 0) {
        ctrlrJeux.genererCondiment();
    }
    if ((clock()) % 500 == 0) {
        //system("cls");
        //clear_screen();
        ctrlrJeux.faireTomberCondiments();
        ctrlrJeux.Afficher();
    }*/
    //ctrlrJeux.Afficher();
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
    int exit = 0;
    while (exit!=2) 
    {
        CtrlrJeux ctrlrJeux;
        CtrlrMenu menu;
        //thread t1(Afficher);
        int touche;
        exit = false;
        while (exit<1)
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
                    exit = 2;
                    break;
                    //pause = p
                case 112:
                    exit = menu.Pause(ctrlrJeux);
                    //ctrlrJeux.setActif(!ctrlrJeux.getActif());
                default:
                    //cout << "touche" << touche << endl;
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
        //ctrlrJeux.~CtrlrJeux();
        //menu.~CtrlrMenu();
    }
   
}

