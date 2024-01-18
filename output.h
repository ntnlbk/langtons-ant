#ifndef OUTPUT_H
#define OUTPUT_H
#include "ant.h"
#include <stdio.h>
void printWhiteMrowka(mr* mrowka, FILE* out);

void printDarkMrowka(mr* mrowka, FILE* out);

void printIterToFile(FILE* out, int wierszy, int kolumny, int** plansha, mr* mrowka);
#endif
