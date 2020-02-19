#pragma once
#include "VueJeux.h"
#include "Personnage.h"
#include "Condiment.h"
class CtrlrJeux
{
public:
	CtrlrJeux();
	~CtrlrJeux();
	void ActionDeplacer(int direction);
	void Pause();
	void Afficher();
private:
	VueJeux vue;
	Personnage personnage;
	Condiment condiment;
	//char afficher[][];
};

