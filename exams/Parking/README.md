# Parking lot

## What to do?

- Napsat program, který řídí parkoviště
- Dostane 2 čísla, která definují velikost parkoviště (počet pater, míst)
- 2 funkce: + přijet, - odjet
#### + funkce
- Čísla reprezentují patro a místo, string je SPZ
#### - function
- Auto se zde musí nacházet, aby mohlo odjet. Jinak -> "Nenalezeno."
- Pokud se zde auto nachází a uvolní se místo.

#### Ošetření vstupu
- Místo musí být definováno 2 číslama a musí existovat
- Volány mohou být pouze funkce + a -
- V + funkci se musí zkontrolovat obsazenost místa a SPZ
- V - funkci se musí zkontrolovat, zda dané auto je v parkovišti

## Basic showcase
```md
Velikost:
10 20
Pozadavky:
+ 0 0 987ABC21
OK
+ 5 7 ABC1234
OK
+ 9 11 XYZ987A
OK
+ 5 8 129X98X
OK
- ABCDEF
Nenalezeno
- XYZ987A
OK
- XYZ987A
Nenalezeno
+ 9 11 OPRSTUV
OK
+ 9 11 KLMN32112
Obsazeno OPRSTUV
+ 10 3 AAAA666
Nespravny vstup.
```
```md
Velikost:
4 5
Pozadavky:
 + 2 3 TEST123
OK
- TEST12345
Nenalezeno
* 65ABCD
Nespravny vstup.
```

### Input generator

- Soubor gen.c
- Generuje 500000 řádek
- Je nutno zadat velikost parkoviště

##### How to run it?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
10 55
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```