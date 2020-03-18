#include "CtrlrJeux.h"
#include <iostream>

using namespace std;


CtrlrJeux::CtrlrJeux(int score)
{
	 hauteur = vue.getHauteur();
	 largeur = vue.getLargeur();
	 personnage = Personnage(int(largeur/2));
	 //La longueure de la recette est par rapport au score/niveau)
	 score + 2 < 10 ? liste_longeur = (score + 2):liste_longeur=(9);
	 for (int i = 0; i < liste_longeur; i++)
	 {
		 do {
			 recette[i] = Condiment();
		 } while (recette[i].getSorte() == Condiment::PAIN);
		 cout << recette[i] << endl;
	 }
	 recette[liste_longeur - 1] = Condiment(Condiment::PAIN,Point());
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
		affichage+= "Liste en orde des condiments : ";
		for (int i = 0; i < liste_longeur; i++)
		{
			affichage+= (recette[i]).toString();
		}
		affichage += "\n";
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
				//Condiment* copy(c);
					personnage.ajouterCondiment(c);
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

Condiment CtrlrJeux::getlisteV(int i)
{
	return recette[i];
}

int CtrlrJeux::getLongeurL()
{
	return liste_longeur;
}

Personnage CtrlrJeux::getPersonne()
{
	return personnage;
}