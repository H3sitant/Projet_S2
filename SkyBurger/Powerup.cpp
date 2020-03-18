#include "Powerup.h"


Powerup::Powerup(SortePowerup sorte, Point position) : Condiment(SorteCondiment::POWERUP, position) {
	setSortePow(sorte);
	setPosition(position);
}
Powerup::Powerup() : Condiment(){
	setSortePow(static_cast <SortePowerup>(rand()%last));
}

Powerup::SortePowerup Powerup::getSortePow() {
	return sortePow;
}
void Powerup::setSortePow(SortePowerup sorte) {
	sortePow = sorte;
}

char Powerup::toString()
{
	switch (sortePow) {
	case STAR:
		return 'S';
		break;
	case RAINBOW:
		return 'R';
		break;
	case POTION:
		return 'M'; //Comme dans magique
		break;
	default:
		return 'e';
		break;
	}
}
