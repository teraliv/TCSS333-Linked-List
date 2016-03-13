/*
 *  main.c
 *  TCSS 333 - Winter 2015
 *
 *  Assignment 5 - Linked List functions
 *  Alex Terikov (teraliv@uw.edu)
 *  2/18/16.
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void testDoubleAll();
void testDeleteAll();
void testMerge();
void testNodupdata();
void printNodupdataMessage(int status);
void testLooplesslength();


int main(void) {

    // testLooplesslength();
    // testNodupdata();     
    // testMerge();
    // testDoubleAll();
    testDeleteAll();

    return 0;
}

// test to check if the linked list does not 
// contain loop in it
void testLooplesslength() {
    printf("+-----------------------------+\n");
    printf("|    TEST: LOOPLESS LENGTH    |\n");
    printf("+-----------------------------+\n");

    int result;

    struct node *intlist = NULL, *curr;
    
    // test for empty list
    result = looplesslength(intlist);
    if (result == 0)
        printf("Original list is empty\n");

    // test with no loop in list
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 4);
    intlist = add_to_list(intlist, 3);
    intlist = add_to_list(intlist, 2);
    intlist = add_to_list(intlist, 1);
    printf("\n5 nodes have been added to the list\n");
    printAll(intlist);

    result = looplesslength(intlist);
    if (result > 0) 
        printf("List contains %d nodes, no loop found!\n", result);

    // test with loop in list
    printf("\nNow list contains the loop: 5 points to 1\n");
    curr = intlist;
    curr = curr->next->next->next->next;
    curr->next = intlist;
    result = looplesslength(intlist);
    if (result < 0) 
        printf("List contains %d nodes, loop was found!\n\n", result);
}

// test to check if the linked list does not
// contain dublicate nodes with the same value
void testNodupdata() {
    printf("+----------------------------+\n");
    printf("|    TEST: DUPLICATE DATA    |\n");
    printf("+----------------------------+\n");

    struct node *intlist = NULL;
    
    // test for emptly list
    printf("Original list is empty\n");
    printNodupdataMessage(nodupdata(intlist));
    
    // test for no dublicate list
    intlist = add_to_list(intlist, 1);
    intlist = add_to_list(intlist, 7);
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 3);    
    printf("\n4 nodes have been added\n");
    printAll(intlist);
    printNodupdataMessage(nodupdata(intlist));

    // test for list with dublicates
    intlist = add_to_list(intlist, 1);
    printf("\n1 node with dublicate data have been added\n");
    printAll(intlist);
    printNodupdataMessage(nodupdata(intlist));
    printf("\n");
}

// helper function for testNodupdata() function
// to print out status message
void printNodupdataMessage(int status) {
    if (status == 1)
        printf("No dublicate data is found!\n");
    else
        printf("There is dublicate data in the list!\n");
}


// test to merge 2 linked list into one
void testMerge() {
    printf("+-------------------------+\n");
    printf("|    TEST: MERGE LISTS    |\n");
    printf("+-------------------------+\n");

    struct node *intlist1 = NULL;
    struct node *intlist2 = NULL;
    struct node *mergelist = NULL;
    
    // add elements to first list
    printf("\nList 1 contain following values\n");
    intlist1 = add_to_list(intlist1, 20);
    intlist1 = add_to_list(intlist1, 13);
    intlist1 = add_to_list(intlist1, 11);
    intlist1 = add_to_list(intlist1, 9);
    intlist1 = add_to_list(intlist1, 7);
    intlist1 = add_to_list(intlist1, 7);
    intlist1 = add_to_list(intlist1, 5);
    intlist1 = add_to_list(intlist1, 3);
    printAll(intlist1);

    printf("\nList 2 contain following values\n");
    // add elements to second list
    intlist2 = add_to_list(intlist2, 10);
    intlist2 = add_to_list(intlist2, 6);
    intlist2 = add_to_list(intlist2, 5);
    intlist2 = add_to_list(intlist2, 1);
    printAll(intlist2);
    
    mergelist = merge(intlist1, intlist2);
    printf("\nMerged list contain following values:\n");
    printAll(mergelist);
    printf("\n");
}

void testDoubleAll() {
    printf("+-------------------------------+\n");
    printf("|    TEST: DOUBLE EVERY NODE    |\n");
    printf("+-------------------------------+\n");
    
    struct node *intlist = NULL;
    intlist = add_to_list(intlist, 30);
    intlist = add_to_list(intlist, 20);
    intlist = add_to_list(intlist, 10);
    
    printf("\nOriginal list\n");
    printAll(intlist);

    printf("\nDouble every node\n");
    intlist = doubleAll(intlist);
    printAll(intlist);

    printf("\nDouble every node again\n");
    intlist = doubleAll(intlist);
    printAll(intlist);
    printf("\n");
}


void testDeleteAll() {
    printf("+--------------------------------------------------------+\n");
    printf("|    TEST: DELETE ALL OCCURENCES OF NODE WITH VALUE N    |\n");
    printf("+--------------------------------------------------------+\n");

    struct node *intlist = NULL;
    int i;

    int data2[] = {5,5,8,8,8,8,8,6};

    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 5);   
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 6); 
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);
    intlist = add_to_list(intlist, 8);


    // intlist = add_to_list(intlist, 9);
    // intlist = add_to_list(intlist, 1);
    // intlist = add_to_list(intlist, 4);
    // intlist = add_to_list(intlist, 5);
    // intlist = add_to_list(intlist, 1);
    // intlist = add_to_list(intlist, 9);
    // intlist = add_to_list(intlist, 9);


    printf("Original list\n");
    printAll(intlist);

    printf("\nRemove all occurences of 8\n");
    intlist = deleteAll(intlist, 8);
    printAll(intlist); 

    // printf("\nRemove all occurences of 9\n");
    // intlist = deleteAll(intlist, 9);
    // printAll(intlist);    

    // printf("\nRemove all occurences of 1\n");
    // intlist = deleteAll(intlist, 1);
    // printAll(intlist);

    // printf("\nRemove all occurences of 4\n");
    // intlist = deleteAll(intlist, 4);
    // printAll(intlist);    

    // printf("\nRemove all occurences of 5\n");
    // intlist = deleteAll(intlist, 5);
    // printAll(intlist);
}
