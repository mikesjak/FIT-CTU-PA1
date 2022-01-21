# EAN codes


## What to do?
- Create a program that get unlimited amount of codes
- After the input is finished, you have to print 10 codes with the biggest amount

- Prints current amount of goods
#### What to check in input scanning

- Code can has <5,100> chars

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
### Input generator

- You will fint it in gen.c
- Right now it will generate 100000 lines
- It only creates good inputs with the lenght of 6 chars max

##### How to run it?

```md
g++ -Wall -pedantic gen.c -o gen.out
./gen.out > in.txt
g++ -Wall -pedantic code.c -fsanitize=address -g
./a.out < in.txt
```