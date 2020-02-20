// SkyBurger.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CtrlrJeux.h"
#include <thread>
#include <conio.h>
CtrlrJeux ctrlrJeux;
void Afficher()
{
    cout << "Afficher" << endl;
    ctrlrJeux.Afficher();
}
int main()
{
    thread t1(Afficher);
    int touche;
    do
    {
        touche = _getch();
        switch (touche)
        {
        case 75:
        case 97:
            cout << "gauche" << endl;
            ctrlrJeux.ActionDeplacer(0);
            break;
        case 77:      
        case 100:
            cout << "droite" << endl;
            ctrlrJeux.ActionDeplacer(1);
            break;
        default:
            break;
        }
    } while (touche != 27);
    ctrlrJeux.setActif(false);
   
    t1.join();
}
