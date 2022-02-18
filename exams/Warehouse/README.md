# Warehouse

- code.c je naivní řešení
- binarySearch.c používá binary search

## Zadání
- Napsat program, který řídí sklad
- 3 funkce +, -, ?
- Kód produktu nesmí být delší než 100 znaků
- Počet vstupů je omezen na 100000

#### + funkce
```md
+ kod počet
```
- Přidá 'počet' zboží
#### - function
```md
- kod počet
```
- odebere 'počet' zboží
#### ? function
```md
? kod
```
- Napíše aktuální množstí

## Basic showcase
##### Input
```md
+ 123 1
+ 123 1
+ 244 5
+ 122 1
- 123 2
- 123 1
? 123
? 244
- 244 6
? 244
```
##### Output
```md
Prikazy:
Vytvoreno.
Pridano.
Vytvoreno.
Vytvoreno.
Odebrano.
Nedostatek zbozi.
Kusu: 0.
Kusu: 5.
Nedostatek zbozi.
Kusu: 5.
```
### Input generator

- Soubor gen.c
- Generuje 99999 řádek

##### Jak to spustit?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```