# Warehouse

- code.c is slower version, naive
- binarySearch.c is way faster, has binary search inplemented

## What to do?
- Create a program to manage a warehouse
- You have to create 3 functiong +, -, ?
- Code of the product cannot be longer that 100 chars
- Amount of input is limited to 100000

#### + function
```md
+ code amount
```
- Adds amount of goods
#### - function
```md
- code amount
```
- Takes amount of goods
#### ? function
```md
? code
```
- Prints current amount of goods
#### What to check in input scanning


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

- You will fint it in gen.c
- Right now it will generate 99999 lines
- Firstly you need to define the size of the lot

##### How to run it?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
example: 10 55
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```