#include <stdio.h>
#include <unistd.h>
#include "write.h"

// prints the unsigned binary representation of the (bin) value
// up to 32-bits. (e.g. 0000 0000 0000 0000 0101 1010 0101 1010)
// index ( i ) begins at 31 LEFT SIDE and decrements toward 0
// Used to validate that the correct bits are flipped
void printBinary(const unsigned long bin)
{
    unsigned binsize = (sizeof(bin) * 4) - 1;
    unsigned i = 0;
    unsigned short pad = 4;
    unsigned short count = 0;
    for (i = 1 << binsize; i > 0; i = i / 2)
    {
        (bin & i) ? printf("1") : printf("0");
        if (++count == pad)
        {
            printf(" ");
            pad += 4;
        }
    }
    printf("\n");
}

void writePrimesToFile(const unsigned long bit_block, unsigned long verify_index, unsigned long current_value)
{
    FILE *fp = fopen("primes.txt", "a");
    fprintf(fp, "%d\n", 2);
    if (((bit_block & (1 << verify_index)) >> verify_index) == 0)
    {
        fprintf(fp, "%lu\n", current_value);
    }
    fclose(fp);
}

// Validates given bit block against a bit index from the RIGHT side for ZERO
void consolePrimes(const unsigned long bit_block, unsigned long verify_index, unsigned long current_value)
{
    if (((bit_block & (1 << verify_index)) >> verify_index) == 0)
    {
        printf("%lu\n", current_value);
    }
}

void help_menu(void)
{
    printf("\n\x1b[94mPrime Numbers using the Sieve of Eratosthenes method:\x1b[0m"
           "\n> \x1b[94mCL Example:\x1b[0m\t\t[ $ ./primesMT -t 4 -u 1024 ]"
           "\n> \x1b[94m-t\x1b[0m\t\t\t[ indicates the number of threads ( 0, 40 ) ]"
           "\n> \x1b[94m-u\x1b[0m\t\t\t[ find all prime numbers up to: -u number ]"
           "\n> \x1b[94m-v\x1b[0m\t\t\t[ verbose, helpful print of values during execution ]"
           "\n> \x1b[94m-h\x1b[0m\t\t\t[ help menu, which you are reading ]"
           "\n\n\x1b[32mMakefile Commands\x1b[0m:"
           "\n$ \x1b[94mmake\x1b[0m\t\t\t[ creates the executable (psush) and .o ]"
           "\n$ \x1b[94mmake all\x1b[0m\t\t[ same as make, no other program besides psush in this directory ]"
           "\n$ \x1b[94mmake clean\x1b[0m\t\t[ removes *.o, *.txt, and psush.exe ]"
           "\n$ \x1b[94mmake cls\x1b[0m\t\t[ short for $ make clean, for lazy coders :> ]"
           "\n$ \x1b[94mmake canvas\x1b[0m\t\t[ cleans directory & builds the username-directory-execname.tar.gz ]"
           "\n$ \x1b[94mmake ci\x1b[0m\t\t[ builds RCS revisioning directory if !found, lazy save ]\n\n");
}
