
#include "Personnage.h"
#define droite 1
#define gauche 0
Personnage::Personnage()
{
	position = 0;
}
Personnage::~Personnage()
{

}
int Personnage::getPosition()
{
	return position;
}
void Personnage::setPosition(int newPosition)
{
	position = newPosition;
}
stack<Condiment> Personnage::getCondiments()
{
	return condiments;
}
void Personnage::setCondiments(stack<Condiment> newCondiments)
{
	condiments = newCondiments;
}
void Personnage::deplacer(int direction,int largeur)
{
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
int Personnage::getHauteur()
{
	int hauteur;
	hauteur=
	return hauteur;
}