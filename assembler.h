/*
 * This file includes common system header files, several local header
 * files widely used in the assembler program, and signatures for other
 * commonly used functions.
 */

#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>     /* May need to be _stdlib.h on some machines. */
#include <string.h>    /* Might be memory.h on some machines. */
#include <ctype.h>

#include "LabelTable.h"
#include "getToken.h"
#include "printFuncs.h"
#include "process_arguments.h"
#include "same.h"


int getNTokens(char *instructionBuffer, int N, char *results[]);

void getOpType(char *opcode, char *opType, int *code, int line);

int getRegNbr(char *regName, int line);

int binToDec(char string[], int begin, int end);

int verifyInstrName(char *instr, int line);

int verifyRegName(char *reg, int line, int expected);

void assemblerR(int opcode, char *restOfStmt, int line);

void assemblerI(int opcode, char *restOfStmt, int line);

void assemblerJ(int opcode, char *restOfStmt, int line);

void printBin(int value, int length);

LabelTable sTable;

LabelTable pass1(FILE *fp);

LabelTable pass2(FILE *fp, LabelTable table);


#endif
