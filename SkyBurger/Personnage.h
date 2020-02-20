#pragma once
#include "Condiment.h"
#include <vector>
using namespace std;
class Personnage
{
private:
	int position;
	vector<Condiment> condiments;
public:
	Personnage(int position=0);
	~Personnage();
	int getPosition();
	void setPosition(int newPosition);
	vector<Condiment> getCondiments();
	void setCondiments(vector<Condiment> condiments);
	void deplacer(int direction, int largeur);
	int getHauteur();
	char toString();
	Personnage copy();
	friend ostream& operator<<(ostream& out, Personnage p);
	
};

