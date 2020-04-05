# Prime Number Finder

A program that finds the prime numbers between 2 and the given number M by using the T number of threads.

## How to compile?

```bash
g++ -fopenmp main.cpp
```

## How to run?

```bash
./a.out M T
```

### Example

```bash
./a.out 100000000 64
Greatest prime smaller than or equal to 100000000 is 99999989
Time taken by the program is 8.260846 seconds
```

## What does it output?

It outputs the greatest prime number smaller than or equal to M and the execution time of the program.

To print all the prime numbers up to and including M, remove the block comment that covers the lines 118-122. 


## How to change the scheduling method?

Go to line number 73 in the source file. Then change the pragma clause by specifying the scheduling method and the block size. 

## What is prepopulated results.csv and results.pdf file?

It contains the performance results of the program for different intervals, number of threads, scheduling methods and block sizes. See results.pdf for colored version of results.csv.

## What was the machine specification?

The machine had 64 virtual CPUs and 240 GB ram. There were acutally 32 physical CPUs each with 2 cores. CPU model was Intel Xeon and had 2.3 GHz clock rate. The virtual machine was created in Google Cloud.

## License
[MIT](https://choosealicense.com/licenses/mit/)
