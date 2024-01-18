#include "ant.h"

void turnRight(mr * mrowka){
	mrowka->kierunek = mrowka->kierunek +1;
	if(mrowka->kierunek == 4){
		mrowka->kierunek = 0;
	}
}

void turnLeft(mr * mrowka){
	mrowka->kierunek = mrowka->kierunek - 1;
	if(mrowka->kierunek == -1){
		mrowka->kierunek = 3;
	}
}

void goForward(mr* mrowka){
	switch (mrowka->kierunek){
	case 0:
		if(mrowka->aktualnyWiersz != 0)
			mrowka->aktualnyWiersz -= 1;
		else
			mrowka->aktualnyWiersz = mrowka->wierszy;
		break;
		
	case 1:
		if(mrowka->aktualnaKolumna != mrowka->kolumny)
			mrowka->aktualnaKolumna += 1;
		else
			mrowka->aktualnaKolumna = 0;
		break;
	case 2:
		if(mrowka->aktualnyWiersz != mrowka->wierszy)
			mrowka->aktualnyWiersz += 1;
		else
			mrowka->aktualnyWiersz = 0;
		break;
	case 3:
		if(mrowka->aktualnaKolumna != 0)
			mrowka->aktualnaKolumna -= 1;
		else
			mrowka->aktualnaKolumna = mrowka->kolumny;
		break;
	}
}
