#pragma once
#include "CtrlrJeux.h"
class CtrlrMenu
{
public:
	CtrlrMenu();
	~CtrlrMenu();
	int Pause(CtrlrJeux jeux);
	void fin_partie(CtrlrJeux jeux);
	void Afficher();
};

