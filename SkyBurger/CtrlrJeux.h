#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
#define droite 1
#define gauche 0
using namespace std;

class CtrlrJeux
{
public:
	CtrlrJeux();
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	void Pause();
	const void Afficher();
private:
	VueJeux vue;
	Personnage personnage;
	vector<Condiment> fallingCondiments;
	int hauteur;
	int largeur;
};

