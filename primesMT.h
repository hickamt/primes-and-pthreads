#pragma once

#ifndef PRIMESMT_H
#define PRIMESMT_H

#include <stdint.h>
#include <pthread.h>

typedef struct BitBlock_s
{
    uint32_t bits;
    pthread_mutex_t mutex_id;
} BitBlock_t;

void parseCommandLine(int argc, char *argv[]);
unsigned long totalBitBlocks(void);
void allocateBitArray(void);
void flipBitAtIndex(unsigned long, unsigned long);
void verboseFlipBitAtIndex(unsigned long, unsigned long);
void *maskMultiples(void *);
void joinThreads(pthread_t *);
void evaluatePrimes(void);
void getPrimes(void);
void deallocateThreads(pthread_t *);
void deallocateBitArray(void);

#endif // PRIMESMT_H