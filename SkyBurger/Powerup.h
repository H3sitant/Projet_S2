#pragma once
#include "Condiment.h"
 class Powerup : public Condiment {
public:
    enum SortePowerup{STAR, RAINBOW, POTION, last};
    Powerup(SortePowerup sorte, Point position);
    Powerup();
    char toString();
    SortePowerup getSortePow();
    void setSortePow(SortePowerup sorte);

 private:
     SortePowerup sortePow;
};

