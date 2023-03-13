// Instructor ~ R. Jesse Chaney | rchaney@pdx.edu
// Program By: Todd Hickam | Primes and Pthreads | CS 333 Winter Term 2023
// Allowed Option of Implementation: Static or Dynamic
// Chosen Implementation: Sieve of Erotosthenes with dynamic thread processing

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <values.h>
#include <math.h>
#include <sys/time.h>
#include <getopt.h>
#include "primesMT.h"
#include "write.h"

#define GET_START_INDEX(_tid) (3 + (2 * _tid))
#define INCREMENT_INDEX(_thread_index, _num_threads) (_thread_index + (2 * _num_threads))

BitBlock_t *bitArray; // creat threads call does not appear to allow function(arguments)
const unsigned long NUM_BITS = 32;
unsigned long upper_bound = 10240;            // find primes up to this value inclusive
unsigned long num_threads = 1;                // unsigned long (n) pthreads, default = 1
unsigned long number_bit_blocks = 0;          // number of blocks to hold upper bound prime number request
unsigned long square_root_of_upper_bound = 0; // sqrt(upper_bound) pthread stop condition
uint16_t verbose_mode = 0;                    // used to allow console out of bit array values

unsigned long totalBitBlocks(void)
{
  return (upper_bound / NUM_BITS) + 1;
}

void parseCommandLine(int argc, char *argv[])
{
  unsigned long temp = 0;
  int opt;
  number_bit_blocks = totalBitBlocks();
  square_root_of_upper_bound = sqrt(upper_bound) + 1;

  while ((opt = getopt(argc, argv, "t:u:hv")) != -1)
  {
    switch (opt)
    {
    case 't': // number of threads
      if ((temp = strtoul(optarg, NULL, 10)) > num_threads)
      {
        num_threads = temp;
      }
      break;
    case 'u': // upper bound
      upper_bound = strtoul(optarg, NULL, 10);
      square_root_of_upper_bound = sqrt(upper_bound) + 1;
      number_bit_blocks = totalBitBlocks();
      break;
    case 'v': // verbose mode
      ++verbose_mode;
      fprintf(stderr, "\nVerbose Mode Initiated\n");
      break;
    case 'h': // menu
      help_menu();
      exit(EXIT_SUCCESS);
      break;
    default:
      fprintf(stderr, "Well, that was unexpected: \n");
      break;
    }
  }
}

void allocateBitArray(void)
{
  bitArray = (BitBlock_t *)calloc(number_bit_blocks, sizeof(BitBlock_t));
  for (unsigned long index = 0; index < number_bit_blocks; ++index)
  {
    pthread_mutex_init(&(bitArray[index].mutex_id), NULL);
  }
}

void verboseFlipBitAtIndex(unsigned long bit_index, unsigned long block_index)
{
  fprintf(stderr, "\nMasking Bit:\t%lu\t In Block:\t%lu", bit_index, block_index);
  pthread_mutex_lock(&bitArray[block_index].mutex_id);
  bitArray[block_index].bits |= (1 << bit_index);
  pthread_mutex_unlock(&bitArray[block_index].mutex_id);
}

void flipBitAtIndex(unsigned long bit_index, unsigned long block_index)
{
  pthread_mutex_lock(&bitArray[block_index].mutex_id);
  bitArray[block_index].bits |= (1 << bit_index);
  pthread_mutex_unlock(&bitArray[block_index].mutex_id);
}

void *maskMultiples(void *thread_id)
{
  if (verbose_mode)
  {
    for (unsigned long thread_index = GET_START_INDEX((unsigned long)thread_id); thread_index <= square_root_of_upper_bound; thread_index = INCREMENT_INDEX(thread_index, num_threads))
    {
      fprintf(stderr, "\n\nFor Thread ID:\t%lu\tMasking Thread Index:\t%lu ", (unsigned long)thread_id, thread_index);
      for (unsigned long bit_index = (thread_index + thread_index); bit_index <= upper_bound; bit_index += thread_index)
      {
        verboseFlipBitAtIndex(bit_index % NUM_BITS, bit_index / NUM_BITS);
      }
    }
  }
  else
  {
    for (unsigned long thread_index = GET_START_INDEX((unsigned long)thread_id); thread_index <= square_root_of_upper_bound; thread_index = INCREMENT_INDEX(thread_index, num_threads))
    {
      for (unsigned long bit_index = (thread_index + thread_index); bit_index <= upper_bound; bit_index += thread_index)
      {
        flipBitAtIndex(bit_index % NUM_BITS, bit_index / NUM_BITS);
      }
    }
  }
  pthread_exit(EXIT_SUCCESS);
}

void joinThreads(pthread_t *threads)
{
  for (unsigned long thread_id = 0; thread_id < num_threads; ++thread_id)
  {
    if (pthread_join(threads[thread_id], NULL) != 0)
    {
      fprintf(stderr, "\npthread_join() error\n");
      exit(1);
    }
  }
}

void evaluatePrimes(void)
{
  pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
  for (unsigned long thread_id = 0; thread_id < num_threads; ++thread_id)
  {
    if (pthread_create(&threads[thread_id], NULL, maskMultiples, (void *)thread_id) != 0)
    {
      fprintf(stderr, "\npthread_create() error\n");
      exit(1);
    }
  }
  joinThreads(threads);
  deallocateThreads(threads);
}

void getPrimes(void)
{
  if (verbose_mode)
  {
    fprintf(stderr, "\n\n*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
    fprintf(stderr, "\nPrime Numbers Have Been Written To File: primes.txt\n");
    fprintf(stderr, "\n*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n");
    for (unsigned long current_value = 3; current_value <= upper_bound; current_value += 2)
    {
      writePrimesToFile(bitArray[(current_value / NUM_BITS)].bits, current_value % NUM_BITS, current_value);
    }
  }
  else
  {

    printf("2\n");
    for (unsigned long current_value = 3; current_value <= upper_bound; current_value += 2)
    {
      consolePrimes(bitArray[(current_value / NUM_BITS)].bits, current_value % NUM_BITS, current_value);
    }
  }
}

void deallocateThreads(pthread_t *threads)
{
  if (threads)
    free(threads);
}

void deallocateBitArray(void)
{
  if (bitArray)
    free(bitArray);
}

int main(int argc, char *argv[])
{
  parseCommandLine(argc, argv);
  allocateBitArray();
  evaluatePrimes();
  getPrimes();
  deallocateBitArray();
  return EXIT_SUCCESS;
}