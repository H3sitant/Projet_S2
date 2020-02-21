#pragma once
#include "Condiment.h"
#include <list>
#define droite 1
#define gauche 0
using namespace std;
class Personnage
{
private:
	int position;
	list<Condiment*> condiments;
public:
	Personnage(int position=0);
	~Personnage();
	int getPosition();
	void setPosition(int newPosition);
	list<Condiment*> getCondiments();
	void setCondiments(list<Condiment*> condiments);
	void deplacer(int direction, int largeur);
	int getHauteur();
	char toString();
	void ajouterCondiment(Condiment* c);
	Personnage copy();
	friend ostream& operator<<(ostream& out, Personnage p);
	void setHauteur(int newH);	
};

