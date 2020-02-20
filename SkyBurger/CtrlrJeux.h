#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
using namespace std;

class CtrlrJeux
{
public:
	CtrlrJeux();
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	void Pause();
	void Afficher();
	bool getActif();
	void setActif(bool value);
private:
	VueJeux vue;
	Personnage personnage;
	vector<Condiment> fallingCondiments;
	int hauteur;
	int largeur;
	bool Jeu_Actif;
};

