#include "CtrlrJeux.h"
#include <iostream>
#include <string>


using namespace std;


CtrlrJeux::CtrlrJeux(int score=0)
{
	 hauteur = vue.getHauteur();
	 largeur = vue.getLargeur();
	 personnage = Personnage(int(largeur/2));
	 //La longueur de la recette est par rapport au score/niveau)
	 score + 2 < 10 ? liste_longeur = (score + 2):liste_longeur=(9);
	 for (int i = 0; i < liste_longeur; i++)
	 {
		 //Permet de s'assurer qu'aucun pain n'est généré.. pourrait être amélioré car peut prendre du temps
		 do {
			 recette[i] = Condiment();
		 } while (recette[i].getSorte() == Condiment::PAIN);
		 cout << recette[i] << endl;
	 }
	 //Le dernier ingrédient est un pain
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
		affichage += "Powerup actif: ";
		switch (powerUpActif)
		{
		case 'S':
			affichage += "Star	";
			affichage += "Temps restant: ";
			for (int i = 0; i < tempsRestantPowerup; i++) {
				affichage += "|";
			}
			break;
		case 'R':
			affichage += "Rainbow	";
			affichage += "Temps restant: ";
			for (int i = 0; i < tempsRestantPowerup; i++) {
				affichage += "|";
			}
			break;
		default:
			affichage += "Aucun	";
			break;
		}
		affichage += '\n';
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

void CtrlrJeux::activerPower(Powerup powerup)
{
	cout << "Powerup activé!";
	//TODO Coder les différentes effets des powerups
	switch (powerup.getSortePow()) {
		case Powerup::STAR:
			//powerUpActif = powerup.toString();
			//tempsRestantPowerup = TEMPS_MAX_POWERUP;
			break;
		case Powerup::RAINBOW:
			powerUpActif = powerup.toString();
			tempsRestantPowerup = TEMPS_MAX_POWERUP;
			activerRainbow();
			break;
		case Powerup::POTION:
			//Retire le dernier condiment de la pile du joueur
			//Powerup de type passif -> application immédiate
			if (!personnage.getCondiments().empty()) {
				personnage.retirerTop();
			}
			break;
		case Powerup::CORONA:
			//Le corona fait le bordel et mélange le burger constitué
			personnage.mixBurger();
			break;
		default:
			throw (invalid_argument("Type de powerup non pris en charge"));
	}
}




//Pouvoir transformant tous les condiments en
//le prochain élément nécessaire à la recette
void CtrlrJeux::activerRainbow() {
	int i = 0;
	bool pileIsGood = true;
	Condiment::SorteCondiment condimentVoulu;
	for (Condiment *c : personnage.getCondiments()) {
		if (c->getSorte() != recette[i].getSorte()) {
			pileIsGood = false;
		}
		i++;
	}
	list<Condiment*> newFalling;
	if (pileIsGood){
		condimentVoulu = recette[i].getSorte();
		for (Condiment *c : fallingCondiments) {
			newFalling.push_back(new Condiment(condimentVoulu, c->getPosition()));
		}
	}
	else //On transforme les condiments en potion pour permettre au joueur de corriger ses erreurs
	{
		for (Condiment* c : fallingCondiments) {
			newFalling.push_back(new Powerup(Powerup::POTION, c->getPosition()));
		}
	}
	fallingCondiments = newFalling;
}
//Verifie si un powerup est actif et applique son effet
void CtrlrJeux::verifierPowerups() {
	if (powerUpActif != NULL) {
		if (tempsRestantPowerup-- > 0) {
			switch (powerUpActif) {
				case 'R': //Rainbow
					activerRainbow();
					break;
				default:
					throw invalid_argument("Type de PowerUp non pris en charge");
				}
		}
		else {
			powerUpActif = NULL;
		}
	}
}

bool CtrlrJeux::faireTomberCondiments() {
	bool finjeu = false;
	if (!fallingCondiments.empty()) {
		verifierPowerups();
		for (Condiment* c : fallingCondiments) {
			c->deplacer(bas);
		}
		
		list<Condiment*> cpyFalling(fallingCondiments);
		for (Condiment* c : cpyFalling) {
			if (c->getPosition().y == personnage.getHauteurBurger() && c->getPosition().x == personnage.getPosition()) {
				//Condiment* copy(c);
					fallingCondiments.remove(c);
					Powerup* p;
					switch (c->getSorte()) {
					
					case Condiment::POWERUP:
						p = dynamic_cast<Powerup*> (c);
						if (p) //vérifie que le cast s'est bien passé
						{
							activerPower(*p);
							break;
						}
					case Condiment::PAIN:
						finjeu = true;
					default:
						personnage.ajouterCondiment(c);
					}
					
			}else if (c->getPosition().y<0) fallingCondiments.remove(c);
			else if (coronaVirusMode & c->getPosition().y == int(hauteur / 2)) {//Les éléments qui passent la moitié de l'écran on des chances de se transformer en virus
				if (rand() % PROB_CORONA==0) {
					Condiment* contaminedCondiment = new Powerup(Powerup::CORONA, c->getPosition());
					fallingCondiments.push_back(contaminedCondiment);
					fallingCondiments.remove(c);
				}
			}
		}
	}
	return finjeu;
}

void CtrlrJeux::genererCondiment() {
	Condiment* newCond;
	int coordy = hauteur - 1;
	int coordx = rand() % largeur;
	Point p = { coordx, coordy };
	
	if (rand() % PROBPOWERUP == 0){
		//Choisis un powerup de façon aléatoire
		Powerup::SortePowerup sorte = static_cast<Powerup::SortePowerup>(rand() % Powerup::last);
		newCond = new Powerup(sorte, p);
	}
	else {
		//Choisis un condiment autre que powerup de façon aléatoire
		Condiment::SorteCondiment sorte = static_cast<Condiment::SorteCondiment>(rand() % Condiment::POWERUP);
		newCond = new Condiment(sorte, p);
	}
	fallingCondiments.push_back(newCond);
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