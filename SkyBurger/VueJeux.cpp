#include "VueJeux.h"
VueJeux::VueJeux()
{
	Largeur = 15;
	Hauteur = 15;
}
VueJeux::~VueJeux()
{

}
int VueJeux::getHauteur()
{
	return Hauteur;
}
void VueJeux::setHauteur(int newHauteur)
{
	Hauteur = newHauteur;
}
int VueJeux::getLargeur()
{
	return Largeur;
}
void VueJeux::setLargeur(int newLargeur)
{
	Largeur = newLargeur;
}