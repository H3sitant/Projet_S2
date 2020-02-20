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
            cout << "gauche" << endl;
            break;
        case 77:
            cout << "droite" << endl;
            break;
        case 97:
            cout << "gauche" << endl;
            break;
        case 100:
            cout << "droite" << endl;
            break;
        default:
            break;
        }
    } while (touche != 27);
   
    t1.join();
}
