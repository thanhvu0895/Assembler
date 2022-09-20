# Assembler PP

### Contributor: 

Daniel Alspector-Kelly, Thanh Vu

### Description 

This program acts as a assembler, turning MIPS Instructions into machine code.  

### How to run this progarm

It is run from a bash terminal, using a make file to compile everything properly.  

<p align="justify">
 - Type 'make' to compile the program into an executeable named disassembler by default
 - The program can be run from the executable using name [ filename ] [ 0|1 ], where "name" is the name of the executable, "filename" is an optional file containing the input to read, and "0" or "1" may be used to specify that debugging should be turned off or on, respectively.   </p>
- If no filename is provided, the program reads its input from stdin.  
- If no debugging choice is provided, the program won't print debugging messages.  
<p align="justify">- Included test files are test.txt and moretests.txt, output files are myOutput.out and myErrors.err for test.txt, and myOutput2.out and myErrors2.err for moretests.txt. </p>

Sample input:  
lw $t0, 1200($t1)  
add $t0, $s2, $t0  
sw $t0, 1200($t1)  
Output:  
10001101001010000000010010110000  
00000010010010000100000000100000  
10101101001010000000010010110000  

Modifications:  
  
2/15/2020: Implementing getOpType and getNbr  
2/18/2020: Fixed bracket style  
2/19/2020: Updated test cases, added function that tests for invalid registers, and created this file  
