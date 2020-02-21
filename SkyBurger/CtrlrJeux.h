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
	void Pause();
	const void Afficher();
	bool getActif();
	void setActif(bool value);
	void faireTomberCondiments();
	void genererCondiment();
private:
	VueJeux vue;
	Personnage personnage;
	list<Condiment*> fallingCondiments;
	int hauteur;
	int largeur;
	bool Jeu_Actif;
};

