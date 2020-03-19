
#include "Personnage.h"
using namespace std;
#include <iostream>

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
list<Condiment*> Personnage::getCondiments()
{
	return condiments;
}

void Personnage::retirerTop() {
	condiments.pop_back();
}
void Personnage::setCondiments(list<Condiment*> newCondiments)
{
	condiments = newCondiments;
}
void Personnage::deplacer(int direction, int largeur)
{

	if (direction == gauche)
	{
		if (position <= 0)
		{
			position = largeur - 1;
		}
		else
		{
			position--;
		}
	}
	else
	{
		if (position >= largeur - 1)
		{
			position = 0;
		}
		else
		{
			position++;
		}
	}
	
	for(Condiment* c : condiments) {
		c->setPositionX(position);
	}
}
int Personnage::getHauteur()
{
	return condiments.size()+1;
}

std::ostream& operator<<(ostream& out, Personnage p) {
	out << p.toString();
	return out;
}

char Personnage::toString() {
	return '#';
}
void Personnage::ajouterCondiment(Condiment* c) {
	condiments.push_back(c);
}
Personnage Personnage::copy()
{
	Personnage copy;
	copy.setPosition(this->position);
	list<Condiment*> c(condiments);
	copy.setCondiments(c);
	return copy;
}
void Personnage::setHauteur(int newH)
{
	list<Condiment*> newcondiments;
	condiments.clear();
	cout << condiments.size() << endl;
	condiments = newcondiments;
}