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
	void faireTomberCondiments();
	void genererCondiment();
private:
	VueJeux vue;
	Personnage personnage;
	list<Condiment*> fallingCondiments;
	int hauteur;
	int largeur;
};

