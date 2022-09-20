/**
 * LabelTable pass2 (FILE * fp, LabelTable table)
 *      @param  fp  pointer to an open file (stdin or other file pointer)
 *                  from which to read lines of assembly source code
 *      @param  table  an existing Label Table
 *      @return a newly-created table containing labels found in the
 *              input file, each with the address of the instruction
 *              containing it (assuming the first line of input
 *              corresponds to address 0)
 *
 *  The second pass does the actual
 *  translation from assembly to machine language.
 *  The machine language output should be in the same format
 *  as the input for your disassembler program,
 *  i.e., each line should contain 32 characters
 *  representing the 32 bits of a single machine instruction.
 *
 * Author: Thanh Vu, Daniel Alspector-Kelly
 * Date:   02/15/2020
 *
 * Modified:  
 *      02/15/2020 - Implementing getOpType and getNbr
 *      02/17/2020 - Fixed duplicate verifyInstrName calls
 */

#include "assembler.h"

/**
 *
 * @param instName
 * @param restOfInstruction
 * @param lineNum
 * @param PC
 */

LabelTable pass2(FILE *fp, LabelTable table)
/* returns a copy of the label table that was constructed */
{
    int lineNum;                /* line number */
    int PC;                     /* program counter */
    char *tokBegin, *tokEnd;     /* used to step thru inst */
    char inst[BUFSIZ];           /* will hold instruction; BUFSIZ
                                      is max size of I/O buffer
                                      (defined in stdio.h) */
    char *instrName;              /* instruction name (e.g., "add") */
    char opType;
    int code;
    char *regName;
    char *restOfStatement;
    sTable = table;



    /* Continuously read next line of input until EOF is encountered.
     */
    for (lineNum = 1, PC = 0; fgets(inst, BUFSIZ, fp); lineNum++, PC += 4) 
    {
        /* If the line starts with a comment, move on to next line.
         * If there's a comment later in the line, strip it off
         *  (replace the '#' with a null byte).
         */
        if (*inst == '#') continue;
        (void) strtok(inst, "#");

        /* Read the first token, skipping any leading whitespace. */
        tokBegin = inst;
        getToken(&tokBegin, &tokEnd);
        /* tokBegin now points to 1st non-whitespace character
         * in the token and tokEnd points to 1st punctuation mark
         * or whitespace after the end of the token.
         */

        /* Skip label, if any */
        if (*(tokEnd) == ':') 
        {
            /* Line has a label!  Get new token! */
            tokBegin = tokEnd + 1;
            getToken(&tokBegin, &tokEnd);
        }

        /* If empty line or line containing only a label, get next line */
        if (*tokBegin == '\0')
            continue;

        /* We have a valid token; turn it into a string and set
         * tokBegin to point to the character after the end.
         */
        *tokEnd = '\0';
        instrName = tokBegin;
        restOfStatement = tokEnd + 1;  /* starts after end of opcodeString */

        regName = "$t1";
        printDebug("The reg number we are looking for: %d \n", getRegNbr(regName, lineNum));
        printDebug("Name of instrName before calling getOpType: %s \n", instrName);

        //printDebug("Checking if match (0 = not match, 1 = match): %d\n", verifyInstrName(instrName, lineNum));
//        processInstruction(instrName, tokBegin, lineNum, PC);

        if (verifyInstrName(instrName, lineNum) == 1) 
        {
            getOpType(instrName, &opType, &code, lineNum);

            printDebug("============AFTER CALLING FUNCTION:\n\n");
            printDebug("Name of instrName after: %s \n", instrName);
            printDebug("Type Name is: %c\n", opType);
            printDebug("Type Code is: %d\n", code);



            printDebug("The rest of statements are: %s\n", restOfStatement);


            if (opType == 'R') 
            {
                assemblerR(code, restOfStatement, lineNum);
            }

            if (opType == 'J') 
            {
                assemblerJ(code, restOfStatement, lineNum);
            }
            if (opType == 'I') 
            {
                assemblerI(code, restOfStatement, lineNum);
            }

        }
    }



    /* EOF */
    (void) fclose(fp);
    return table;

}

