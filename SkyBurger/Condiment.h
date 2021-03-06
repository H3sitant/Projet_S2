#pragma once
#include <ostream>
#define bas 3
#define droite 1
#define gauche 0
using namespace std;

struct Point {
	int x;
	int y;
};
class Condiment
{
public:
	enum SorteCondiment{ PAIN, LAITUE, TOMATE, OIGNON, BOULETTE, POWERUP}; //IMPORTANT: Powerup doit demeurer � la fin de l'enum
	Condiment(Point p = { 0,0 });
	Condiment(SorteCondiment sorte, Point position);
	Condiment(const Condiment &c);
	ostream& afficher(ostream& out);
	virtual char toString();
	friend ostream& operator<<(ostream& out, Condiment c);
	SorteCondiment getSorte();
	void setSorte(SorteCondiment sorte);
	Point getPosition();
	void setPosition(Point Position);
	void setPositionX(int x);
	void setPositionY(int y);
	void deplacer(int direction);
	bool operator==(const Condiment& c) const;

	Condiment& operator=(const Condiment& c);

private:
	SorteCondiment sorte;
	Point position;
};



