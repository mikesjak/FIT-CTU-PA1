# Parking lot

## What to do?

- Create a program to manage a Parking lot
- Firstly add to number to define size of the Parking lot
- Then there will be two functions: + to add a car, - to take a car
#### + function
- In input first number is floor, second is place and string is a number plate
#### - function
- The number plate must be already registered or it will say "Nenalezeno."
- Otherwise it will just take the car away and free the spot.

#### What to check in input scanning
- size of the lot must be defined by two numbers > 0
- only + or - can be called
- In the + function you will have to check if that place isnt taken or if any info isn't missing
- In the - function you will have to check if the car is there or not.

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

- You will fint it in gen.c
- Right now it will generate 500000 lines
- Firstly you need to define the size of the lot

##### How to run it?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
example: 10 55
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```