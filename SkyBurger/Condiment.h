#pragma once
#include <ostream>
using namespace std;
class Condiment
{
public:
	enum SorteCondiment{LAITUE, PAIN, TOMATE, OIGNON, BOULETTE};
	ostream& afficher(ostream& out);
	friend ostream& operator<<(ostream& out, Condiment c);
	SorteCondiment getSorte();
	void setSorte(SorteCondiment sorte);
	Point getPosition();
	void setPosition(Point Position);

private:
	SorteCondiment sorte;
	Point position;
};

struct Point {
	int x;
	int y;
};

