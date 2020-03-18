#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
#include <list>
using namespace std;

class CtrlrJeux
{
public:
	CtrlrJeux(int score);
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	const void Afficher();
	bool faireTomberCondiments();
	void genererCondiment();
	string toString(int sorte);
	Condiment getlisteV(int i);
	int getLongeurL();
	Personnage getPersonne();
private:
	VueJeux vue;
	Personnage personnage;
	list<Condiment*> fallingCondiments;
	int hauteur;
	int largeur;
	int liste_longeur;
	Condiment recette[10];

};

