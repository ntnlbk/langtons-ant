#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ant.h"
#include "field.h"
#include "output.h"
int main(int argc, char** argv){
int i, j;
int wierszy;
int kolumny;
int iteracje;
int kierunek;
char* outName;
bool isAllStepsShow = true;
int option;
char* wierszyCh;
char* kolumnyCh;
char* iteracjeCh;
char* kierunekCh;
char* outNameCh;
bool randomMap = false;
bool inputMap = false;

//inicjalizacja planshy i mrówki
int** plansha;
int wStart;
int kStart;


//parsing arguments
while ((option = getopt(argc, argv, "w:k:i:z:o:lp")) != -1){

	switch(option) {
	
	case 'w':
		wierszyCh = optarg;
		break;
	case 'k':
		kolumnyCh = optarg;
		break;
	case 'i':
		iteracjeCh = optarg;
		break;
	case 'z':
		kierunekCh = optarg;
		break;
	case 'o':
		outNameCh = optarg;
		break;
	case 'l':
		randomMap = true;
		break;
	case 'p':
		inputMap = true;
		break;	
	case '?':
		printf("niewiadomy parametr: %c\n", optopt);
		break;
	case ':':
		printf("nie podano parametru: %c\n", optopt);
		break;
	default:
		wierszyCh = "";
		kolumnyCh = "";
		iteracjeCh = "";
		kierunekCh = "";
		outNameCh = "";
		break;
	}
}

if (inputMap){
printf("Odczytuję mapę z pliku mapa.txt\n");
FILE* in;
in = fopen("mapa.txt", "r");
if (in == NULL){
	printf("nie znaleziono pliku mapa.txt\n");
	printf("zatrzymuję propgram\n");
	return 0;
} else{
	fscanf(in, "%d", &wierszy);
	fscanf(in, "%d", &kolumny);
	printf("wczytana plansha %dx%d\n", wierszy, kolumny);
	plansha = calloc(wierszy, sizeof(int*));
	for (j = 0; j < wierszy; j++){
		plansha[j] = calloc(kolumny, sizeof(int));
	}
	for(i = 0; i< wierszy; i++){
		for (j = 0; j < kolumny; j++){
			fscanf(in, "%d", &plansha[i][j]);
		}
	}
	printf("początkowa pozycja mrówki: ");
	fscanf(in, "%d", &wStart);
	fscanf(in, "%d", &kStart);
	printf("%d, %d\n", wStart, kStart);
}

} else {

	if(wierszyCh != NULL && wierszyCh != ""){
		wierszy = atoi(wierszyCh);
		if(wierszy != 0)
			printf("wierszy: %d\n", wierszy);
		else{
			printf("nieprawidłowy parametr liczby wierszy, przyjmuję wierszy = 300\n");
			wierszy = 300;
		}
	} else {
		printf("nie podano liczbę wierszy, przyjmuję wierszy = 300\n"); 
		wierszy = 300;
	}
	if(kolumnyCh != NULL && kolumnyCh != ""){
		kolumny = atoi(kolumnyCh);
		if(kolumny != 0)
			printf("kolumny: %d\n", kolumny);
		else{
			printf("nieprawidłowy parametr liczby kolumny, przyjmuję kolumny = 300\n");
			kolumny = 300;
		}
	} else {
		printf("nie podano liczbę kolumn, rzyjmuję kolumny = 300\n"); 
		kolumny = 300;
	}

	if(randomMap){
		printf("Generuję planshę z losowo ustawionymi czarnymi polami i losuję pozycję mrówki\n");
		srand(time(NULL));
		
		plansha = calloc(wierszy, sizeof(int*));
		for (j = 0; j < wierszy; j++){
			plansha[j] = calloc(kolumny, sizeof(int));
		}
		for(i = 0; i< wierszy; i++){
			for (j = 0; j < kolumny; j++){
				bool rand_bool = rand() & 1;
				if(rand_bool)
					plansha[i][j] = 1;
			}
		}
		printf("początkowa pozycja mrówki: ");
		wStart = ((rand() % wierszy) + 1);
		kStart = ((rand() % kolumny) + 1);
		printf("%d, %d\n", wStart, kStart);
	} else{
		printf("Generuję pustą planshę, mrówka znajduję się w środku\n");
		plansha = calloc(wierszy, sizeof(int*));
		for (j = 0; j < wierszy; j++){
			plansha[j] = calloc(kolumny, sizeof(int));
		}
		printf("początkowa pozycja mrówki - środek planszy: ");
		wStart = wierszy % 2 == 0 ? wierszy / 2 : (wierszy-1) / 2;
		kStart = kolumny % 2 == 0 ? kolumny / 2 : (kolumny-1) / 2;
		printf("%d, %d\n", wStart, kStart);

	}

}

if(iteracjeCh != NULL && iteracjeCh != ""){
	iteracje = atoi(iteracjeCh);
	if(iteracje != 0)
		printf("iteracje: %d\n", iteracje);
	else{
		printf("nieprawidłowy parametr liczby iteracji, przyjmuje 25000\n");
		iteracje = 25000;
	}
} else {
	printf("nie podano parametru liczby iteracji, przyjmuję 25000\n");
	iteracje = 25000;
}
if(iteracje > 150){
	printf("Liczba iteracji jest większa od 150, więc nie będę wypisywał wszystkie iteracje do plików.\n");
	printf("Wypiszę tylko pierwszą i ostatnią iterację\n");
	isAllStepsShow = false;
}
if(kierunekCh != NULL && kierunekCh != ""){
	kierunek = atoi(kierunekCh);
	if(kierunek >= 0 && kierunek <= 3)
		printf("kierunek: %d\n", kierunek);
	else{
		printf("nieprawidłowy parametr kierunku, przyjmuje 0(góra)\n");
		kierunek = 0;
	}
} else {
	printf("nie podano parametru kierunku, przyjmuje 0(góra)\n");
	kierunek = 0;
}
if(outNameCh != NULL && outNameCh != ""){
	outName = outNameCh;
	printf("pliki wynikowe mają nazwę: %s_<nr.iteracji>iteracja\n", outName);
} else {
	outName = "";
	printf("nie podano parametru przedrostku plików wynikowych, przyjmuje <nr.iteracji>iteracja\n");
}



printf("kierunek mrówki: ");

switch(kierunek){
	case 0: 
		printf("góra(%d)\n", kierunek);
		break;
	case 1: 
		printf("prawo(%d)\n", kierunek);
		break;
	case 2:
		 printf("dół(%d)\n", kierunek);
		 break;
	case 3: 
		printf("lewo(%d)\n", kierunek);
		break;
}

mr mrowka = {kierunek, wStart-1, kStart-1, wierszy-1, kolumny-1};
if (isAllStepsShow){
	for (i = 0; i< iteracje; i++){
	char filename[sizeof(outName) + 30];
	strcat(filename, outName);
	strcat(filename, "_");
	char temp[50000];
	sprintf(temp, "%d", i);
	strcat(filename, temp);
	strcat(filename, "iteracja");
	FILE *out = fopen(filename, "w");
	printIterToFile(out, wierszy, kolumny, plansha, &mrowka);
	fclose(out);
	filename[0] = '\0';
	step(&mrowka, plansha);
	}
} else {
	char filename[sizeof(outName) + 30];
	strcat(filename, outName);
	strcat(filename, "_iteracja 0");
	FILE *out = fopen(filename, "w");
	filename[0] = '\0';
	printIterToFile(out, wierszy, kolumny, plansha, &mrowka);
	fclose(out);
	for (i = 0; i< iteracje; i++){
	step(&mrowka, plansha);
	}
	strcat(filename, outName);
	strcat(filename, "_iteracja końcowa");
	out = fopen(filename, "w");
	filename[0] = '\0';
	printIterToFile(out, wierszy, kolumny, plansha, &mrowka);
	fclose(out);
}


for (j = 0; j < wierszy; j++){
	free(plansha[j]);
}
free(plansha);

return 0;
}
