#pragma once
#include "CtrlrJeux.h"
class CtrlrMenu
{
public:
	CtrlrMenu();
	~CtrlrMenu();
	int Pause(CtrlrJeux jeux);
	int fin_partie(CtrlrJeux jeux, int score);
	void Afficher();
	bool victoire(CtrlrJeux jeux);
};

