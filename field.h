#ifndef FIELD_H
#define FIELD_H
#include "ant.h"

void changeColor(int wiersz, int kolumna, int** plansha);

void stepFromWhite(mr * mrowka, int** plansha);

void stepFromDark(mr * mrowka, int** plansha);	

void step(mr * mrowka, int** plansha);
#endif
