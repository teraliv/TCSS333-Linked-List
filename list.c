/*
 *  list.c
 *  TCSS 333 - Winter 2015
 *
 *  Assignment 5 - Linked List functions
 *  Alex Terikov (teraliv@uw.edu)
 *  2/18/16.
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void printAll(struct node* list) {
    struct node* curr = list;
    printf("List: ");
    while (curr != NULL) {  // Watch Out: curr->next !=  NULL
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

void add_to_listP2P( struct node **list  ,int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

int inOrder(struct node *list) {
    struct node *curr = list;
    if (curr == NULL)
        return 1;
    while (curr->next != NULL) {  // SAFETY CHECK: curr  != NULL
        if (curr->value > curr->next->value) {  // SAFETY CHECK:  curr->next != NULL
            return 0;
        }
        curr = curr->next;
    }
    return 1;
} 

struct node *delete_from_list(struct node *list, int n) {
    struct node *cur, *prev;
    for (cur = list, prev = NULL; cur != NULL ; prev = cur, cur = cur->next) {
        if (cur->value == n) {
            if (prev == NULL)
               list = list->next; /* n is in the first node */
                else
               prev->next = cur->next; /* n is in some other node */
                    free(cur);
                break;
        }
    }
    return list;
}



// A function to check if a linked
// list contain a loop in it.
int looplesslength(struct node *list) {
    int foundListEnd = 0, countNodes = 0, loopFound = 0, i;
    
    struct node *curr, *scan;
    curr = list;

    // loop the list until the end of the list
    // is found or loop is found.
    while (!foundListEnd) {
        
        // end of the list is found
        if (curr == NULL)
            foundListEnd = 1;
        // keep looking
        else {
            curr = curr->next;
            if (curr != NULL)
                countNodes++;
            
            // check if the list has a loop
            if (curr != NULL && curr->next != NULL) {
                for (i = 0, scan = list; i < countNodes; i++, scan = scan->next) {
                    if (curr->next == scan) {
                        foundListEnd = 1;
                        loopFound = 1;
                    }
                }
            }
        }        
    }
    
    // nodes count start from 0, increment it
    if (countNodes != 0)
        countNodes++;

    // if loop found result of total nodes is negative
    if (loopFound)
        countNodes = countNodes - (countNodes * 2);

    return countNodes;
}


// A function to merge two given linked list into a new one.
struct node *merge(struct node* list1, struct node* list2) {
    struct node *mergelist, *cur1, *cur2, *curm, *prevm;

    cur1 = list1, cur2 = list2;
    mergelist = NULL;

    while (cur1 != NULL || cur2 != NULL) {
        // List2:node < List1:node
        if (cur1 != NULL && cur2 != NULL && cur2->value < cur1->value) {
            curm = cur2;
            cur2 = cur2->next;
            curm->next = NULL;
        }
        
        // List2:node <= List1:node
        else if (cur1 != NULL && cur2 != NULL && cur1->value <= cur2->value) {
            curm = cur1;
            cur1 = cur1->next;
            curm->next = NULL;
        }

        // List2: have remaining nodes, List1: not
        else if (cur2 != NULL && cur1 == NULL) {
            curm = cur2;
            cur2 = cur2->next;
            curm->next = NULL;
        }

        // List1: have remaining nodes, List2: not
        else if (cur1 != NULL && cur2 == NULL) {
            curm = cur1;
            cur1 = cur1->next;
            curm->next = NULL;
        }

        // check if mergelist is empty 
        // add current node as first node to it
        if (mergelist == NULL) {
            mergelist = curm;
            prevm = mergelist;
        }
        // add current node to the tail of new merged list
        else {
            prevm->next = curm;
            prevm = prevm->next;
        }
    }
    
    return mergelist;
}

// A function to check if a given linked
// list contains nodes with dublicate values
int nodupdata(struct node *list) {
    int dubFound = 1;

    struct node *curr, *scan;
    curr = list;

    // list is empty, no dublicates
    if (list == NULL)
        return dubFound;

    // loop until current node is not null 
    // or dublicate is not found
    while (curr != NULL && dubFound) {
        scan = curr;
        
        // check for dublicate data
        while (scan->next != NULL) {
            scan = scan->next;
            if (curr->value == scan->value)
                dubFound = 0; 
        }
        curr = curr->next;
    }

    return dubFound;
}


// A function to double every node in a 
// given linked list
struct node *doubleAll(struct node* list) {
    struct node *curr, *prev, *copy_node;
    curr = list;

    // check for empty list
    if (list == NULL)
        return list;

    // dublicate every node
    while (curr != NULL) {
        copy_node = malloc(sizeof(struct node));
        prev = curr;
        curr = curr->next;
        copy_node->value = prev->value;
        copy_node->next = curr;
        prev->next = copy_node;
    }

    return list;
}

// A function to delete every node tha contain N value
struct node *deleteAll(struct node *list, int n) {
    struct node *curr, *prev, *temp;

    curr = list, prev = NULL;

    while (curr != NULL) {
        // special case: N is first node
        if (list->value == n) {
            temp = list;
            list = list->next;
            curr = list;
            free(temp);
        }
        
        // no more nodes left
        if (curr == NULL)
            return list;

        prev = curr;
        curr = curr->next;
        
        // N is in other node
        if (curr != NULL && curr->value == n) {
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        }
    }

    return list;
}
