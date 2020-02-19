#pragma once
class VueJeux
{
public:
	VueJeux();
	~VueJeux();
	int getHauteur();
	void setHauteur(int pos);
	int getLargeur();
	void setLargeur(int pos);
private:
	int Largeur;
	int Hauteur;
};

