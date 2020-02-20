#pragma once
#include <ostream>
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
	ostream& afficher(ostream& out);
	char toString();
	friend ostream& operator<<(ostream& out, Condiment c);
	SorteCondiment getSorte();
	void setSorte(SorteCondiment sorte);
	Point getPosition();
	void setPosition(Point Position);

private:
	SorteCondiment sorte;
	Point position;
};



