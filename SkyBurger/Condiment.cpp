#include "Condiment.h"

ostream& Condiment::afficher(ostream& out)
{
	return out;
}



enum Condiment::SorteCondiment Condiment::getSorte()
{
	return SorteCondiment();
}

void Condiment::setSorte(SorteCondiment sorte)
{
}

Point Condiment::getPosition()
{
	return Point();
}

void Condiment::setPosition(Point Position)
{
}

ostream& operator<<(ostream& out, Condiment c)
{
	return c.afficher(out);
}
