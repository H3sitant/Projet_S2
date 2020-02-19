#include "CtrlrJeux.h"
#define droite 1
#define gauche 0

CtrlrJeux::CtrlrJeux()
{
	int hauteur = vue.getHauteur();
	int largeur = vue.getLargeur();
}
CtrlrJeux::~CtrlrJeux()
{

}
void CtrlrJeux:: ActionDeplacer(int direction)
{
	int largeur = vue.getLargeur();
	personnage.deplacer(direction, largeur);
}

void CtrlrJeux::Pause()
{
	
}
void CtrlrJeux ::Afficher()
{


}