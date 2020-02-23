#include "CtrlrJeux.h"
#include <iostream>

using namespace std;


CtrlrJeux::CtrlrJeux()
{
	 hauteur = vue.getHauteur();
	 largeur = vue.getLargeur();
	 personnage = Personnage(int(largeur/2));
	 liste_longeur = (rand() % 10)+1;
	 for (int i = 0; i < liste_longeur; i++)
	 {
		 listeV[i] = ((rand() % 4) + 1);
		 cout << listeV[i] << endl;
	 }
	 listeV[liste_longeur - 1] = 0;
	 //Jeu_Actif = true;
}
CtrlrJeux::~CtrlrJeux()
{

}
void CtrlrJeux:: ActionDeplacer(int direction)
{
	personnage.deplacer(direction, largeur);
}
//Affichage � la console chaque �l�ment en jeux
const void CtrlrJeux::Afficher()
{
	string item =" ";
		//system("cls");
		Personnage cpyPersonnage = personnage.copy();
		list<Condiment*> cpyFalling(fallingCondiments);
		string affichage = "";
		cout << "Liste en orde des condiments : ";
		for (int i = 0; i < liste_longeur; i++)
		{
			toString(listeV[i]);
		}
		cout << endl;
		for (int i = hauteur - 1; i >= 0; i--) {
			string ligne = "";
			for (int j = 0; j < largeur; j++) {
				item = " ";
				for (Condiment* c : cpyFalling) {
					if (c->getPosition().y == i && c->getPosition().x == j) {
						item = c->toString();
						break;
					}
				}

				if (i == 0 && j == cpyPersonnage.getPosition())
				{

					item = cpyPersonnage.toString();
				}

				for (Condiment* c : cpyPersonnage.getCondiments()) {
					if (c->getPosition().y == i && c->getPosition().x == j) {
						item = c->toString();
						break;
					}
				}
				ligne+= item;
			}
			affichage+= (ligne + "\n");
		}
		cout << affichage;
}

bool CtrlrJeux::faireTomberCondiments() {
	bool finjeu = false;
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
					if (c->getSorte() == 0)
					{
						//cout << "fin de partie" << endl;
						finjeu = true;
					}
			}else if (c->getPosition().y<0) fallingCondiments.remove(c);
		}
	}
	return finjeu;
}

void CtrlrJeux::genererCondiment() {
	Condiment c(largeur, hauteur);
	fallingCondiments.push_back(new Condiment(largeur, hauteur));
}

void CtrlrJeux::toString(int sorte) {
	switch (sorte) {
	case 1:
		cout << "L ";
		break;
	case 2:
		cout << "T ";
		break;
	case 3:
		cout << "O ";
		break;
	case 0:
		cout << "P ";
		break;
	case 4:
		cout << "B ";
		break;
	default:
		cout << "e ";
		break;
	}
}

int CtrlrJeux::getlisteV(int i)
{
	return listeV[i];
}

int CtrlrJeux::getLongeurL()
{
	return liste_longeur;
}

Personnage CtrlrJeux::getPersonne()
{
	return personnage;
}