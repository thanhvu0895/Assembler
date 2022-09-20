/*
 * Test Driver to test the assembler.
 *
 * This program reads lines from a file.  For each line, the program
 *      calls pass1 to get the labels from the file and store them in a table,
 *      and then calls pass2 to do the actual
 *      translation from assembly to machine language.
 *
 * Usage:
 *          name [ filename ] [ 0|1 ]
 *      where "name" is the name of the executable, "filename" is an
 *      optional file containing the input to read, and " 0" or
 *      "1" specifies that debugging should be turned off or on,
 *      respectively, regardless of any calls to debug_on, debug_off,
 *      or debug_restore in the program.  Both arguments are optional;
 *      if both are present they may appear in either order.  If no
 *      filename is provided, the program reads its input from stdin.
 *      If no debugging choice is provided, the program prints debugging
 *      messages, or not, depending on indications in the code.
 *
 * Input:
 *      The program reads its input from a file passed in as a parameter
 *      on the command line, or reads from the standard input.
 *
 * Output:
 *      For each valid line, the program attempts to print the machine language representation of the line.
 *      If the line does not have a valid op name,
 *      an error message will be printed.
 *
 *      For each invalid line, the program prints an error message to
 *      stderr saying so.  (The program also prints an error message if
 *      it cannot open the file.)
 *
 * Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *        modified: Febuary 17 implented main
 *
 */
#include "assembler.h"
#include "LabelTable.h"

int main(int argc, char *argv[]) 
{
    FILE *fptr;               /* file pointer */
    LabelTable table;


    /* Process command-line arguments (if any) -- input file name
     *    and/or debugging indicator (1 = on; 0 = off).
     */
    fptr = process_arguments(argc, argv);
    if (fptr == NULL) 
    {
        return 1;   /* Fatal error when processing arguments */
    }

    table = pass1(fptr);



    rewind(fptr);
    pass2(fptr, table);


    (void) fclose(fptr);
    return 0;

}



