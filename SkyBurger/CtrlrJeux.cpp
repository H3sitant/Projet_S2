#include "CtrlrJeux.h"
#include <iostream>



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
		//system("cls");
		Personnage cpyPersonnage = personnage.copy();
		list<Condiment*> cpyFalling(fallingCondiments);
		for (int i = hauteur - 1; i >= 0; i--) {
			for (int j = 0; j < largeur; j++) {
				item = ' ';
				for (Condiment* c : cpyFalling) {
					if (c->getPosition().y == i && c->getPosition().x == j) {
						item = c->toString();
						break;
					}
				}

				if (i == 0 && j == cpyPersonnage.getPosition()) {

					item = cpyPersonnage.toString();
				}

				for (Condiment* c : cpyPersonnage.getCondiments()) {
					if (c->getPosition().y == i && c->getPosition().x == j) {
						item = c->toString();
						break;
					}
				}
				cout << item;
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

void CtrlrJeux::faireTomberCondiments() {
	if (!fallingCondiments.empty()) {
		for (Condiment* c : fallingCondiments) {
			c->deplacer(bas);
		}
		
		list<Condiment*> cpyFalling(fallingCondiments);
		for (Condiment* c : cpyFalling) {
			if (c->getPosition().y == personnage.getHauteur() && c->getPosition().x == personnage.getPosition()) {
				Condiment* copy(c);
					personnage.ajouterCondiment(copy);
					fallingCondiments.remove(c);
			}
		}
	}
}

void CtrlrJeux::genererCondiment() {
	Condiment c(largeur, hauteur);
	fallingCondiments.push_back(new Condiment(largeur, hauteur));
}