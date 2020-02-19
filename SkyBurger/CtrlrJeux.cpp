#include "CtrlrJeux.h"
#define droite 1
#define gauche 0

CtrlrJeux::CtrlrJeux()
{
	int hauteur = vue.getHauteur();
	int largeur = vue.getLargeur();
	//char afficher[hauteur][largeur];
}
CtrlrJeux::~CtrlrJeux()
{

}
void CtrlrJeux:: ActionDeplacer(int direction)
{
	int position = personnage.getPosition();
	int largeur = vue.getLargeur();
	if (direction == gauche)
	{
		if (position == 0)
		{
			position = largeur;
		}
		else
		{
			position--;
		}
	}
	else
	{
		if (position == largeur)
		{
			position = 0;
		}
		else
		{
			position++;
		}
	}
}

void CtrlrJeux::Pause()
{
	
}
void CtrlrJeux ::Afficher()
{


}