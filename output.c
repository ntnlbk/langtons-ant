#include "output.h"
void printWhiteMrowka(mr* mrowka, FILE* out){
	switch(mrowka->kierunek){
		case 0: 
			fprintf(out, "│△│");
			break;
		case 1: 
			fprintf(out, "│▷│");
			break;
		case 2: 
			fprintf(out, "│▽│");
			break;
		case 3: 
			fprintf(out, "│◁│");
			break;
	}
	
}
void printDarkMrowka(mr* mrowka, FILE* out){
	switch(mrowka->kierunek){
		case 0: 
			fprintf(out, "│▲│");
			break;
		case 1: 
			fprintf(out, "│▶│");
			break;
		case 2: 
			fprintf(out, "│▼│");
			break;
		case 3: 
			fprintf(out, "│◀│");
			break;
	}
	
}
void printIterToFile(FILE* out, int wierszy, int kolumny, int** plansha, mr* mrowka){
int i, j;
for (i = 0; i< wierszy; i++){
	for(j=0; j< kolumny; j++){
		if(mrowka->aktualnyWiersz == i && mrowka->aktualnaKolumna == j){
			if(plansha[i][j] == 0)
				printWhiteMrowka(mrowka, out);
			else
				printDarkMrowka(mrowka, out);
			
		} else {
			if(plansha[i][j] == 0)
				fprintf(out, "│ │");
			else
				fprintf(out, "│█│");
			}
		
		}
	fprintf(out, "\n");
}
fprintf(out, "\n");
}
