Kompilacja: make

Wywołanie:
./a.out [podane argumnety]

argumenty:
-w - liczba wierzchołków
-k - liczba kolumn
-i - liczba iteracji (kroków)
-z - kierunek (od 0 - w górę do 3 - w lewo)
-o - przedrostek plików wynikowych
-l – podajemy jeżeli chcemy wylosować planshę
-p - wczytaj pole z pliku mapa.txt. Format pliku - najpierw podawane są rozmiary pola, następnie macierz z 0 i 1 - pole z białymi i czarnymi komórkami odpowiednio, a potem położenie mrówki.


-w - liczba wierzchołków
Jeśli podajemy jako argument: ./a.out -w 32
To program generuje pole z 32-oma wierszami. Ale jeśli nie ma podanego argumentu -w - pole będzie mieć 300 wiersze(automatycznie)

-k - liczba kolumn
Jeśli podajemy jako argument: ./a.out -k 25
To program generuje pole z 25 kolumnami . Ale jeśli nie ma podanego argumentu -k - pole będzie mieć 300 kolumn(automatycznie)


Przykłady:
./a.out -w 35 -k 12
Program wygeneruje pole 35x12
./a.out -k 12
Program wygeneruje pole 300x12
./a.out -w 56
Program wygeneruje pole 56x300
./a.out
Program wygeneruje pole 300x300

-i - liczba iteracji (kroków)
Jeśli podany jako argument: ./a.out -i 500
To mrówka zrobi 500 kroków(przejść)
Jeżeli nie ma argumentu
to mrówka zrobi 25000 kroków(przejść)
Przykład: ./a.out -i 900
Mrówka zrobi 900 kroków

-z - kierunek (od 0 - w górę do 3 - w lewo)
   
w górę: -z 0
w prawo: -z 1 
w dół: -z 2
w lewo: -z 3

Jeżeli podany jako argument: ./a.out -z 3
To w tym przypadku mrówka na początku będzie zwrócona w lewo
Jeżeli nie ma argumentu:
To mrówka automatycznie będzie zwrócona w górę(0)
Przykład:
./a.out -z 1
Mrówka zwrocona w prawo
./a.out
Mrówka zwrocona w górę

-o - przedrostek plików wynikowych
Parametr pozwala zmienić przedrostek plików wynikowych(plików do których będą wypisany kolejne iteracje mrówki)
Jeżeli argument podany: ./a.out -o test -i 10
To generują się pliki test_0iteracja test_1iteracja test_2iteracja.... test_9iteracja (bo kroków 10)
Ale jeżeli liczba iteracji będzie większa od 150 to generują tylko 2 pliki: początkowa i ostatnia iteracja
Jeżeli nie podano argumentu to program będzie automatycznie nazywać pliki <nr.iteracji>iteracja(jeżeli i<150)

lub "_iteracja 0" i "_iteracja końcowa"(i>150)

Przykład:
./a.out -i 14 -o sfc
sfc_0iteracja sfc_1iteracja sfc_2iteracja....sfc_13iteracja
./a.out -o yt
"yt_itreacja 0", "yt_iteracja końcowa"
./a.out -i 56
_1iteracja _2iteracja _3iteracja... _55iteracja

-l - podaj bez argumentu, jeśli chcesz wygenerować losowe pole i wylosować początkową pozycję mrówki.
Przykład:
./a.out -l Generuje losową planszą 300x300
./.a.out -l -w 23 Generuje losową planszą 23x300

-p - wczytaj pole z pliku mapa.txt. Format pliku - najpierw podawane są rozmiary pola, następnie macierz z 0 i 1 - pole z białymi i czarnymi komórkami odpowiednio, a potem położenie mrówki.
Przykład: ./a.out -p (przypuszczamy że w pliku znaiduje się to: 2 3  )
								1 0 1
								0 1 0
								1 2
Geneiruje planszę o rozmiarich 2x3 i mrówka znaiduje się w punkcnie(1, 2)
czarny    biały  czarny
[mrówka]  czarby biały


Przykład wywołania: ./a.out -i 37 -w 89 -k 34 -z 2 -o start
Generuje planszę o rozmiarach 89x34
mrówka zwrocona na dół
Wykonuje 37 kroków
start_0iteracja start_1iteracja start_2iteracja start_3iteracja .... start_36iteracja 
