#include "VueJeux.h"
VueJeux::VueJeux()
{
	Largeur = 30;
	Hauteur = 20;
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