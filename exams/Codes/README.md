# EAN codes


## Zadání
- Napsat program, který načte neomezeně mnoho kódů
- Po veškerém načtení, program vypíše 10 nejčastěji vyskytovaných kódů

#### Ošetření vstupů

- Kód může mít <5,100> znaků

## Basic showcase
##### Input
```md
02345
23456
02345
02345
12366
```
##### Output
```md
02345 3x
23456 1x
12366 1x
```
### Generátor vstupu

- Soubor gen.c
- Generuje 100000 řádek
- Generuje pouze 5-6 místné kódy

##### Jak to spustit?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```