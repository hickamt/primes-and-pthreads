# Primes & Pthreads | Sieve of Eratosthenes

- [GeeksForGeeks Methodology: Sive of Eratosthenes](https://www.geeksforgeeks.org/sieve-of-eratosthenes/)

This lab introduces the implementation of pthreads from the `<pthread.h>` C library. Specifically, this implementation will use a mutex lock and unlock to handle bit manipulation of a bit block. Each bit block is 32-bits and every mask across the bit block will be a non-prime value.

When the process is finished, all prime values up to a given upper_bound will be consoled to screen or written to a file if using verbose mode. Finding the primes is a matter of evaluating each bit block and listing a value associated with the block index and bit index that has not been masked. The implementation is in `write.c`.

## View Program Online: VSCode

<a href="https://vscode.dev/github/hickamt/primes-and-pthreads">
<img src="vscode.png" alt="vscode button" width="auto" height="50px" />
</a>

## Run Program & Command Line Flags

```c
// Example:
$ npm run build && ./primesMT -t 4 -u 1000

// Once the program is built
$ ./primesMT -t # -u #

// Command Line Flags
-t:  flag indicating the number of threads to use
-u:  flag indicating the upper bound, finding primes between [ 0 , upper bound ]
-v:  use verbose mode to see process values for bit block, index, and thread id
-h:  prints a menu of useful information, I hope
```

## Run This Program Using Makefile or NPM

NPM Command Line Arguments:

```c
// Build only
$ npm run build

// Run Quick Test
// finds all primes up to 100,000 using 10 threads
$ npm run dev

// Test for memory leaks
$ npm run valgrind

// Run bash test (takes about 4 - 5 min.)
$ npm run test

// View the simple menu/options
$ npm run menu

// Clean the directory
$ npm run menu
```

## Run the Bash Test

A testPrimes.bash script will run multiple tests from 1 to 30 threads and compute the time and accuracy of this programs implementation.

```c
// Run the Test Bash Script
$ bash testPrimes.bash

```

## Clean Directory

```c
// Make Clean
$ make clean

// npm
$ npm run clean
```

## Output of Test on a Server With 40 Cores

Time Test For Upper Bounds: 100,000 to 1,000,000,000

Upper Bound : Number of Cores : Real Time in Seconds

```c
  100000       1      real 0.02
  100000       2      real 0.02
  100000       3      real 0.02
  100000       5      real 0.01
  100000       7      real 0.01
  100000       9      real 0.01
  100000      12      real 0.01
  100000      16      real 0.01
  100000      20      real 0.01
  100000      25      real 0.01
  100000      30      real 0.01
  1000000      1      real 0.16
  1000000      2      real 0.12
  1000000      3      real 0.11
  1000000      5      real 0.09
  1000000      7      real 0.07
  1000000      9      real 0.07
  1000000     12      real 0.06
  1000000     16      real 0.06
  1000000     20      real 0.05
  1000000     25      real 0.05
  1000000     30      real 0.06
  10000000     1      real 1.86
  10000000     2      real 1.00
  10000000     3      real 0.80
  10000000     5      real 0.62
  10000000     7      real 0.60
  10000000     9      real 0.53
  10000000    12      real 0.45
  10000000    16      real 0.43
  10000000    20      real 0.38
  10000000    25      real 0.39
  10000000    30      real 0.36
  100000000    1      real 38.70
  100000000    2      real 21.51
  100000000    3      real 14.79
  100000000    5      real 9.83
  100000000    7      real 7.78
  100000000    9      real 6.55
  100000000   12      real 5.71
  100000000   16      real 4.92
  100000000   20      real 4.40
  100000000   25      real 4.12
  100000000   30      real 4.13
  1000000000   1      real 180.13
  1000000000   2      real 180.13
  1000000000   3      real 180.13
  1000000000   5      real 134.84
  1000000000   7      real 98.67
  1000000000   9      real 80.06
  1000000000   12     real 67.71
  1000000000   16     real 57.73
  1000000000   20     real 50.63
  1000000000   25     real 46.65
  1000000000   30     real 47.10
```
