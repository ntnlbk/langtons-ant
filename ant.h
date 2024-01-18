#ifndef ANT_H
#define ANT_H
typedef struct {
	int kierunek; //0-góra, 1- prawo, 2- dół, 3-lewo 
	int aktualnyWiersz;
	int aktualnaKolumna;
	int wierszy; //from 0
	int kolumny;
} mr;

void turnRight(mr * mrowka);

void turnLeft(mr * mrowka);

void goForward(mr* mrowka);
#endif
