
#include "Personnage.h"
#define droite 1
#define gauche 0
Personnage::Personnage(int position)
{
	this->position = position;
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
vector<Condiment> Personnage::getCondiments()
{
	return condiments;
}
void Personnage::setCondiments(vector<Condiment> newCondiments)
{
	condiments = newCondiments;
}
void Personnage::deplacer(int direction,int largeur)
{
	if (direction == gauche)
	{
		if (position <= 0)
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
		if (position >= largeur)
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
	return condiments.back().getPosition().y;
}

std::ostream& operator<<(ostream& out, Personnage p) {
	out << p.toString();
	return out;
}

char Personnage::toString() {
	return '¯';
}