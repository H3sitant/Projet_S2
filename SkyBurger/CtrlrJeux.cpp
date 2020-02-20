#include "CtrlrJeux.h"
#include <iostream>



CtrlrJeux::CtrlrJeux()
{
	 hauteur = vue.getHauteur();
	 largeur = vue.getLargeur();
	 personnage = Personnage(int(largeur/2));
	 

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
//Affichage à la console chaque élément en jeux
const void CtrlrJeux ::Afficher()
{
	Personnage cpyPersonnage = personnage.copy();
	vector<Condiment> cpyFalling(fallingCondiments);
		char item = ' ';
		for (int i = hauteur - 1; i >= 0; i--) {
			for (int j = 0; j < largeur; j++) {
				item = ' ';
				for (Condiment c : cpyFalling) {
					if (c.getPosition().y == i && c.getPosition().x == j) {
						item = c.toString();
						break;
					}
				}

				if (i == 0 && j == cpyPersonnage.getPosition()) {

					item = cpyPersonnage.toString();
				}

				for (Condiment c : cpyPersonnage.getCondiments()) {
					if (c.getPosition().y == i && c.getPosition().x == j) {
						item = c.toString();
						break;
					}
				}
				cout << item;
			}
			cout << endl;
		}
		cout << endl << endl;
}