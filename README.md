# Prime Number Finder

A program that finds the prime numbers between 2 and the given number M by using T number of threads and scheduling method SM with specified chunk size CS.

## How to compile?

```bash
g++ -fopenmp main.cpp
```

## How to run?

```bash
./a.out M [T [SM [CS]]]
```

### SM Values: <br>
1 -> Static <br>
2 -> Dynamic <br>
3 -> Guided <br>
4 -> Auto <br>

### Example

```bash

# run only by specifying M [T=1, SM = auto, CS = default]
./a.out 100000000 

# run specifying by M and T [SM = auto, CS = default]
./a.out 100000000 64

# run specifying by M, T and SM [CS = default]
./a.out 100000000 64 2

# run specifying by M, T, SM anc CS
./a.out 100000000 64 2 10000

```

## What does it output?

Program finds the prime numbers by using the specified parameters and writes them to the primes.txt file. <br>
Then it calculates for different combinations of specified parameters and write calculation results to results.txt file. <br>
The first step will probably be completed shorthly but the second step may take a while so be patient. 

### Example Output
```bash
./a.out 10000 2

1229 prime numbers found in the interval [2,10000].
Calculation time is 0.002990 seconds.
Check the created primes.txt file to see found prime numbers!

Waiting for result.txt file to be created!
M,Openmp Loop Scheduling Method,Chunk Size,,T1,T2,S2
10000,1,1,0.002990000,0.000997000,2.998996991
10000,1,10,0.001993000,0.000998000,1.996993988
10000,1,100,0.000997000,0.001997000,0.499248873
10000,1,1000,0.000997000,0.000996000,1.001004016
10000,2,1,0.001995000,0.001994000,1.000501505
10000,2,10,0.000997000,0.000996000,1.001004016
10000,2,100,0.001993000,0.001995000,0.998997494
10000,2,1000,0.000999000,0.000997000,1.002006018
10000,3,1,0.000999000,0.001000000,0.999000000
10000,3,10,0.000998000,0.000997000,1.001003009
10000,3,100,0.001992000,0.001994000,0.998996991
10000,3,1000,0.000995000,0.000996000,0.998995984
10000,4,1,0.001407000,0.001997000,0.704556835
10000,4,10,0.001993000,0.000997000,1.998996991
10000,4,100,0.001996000,0.001994000,1.001003009
10000,4,1000,0.002993000,0.001998000,1.497997998
Check the created results.txt file to see calculation results!
```

## What is prepopulated results.csv and results.pdf file?

It contains the performance results of the program for different intervals, number of threads, scheduling methods and block sizes. See results.pdf for colored version of results.csv.

## What was the machine specification?

The machine had 64 virtual CPUs and 240 GB ram. There were acutally 32 physical CPUs each with 2 cores. CPU model was Intel Xeon and had 2.3 GHz clock rate. The virtual machine was created in Google Cloud.

## License
[MIT](https://choosealicense.com/licenses/mit/)
