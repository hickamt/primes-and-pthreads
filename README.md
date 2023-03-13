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

A testPrimes.bash script will run multiple tests from 1 to 20 threads and compute the time and accuracy of this programs implementation.

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
