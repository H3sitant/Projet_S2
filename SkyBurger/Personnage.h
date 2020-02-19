#pragma once
#include "Condiment.h"

#include <stack>
using namespace std;
class Personnage
{
private:
	int position;
	stack<Condiment> condiments;
public:
	Personnage();
	~Personnage();
	int getPosition();
	void setPosition(int newPosition);
	stack<Condiment> getCondiments();
	void setCondiments(stack<Condiment> condiments);
	void deplacer(int direction, int largeur);
	int getHauteur();
};

