#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
#include "Powerup.h"
#include <list>
using namespace std;

class CtrlrJeux
{
public:
	CtrlrJeux(int score);
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	const void Afficher();
	void activerPower(Powerup powerup);
	bool faireTomberCondiments();
	void genererCondiment();
	string toString(int sorte);
	Condiment getlisteV(int i);
	int getLongeurL();
	Personnage getPersonne();
private:
	static const int PROBPOWERUP = 2;
	static const int TEMPS_MAX_POWERUP =10;
	void activerRainbow();
	void verifierPowerups();
	VueJeux vue;
	Personnage personnage;
	list<Condiment*> fallingCondiments;
	int hauteur;
	int largeur;
	int liste_longeur;
	Condiment recette[10];
	char powerUpActif = NULL;
	int tempsRestantPowerup = 0;

};

