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
	enum SorteCondiment{LAITUE, PAIN, TOMATE, OIGNON, BOULETTE, last};
	Condiment(int largeur, int hauteur);
	Condiment(SorteCondiment sorte, Point position);
	Condiment(const Condiment &c);
	ostream& afficher(ostream& out);
	char toString();
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



