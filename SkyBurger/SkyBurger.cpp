// SkyBurger.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CtrlrJeux.h"
#include <thread>
#include <conio.h>
CtrlrJeux ctrlrJeux;

int main()
{
    while(true){
    int touche;
    if (_kbhit) {
        touche = _getch();
        switch (touche)
        {
        case 97:
        case 75:
            cout << "gauche" << endl;
            ctrlrJeux.ActionDeplacer(gauche);
            break;
        case 77:
        case 100:
            cout << "droite" << endl;
            ctrlrJeux.ActionDeplacer(droite);
            break;
        default:
            break;
        }
    }
        ctrlrJeux.Afficher();
    }
   
}
