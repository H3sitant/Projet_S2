#include "CtrlrJeux.h"
#include <iostream>
#define droite 1
#define gauche 0

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
void CtrlrJeux ::Afficher()
{
	char item = ' ';
	for (int i = hauteur-1; i >= 0; i--) {
		for (int j = 0; j < largeur; j++) {

			for (Condiment c : fallingCondiments) {
				if (c.getPosition().y == i && c.getPosition.x == j) {
					item = c.toString();
					break;
				}
			}

			if (i == 0 && j == personnage.getPosition()) item = personnage.toString();
			
			for (Condiment c : personnage.getCondiments()) {
				if (c.getPosition().y == i&&c.getPosition.x == j) {
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