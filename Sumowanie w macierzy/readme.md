# Sumowanie w macierzy

Link do zadania: [spoj.com](https://pl.spoj.com/problems/SUMMATRX/)

## Polecenie
Dana jest macierz NxN.
Będziesz poproszony o przetworzenie następujących zapytań :
SET x y val
SUM x1 y1 x2 y2
Gdzie SET: ustawia komórkę x,y w macierzy na wartość val.
SUM: sumuje prostokąt w macierzy ograniczony lewym dolnym wierzchołkiem x1;y1 oraz górnym prawym wierzchołkiem x2;y2 tego prostokąta

Pierwsza linia zawiera liczbę T, liczbę testów(T<=10)

Pierwsza linia każdego testu wejścia stanowi liczba N: wymiar macierzy. (N<1024)

Następnie w nieokreślonej liczbie linii jest podana komenda SUM, SET lub END.

Po poleceniu SET podane będą 3 wartości : x,y,val

Po poleceniu SUM podane będą 4 wartości : x1,y1,x2,y2

Komórki podawane w poleceniach są z przedziału <0;n)

Typ int wystarczy, aby wykonać wszystkie operacje.

Polecenie END odpowiada końcowi testu.

Dla każdego polecenia SUM wypisz wynik oddzielając je znakiem nowej linii.

## Wejście
1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END

## Wyjście
1
12
12
13