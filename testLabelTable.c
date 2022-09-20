/*
* Test Driver to test the functions to access and manipulate a label table.
* It includes the following tests:
*
*              DESCRIBE TEST CASES HERE
*
* Author:  Thanh Vu
*        with assistance from: Nathan
*
* Creation Date:  2/2/2020
*        modified: 2/2/2020
* Adding the static entries to the label table and create the test drivers
*
*/

#include "assembler.h"

static void testSearch(LabelTable *table, char *searchLabel);

int main(int argc, char *argv[]) 
{
    /* Process command-line argument (if provided) for
     *    debugging indicator (1 = on; 0 = off).
     */
    (void) process_arguments(argc, argv);


    /* Can turn debugging on or off here (debug_on() or debug_off())
     * if not specified on the command line.
     */


    /* Create 2 tables, one static and one dynamic, for testing purposes */

    LabelTable testTable1;      /* will be a table with static entries */
    LabelTable testTable2;      /* will be a table with dynamic entries */



    /* Test printLabels and findLabel with static testTable1.
     *      DO NOT TEST tableInit, addLabel, or tableResize WITH STATIC TABLE!
     * Use testSearch to test findLabel, for example:
     *      testSearch(&testTable1, "Label1");
     * Examples of basic boundary testing:
     *     Set nbrLabels to 0 and test on empty table.
     *     Put four more entries in staticEntries, set nbrLabels to 5,
     *     and test.  (Don't go beyond the max unless you want to crash the
     *     program.)
     */




    //  Ininitialize the testTable1 with static array given 
    printf("===== Testing with static table =====\n\n");


    /* Initialize testTable1 with a static array of a given size. */
    LabelEntry staticEntries[5];
    testTable1.capacity = 6;
    testTable1.nbrLabels = 0;  // Changing the restricted number of labels allowed in the table.
    testTable1.entries = staticEntries;

    printf("\n ===============BOUNDING TEST===============\n");
    printf("\n === BOUNDING TEST 1====\n");
    printf("\nPrint an empty table when number of labels (nbrLabels) is set to 0.\n\n");
    printf("Expected Result:\n");
    printf("- There are 0 labels in the table.\n\n");
    printf("Result: \n");
    printLabels(&testTable1);

    staticEntries[0].label = "Label1";
    staticEntries[0].address = 1000;
    staticEntries[1].label = "Label2";
    staticEntries[1].address = 1234;
    staticEntries[2].label = "Label3";
    staticEntries[2].address = 1231;
    staticEntries[3].label = "Label4";
    staticEntries[3].address = 3254;

    /*resetting nbrLabels to 5 to do remaining test */
    printf("\n ===BOUNDING TEST 2====\n");
    printf("\nPrint after adding four more entries and set the number of labels (nbrLabels) to 5:\n\n");
    printf("Expected Result:\n");
    printf("- There are 4 labels in the table. \n\n");
    printf("Result: \n");
    testTable1.nbrLabels = 5;
    printLabels(&testTable1);


    printf("\n ===BOUNDING TEST 3====\n");
    printf("\nPrint when adding a label beyond the current capacity of 3:\n\n");
    testTable1.capacity = 3;
    printLabels(&testTable1);


    printf("\n ===BOUNDING TEST 4====\n");
    printf("===========================\n");
    printf("\nPrint when number of labels(nbrLabels) is set later to\n");
    printf("Expected Result:\n");
    printf("- There are 0 labels in the table. \n\n");
    testTable1.nbrLabels = 0;
    printLabels(&testTable1);



    printf("\n ===TEST 5====\n");
    printf("\nSearching for a label that is inside the label table.\n\n");
    printf("Expected Result:\n");
    printf("- Looking for Label3... \n the address is 1231. \n\n");
    printf("Result: \n");
    testSearch(&testTable1, "Label3");


    printf("\n ===TEST 6====\n");
    printf("\nSearch for a non-existent label.\n\n");
    printf("Expected Result:\n");
    printf("- Looking for Label8... \n The label you are looking for does not exist. \n\n");
    printf("Result: \n");
    testSearch(&testTable1, "Label8");




    //. DUPLICATE [X]


    // Capacity check [?]

    // After add 5 , current ?


    printf("\n\n\n===== Testing with dynamic table =====\n");


    /* Initialize testTable2 as a dynamic (changeable size) table. */
    tableInit(&testTable2);


    /* Test printLabels, findLabel, and addLabel with dynamic testTable2.
        * Include appropriate boundary testing.
        */

    printf("\n ===============BOUNDING TEST===============\n");
    printf("\n === BOUNDING TEST 1====\n");
    printf("\nPrint an empty table when number of labels (nbrLabels) is 0.\n\n");
    printf("Expected Result:\n");
    printf("- There are 0 labels in the table.\n\n");
    printf("Result: \n");
    printLabels(&testTable2);


    printf("\n ===BOUNDING TEST 2====\n");
    printf("\nPrint after adding four more entries \n\n");
    printf("Expected Result:\n");
    printf("- There are 4 labels in the table. \n\n");
    printf("Result: \n");
    addLabel(&testTable2, "Label01", 2000);
    addLabel(&testTable2, "Label02", 2214);
    addLabel(&testTable2, "Label03", 2967);
    addLabel(&testTable2, "Label04", 2963);
    printLabels(&testTable2);




    printf("\n ===TEST 4====\n");
    printf("\nAdding a duplicate entry \n\n");
    printf("Expected Result:\n");
    printf("Error: a duplicate label was found.\n No new label will be added to the table\n\n");
    printf("Result: \n");
    addLabel(&testTable2, "Label04", 2963);
    printLabels(&testTable2);




    printf("\n ===TEST 5====\n");
    printf("\nSearching for a label that is inside the label table.\n\n");
    printf("Expected Result:\n");
    printf("- Looking for Label3... \n the address is 1231. \n\n");
    printf("Result: \n");
    testSearch(&testTable2, "Label01");


    printf("\n ===TEST 6====\n");
    printf("\nSearch for a non-existent label.\n\n");
    printf("Expected Result:\n");
    printf("- Looking for Label08... \n        The label you are looking for does not exist. \n\n");
    printf("Result: \n");
    testSearch(&testTable2, "Label08");


    printf("\n ===TEST 7====\n");
    printf("\nSearch for a label after it has been added.\n\n");
    printf("Expected Result:\n");
    printf("- Looking for Label08...\n"
           "        the address is 2200.\n\n");
    printf("Result: \n");
    addLabel(&testTable2, "Label08", 2200);
    testSearch(&testTable2, "Label08");

    printf("\n ===BOUNDING TEST 3====\n");
    printf("\nPrint after adding five more  entries \n\n");
    printf("Expected Result:\n");
    printf("- There are 10 labels in the table. \n\n");
    printf("Result: \n");
    addLabel(&testTable2, "Label11", 2314);
    addLabel(&testTable2, "Label12", 1234);
    addLabel(&testTable2, "Label13", 2912);
    addLabel(&testTable2, "Label14", 2993);
    addLabel(&testTable2, "Label15", 2993);
    printLabels(&testTable2);



}


/*
 * testSearch tests the findLabel function, printing out the label being
 * searched for and either the address where it was found or, if it was
 * not found, an address of -1 and a message that the label was not in
 * the table.  
 *  @param  table        a pointer to the table through which to search
 *  @param  searchLabel  the label to search for
 */
static void testSearch(LabelTable *table, char *searchLabel) 
{
    int address;

    printf("- Looking for %s...\n", searchLabel);

    address = findLabel(table, searchLabel);
    if (address == -1) printf("\t The label you are looking for does not exist.\n");
    else printf("\tthe address is %d.\n", address);


}
