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
	int getPosition();
	void setPosition(int position);
	stack<Condiment> getCondiments();
	void setCondiments(stack<Condiment> condiments);
	void deplacer(int direction);
	int getHauteur();
};

