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
    int retour = 0;
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
int CtrlrMenu::fin_partie(CtrlrJeux jeux, int score)
{
    system("cls");
    bool vic= victoire(jeux);
    cout << "============================" << endl;
    if (vic) cout << "==========VICTOIRE===========" << endl
        << "SCORE : " << score + 1 << endl;
    else cout << "==========DEFAITE===========" << endl
        << "SCORE : " << score << endl;//Afficher score
        cout << "============MENU============" << endl
        << "'N' :: Nouvelle partie" << endl;
    if (vic) cout << "'C' :: Continuer" << endl;
    cout << "'Q' :: Quitter le jeu" << endl
        << "============================" << endl
        << "============================" << endl;
    int retour = 0;
    int touche;
    touche = _getch();
    switch (touche)
    {
    case 110://n
    case 78://N
        system("cls");
        retour = 1;
        break;
    case 99://c
    case 67://C
        if (!vic) fin_partie(jeux,score);
        system("cls");
        break;
    case 113://q
    case 81://Q
        retour = 2;
        break;
    default:
        fin_partie(jeux,score);
        //cout << touche << endl;
        break;
    }
    return retour;
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
bool CtrlrMenu::victoire(CtrlrJeux jeux)
{
    bool vic = true;
    if (jeux.getLongeurL() == jeux.getPersonne().getHauteur()-1)
    {
        int i = 0;
        for (Condiment* c : jeux.getPersonne().getCondiments())
        {

            if (jeux.getlisteV(i).getSorte() != c->getSorte())
            {
                //cout << jeux.getlisteV(i) << endl;
                //cout << c->getSorte()<<endl;
                vic = false;
            }
            i++;
        }
    }
    else
    {
        vic = false;
    }
    
    return vic;
}