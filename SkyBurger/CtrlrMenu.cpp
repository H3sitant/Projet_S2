#include "CtrlrMenu.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
CtrlrMenu::CtrlrMenu()
{

}
CtrlrMenu::~CtrlrMenu()
{

}
int CtrlrMenu::Pause(CtrlrJeux jeux)
{
    int retour = true;
    system("cls");
	Afficher();
    int touche;
    touche = _getch();
    switch (touche)
    {
    case 110://n
    case 78://N
        system("cls");
        retour = 1;
        break;
    case 114://r
    case 82://R
        system("cls");
        break;
    case 113://q
    case 81://Q
        retour = 2;
        break;
    default:
        Pause(jeux);
        //cout << touche << endl;
        break;
    }
    return retour;
}
void CtrlrMenu::fin_partie(CtrlrJeux jeux)
{

}
void CtrlrMenu::Afficher()
{
	cout << "============================" << endl
        << "============MENU============" << endl
        << "'N' :: Nouvelle partie" << endl
        << "'R' :: Reprendre" << endl
        << "'Q' :: Quitter le jeu" << endl
        << "============================" << endl
        << "============================" << endl;

}