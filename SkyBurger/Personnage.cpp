
#include "Personnage.h"

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
			position = largeur-1;
		}
		else
		{
			position--;
		}
	}
	else
	{
		if (position >= largeur-1)
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
	return '#';
}
Personnage Personnage::copy()
{
	Personnage copy;
	copy.setPosition(this->position);
	vector<Condiment> c(condiments);
	copy.setCondiments(c);
	return copy;
}