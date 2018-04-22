# Opis zadania
Dla danej struktury gór znaleźć największą dolinę, którą można wypełnić największą ilością wody.
Struktura gór jest zakodowana poprzez ciąg nieujemnych liczb całkowitych. Odpowiedzią jest
pojedyncza nieujemna liczba całkowita, która jest równa objętości wody mogącej wypełnić
największą dolinę.

# Przykłady
Dla danych wejściowych
```
1 0 3 5 4 0 1 2 1 3 0 1 2 0 1
```
struktura gór wygląda następująco:
```
      |T|
      |T|T|
    |T|T|T|       |T|
    |T|T|T|   |T| |T| |T|
|T| |T|T|T| |T|T|T|T| |T|T| |T|
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
```
W wyniku powinniśmy otrzymać wartość 8, dla doliny pokazanej na rysunku poniżej.

```
      |T|
      |T|T|
    |T|T|T|- - - -|T|
    |T|T|T|- -|T|-|T| |T|
|T| |T|T|T|-|T|T|T|T| |T|T| |T|
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
```
Dla danych
```
6 5 4 3 2 1
```
Wynik powinien wynosić 0, jako że dane nie reprezentują żadnej doliny.
```
|T|
|T|T|
|T|T||T|
|T|T||T||T|
|T|T||T||T||T|
|T|T||T||T||T||T|
TTTTTTTTTTTTTTTTT
```
