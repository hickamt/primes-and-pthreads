#pragma once

#ifndef WRITE_H
#define WRITE_H

void printBinary(const unsigned long);
void writePrimesToFile(const unsigned long bit_block, unsigned long verify_index, unsigned long current_value);
void consolePrimes(const unsigned long bit_block, unsigned long verify_index, unsigned long current_value);
void help_menu(void);

#endif // WRITE_H