#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {

    struct node *intlist = NULL;
    int i;
    
    for (i = 0; i < 10; i ++) {  
        intlist = add_to_list(intlist ,i );
    }
    
    printAll(intlist);
    
    if (!inOrder(intlist)) 
        printf("Out of Order\n");
    else
        printf("In Order\n");
        
    for (i = 0; i < 10; i ++) {  
        intlist = delete_from_list(intlist ,i );
        printAll(intlist);
    }       
    return 0;
}
