#include "CtrlrJeux.h"
#include <iostream>

using namespace std;


CtrlrJeux::CtrlrJeux()
{
	 hauteur = vue.getHauteur();
	 largeur = vue.getLargeur();
	 personnage = Personnage(int(largeur/2));
	 Jeu_Actif = true;
}
CtrlrJeux::~CtrlrJeux()
{

}
void CtrlrJeux:: ActionDeplacer(int direction)
{
	personnage.deplacer(direction, largeur);
}

void CtrlrJeux::Pause()
{
	
}
//Affichage � la console chaque �l�ment en jeux
const void CtrlrJeux ::Afficher()
{
	char item;
		system("cls");
		Personnage cpyPersonnage = personnage.copy();
		vector<Condiment> cpyFalling(fallingCondiments);
		for (int i = hauteur - 1; i >= 0; i--) 
		{
			bool objetL =false;
			for (Condiment c2 : cpyFalling)
			{
				cout << c2.getPosition().y << endl;
				if (c2.getPosition().y == i)
				{
					objetL = true;
					break;
				}
			}
			if (i == 0)
			{
				objetL = true;
			}
			if (objetL == true)
			{
				for (int j = 0; j < largeur; j++) 
				{
					item = ' ';
					for (Condiment c2 : cpyFalling) 
					{
						if (c2.getPosition().y == i && c2.getPosition().x == j) 
						{
							item = c2.toString();
							break;
						}
					}

					if (i == 0 && j == cpyPersonnage.getPosition()) 
					{

						item = cpyPersonnage.toString();
					}

					for (Condiment c : cpyPersonnage.getCondiments()) 
					{
						if (c.getPosition().y == i && c.getPosition().x == j) 
						{
							item = c.toString();
							break;
						}
					}
					cout << item;
				}
			}
			cout << endl;
		}
		cout << endl << endl;
	}
bool CtrlrJeux::getActif()
{
	return Jeu_Actif;
}
void CtrlrJeux::setActif(bool value)
{
	Jeu_Actif = false;
}