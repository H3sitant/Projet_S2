#include "Condiment.h"

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

ostream& operator<<(ostream& out, Condiment c)
{
	return c.afficher(out);
}
