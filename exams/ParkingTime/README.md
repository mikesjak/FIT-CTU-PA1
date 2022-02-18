# Parking prize

## Zadání
- Napiště program, který počítá cenu parkovného
```md
Cenník:
time <= 30 min -> $0
time > 30 <= 60 min -> $30
time > 60 min <= 1 den -> $40 za každou začatou hodinu
time > 1 den -> $1000 za každý začatý den
```

#### + funkce
- Uloží SPZ auta a čas příjezdu
#### - function
- Auto odjíždí -> spočte cenu
#### = function
- Musí být 0:00
- Znamená začátek nového dne
#### Ošetření vstupů
- nejde se zpátky v čase
- správný formát
- pouze 3 funkce mohou být volány

## Basic showcase
```md
Log:
7:00 + CAR1
OK
7:10 + CAR2
OK
7:20 + CAR3
OK
7:20 + CAR4
OK
7:33 - CAR2
RZ: CAR2, cena: 0
7:50 + CAR5
OK
8:10 - CAR4
RZ: CAR4, cena: 30
9:00 + CAR2
OK
9:20 + CAR6
OK
9:21 - CAR3
RZ: CAR3, cena: 120
0:00 =
8:15 - CAR1
RZ: CAR1, cena: 2000
8:25 - CAR3
Nenalezeno
8:45 + CAR7
OK
Pocet automobilu v garazi: 4
```
```md
Log:
7:00 + CAR1
OK
0:00 =
0:00 =
5:00 + CAR2
OK
0:00 =
5:00 + CAR3
OK
0:00 =
4:00 + CAR4
OK
0:00 =
3:00 + CAR5
OK
6:00 - CAR1
RZ: CAR1, cena: 5000
10:01 - CAR2
RZ: CAR2, cena: 4000
10:03 - CAR3
RZ: CAR3, cena: 3000
10:04 - CAR4
RZ: CAR4, cena: 2000
10:05 - CAR5
RZ: CAR5, cena: 320
8:22 + VEHICLE
Nespravny vstup.
```
```md
Log:
5:30+CAR1
OK
12:00                    -                  CAR1
RZ: CAR1, cena: 280
14:15 * CAR3
Nespravny vstup.
```