#include "field.h"
#include "ant.h"

void changeColor(int wiersz, int kolumna, int** plansha){
	if(plansha[wiersz][kolumna] == 0)
		plansha[wiersz][kolumna] = 1;
	else
		plansha[wiersz][kolumna] = 0;
}

void stepFromWhite(mr * mrowka, int** plansha){
	turnRight(mrowka);
	changeColor(mrowka->aktualnyWiersz, mrowka->aktualnaKolumna, plansha);
	goForward(mrowka);
}

void stepFromDark(mr * mrowka, int** plansha){
	turnLeft(mrowka);
	changeColor(mrowka->aktualnyWiersz, mrowka->aktualnaKolumna, plansha);
	goForward(mrowka);
}	

void step(mr * mrowka, int** plansha){
	if(plansha[mrowka->aktualnyWiersz][mrowka->aktualnaKolumna] == 0)
		stepFromWhite(mrowka, plansha);
	else if(plansha[mrowka->aktualnyWiersz][mrowka->aktualnaKolumna] == 1)
		stepFromDark(mrowka, plansha);
}
