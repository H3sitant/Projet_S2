#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
#include <list>
using namespace std;

class CtrlrJeux
{
public:
	CtrlrJeux();
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	const void Afficher();
	bool faireTomberCondiments();
	void genererCondiment();
	void toString(int sorte);
	int getlisteV(int i);
	int getLongeurL();
	Personnage getPersonne();
private:
	VueJeux vue;
	Personnage personnage;
	list<Condiment*> fallingCondiments;
	int hauteur;
	int largeur;
	int liste_longeur;
	int listeV[10];

};

