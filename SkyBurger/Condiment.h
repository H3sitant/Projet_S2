#pragma once
#include <ostream>
using namespace std;
class Condiment
{
public:
	enum SorteCondiment{LAITUE, PAIN, TOMATE, OIGNON, BOULETTE};
	ostream& afficher(ostream& out);
private:

};

