#include "Condiment.h"
#include <math.h>
#include <ctime>


 

Condiment::Condiment(int largeur, int hauteur) {
	srand(time(NULL));
	this->position.y = hauteur-1;
	this->position.x = rand() % largeur;
	sorte = static_cast<SorteCondiment>(rand() % last);
}

Condiment::Condiment(SorteCondiment sorte, Point position) {
	this->sorte = sorte;
	this->position = position;
}

Condiment::Condiment(const Condiment &c) {
	position.y = c.position.y;
	position.x = c.position.x;
	sorte = c.sorte;
}


ostream& Condiment::afficher(ostream& out)
{
	out << this->toString();
	return out;
}
char Condiment::toString() {
	char out;
	switch (sorte) {
	case LAITUE:
		out = 'L';
		break;
	case TOMATE:
		out = 'T';
		break;
	case OIGNON:
		out = 'O';
		break;
	case PAIN:
		out = 'P';
		break;
	case BOULETTE:
		out = 'B';
		break;
	default:
		out = 'e';
		break;
	}
	return out;
 }



enum Condiment::SorteCondiment Condiment::getSorte()
{
	return sorte;
}

void Condiment::setSorte(SorteCondiment sorte)
{
	this->sorte = sorte;
}

Point Condiment::getPosition()
{
	return position;
}

void Condiment::setPosition(Point Position)
{
	this->position = position;
}
void Condiment::setPositionX(int x)
{
	this->position.x = x;
}
void Condiment::setPositionY(int y)
{
	this->position.y = y;
}

ostream& operator<<(ostream& out, Condiment c)
{
	return c.afficher(out);
}

void Condiment::deplacer(int direction) {
	switch (direction) {
	case droite:
		position.x++;
		break;
	case gauche:
		position.x--;
		break;
	case bas:
		position.y--;
		break;
	default:
		break;
	}
}

bool Condiment::operator==(const Condiment& c) const
{
	return (this->sorte == c.sorte && this->position.x == c.position.x && this->position.y == c.position.y);
}

Condiment& Condiment::operator=(const Condiment& c) {
	position.y = c.position.y;
	position.x = c.position.x;
	sorte = c.sorte;
	return *this;
}
