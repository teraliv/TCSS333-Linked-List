#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "list.h"


void handle_alarm( int sig ) {
    printf(" . . . . . . . .  PROGRAM TIMES OUT!\n");
    exit(1);
}

void handle_segfault( int sig ) {
    printf(" . . . . . . . .  SEG FAULT!\n");
    exit(1);
}


struct node *addToFront(struct node* front, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = data;
    newNode->next = front;
    return newNode;    
}

struct node* buildList(int n) {
    int i;
    struct node *front = NULL, *newNode;
    for (i = n; i >= 1; i--) {
        front = addToFront(front,i);
    }
    return front;
}

struct node* buildListArr(int values[],int n) {
    int i;
    struct node *front = NULL, *newNode;
    for (i = n-1; i >= 0; i--) {
        front = addToFront(front,values[i]);
    }
    return front;
}


void checkList(struct node *list, int data[], int size) {
    int i = 0;
    while (list != NULL && i < size) {
         if (list->value != data[i]) {
             printf(".  .   .   .   .   FAIL: %d, should be %d\n", list->value, data[i]);
             return;
         }
         i++;
         list = list->next;
    }
    if (list != NULL) {
         printf("  .  .   .   .   FAIL:  Extra Elements in List\n");
    } else if (i < size) {
         printf("  .  .   .   .   FAIL:  List is too short.\n");
    } else {
         printf("LIST IS GOOD\n");
    }
}


struct node *front;
int data[] = {3,4,6,7,0,0,3,4,6,7,3,4,6,7};

void testDeleteAll1() {
    front = buildListArr(data,14);
    front = deleteAll(front, 4);
    printAll(front);  
    int ans1[] = {3,6,7,0,0,3,6,7,3,6,7};
    int ans1Size = 11;      
    checkList(front,ans1,ans1Size);
}


void testDeleteAll2() {
    front = buildListArr(data,14);
    front = deleteAll(front, 6);
    printAll(front);   
    int ans2[] = {3,4,7,0,0,3,4,7,3,4,7};
    int ans2Size = 11;    
    checkList(front,ans2,ans2Size);
}     

void testDeleteAll3() {    
    front = buildListArr(data,14);    
    front = deleteAll(front, 3);
    printAll(front);      
    int ans3[] = {4,6,7,0,0,4,6,7,4,6,7};
    int ans3Size = 11;    
    checkList(front,ans3,ans3Size);
}

void testDeleteAll4() {        
    front = buildListArr(data,14);        
    front = deleteAll(front, 7);
    printAll(front);      
    int ans4[] = {3,4,6,0,0,3,4,6,3,4,6};
    int ans4Size = 11;    
    checkList(front,ans4,ans4Size);
}

void testDeleteAll5() {        
    int data2[] = {5,5,8,8,8,8,8,6};
    front = buildListArr(data2,8);
    front = deleteAll(front,8);
    printAll(front);
    int ans5[] = {5,5,6};
    int ans5Size = 3;    
    checkList(front,ans5,ans5Size);
}

void testDeleteAll6() {    
    int data3[] = {8,8,8,8,8,8,8};
    front = buildListArr(data3,7);
    front = deleteAll(front,8);
    printAll(front);
    int ans6[] = {};
    int ans6Size = 0;    
    checkList(front,ans6,ans6Size);  
}


void testDoubleAll1() {
    int data[] = {4,1,2,6};
    front = buildListArr(data,4);
    front = doubleAll(front);
    printAll(front);
    int ans[] = {4,4,1,1,2,2,6,6};
    int ansSize = 8;    
    checkList(front,ans,ansSize);
}

void testDoubleAll2() {
    int data[] = {1,1,1};
    front = buildListArr(data,3);
    front = doubleAll(front);
    printAll(front);
    int ans[] = {1,1,1,1,1,1};
    int ansSize = 6;    
    checkList(front,ans,ansSize);
}

void testMerge1() {
    struct node *front1, *front2;
    int data1[] = {1,2,6,15};
    front1 = buildListArr(data1,4);
    int data2[] = {3,5,8,9,13,20};
    front2 = buildListArr(data2,6);    
    
    front = merge(front1,front2);
    printAll(front);
    int ans[] = {1,2,3,5,6,8,9,13,15,20};
    int ansSize = 10;    
    checkList(front,ans,ansSize);
}

void testMerge2() {
    struct node *front1, *front2;
    int data1[] = {1,2,3,5};
    front1 = buildListArr(data1,4);
    int data2[] = {9,13,20};
    front2 = buildListArr(data2,3);    
    
    front = merge(front1,front2);
    printAll(front);
    int ans[] = {1,2,3,5,9,13,20};
    int ansSize = 7;    
    checkList(front,ans,ansSize);
}

void testMerge3() {
    struct node *front1, *front2;
    int data1[] = {9,13,20};
    front1 = buildListArr(data1,3);
    int data2[] = {1,2,3,5};
    front2 = buildListArr(data2,4);    
    
    front = merge(front1,front2);
    printAll(front);
    int ans[] = {1,2,3,5,9,13,20};
    int ansSize = 7;    
    checkList(front,ans,ansSize);
}


void testNoDupData1() {
    int data[] = {4,1,2,6};
    front = buildListArr(data,4);
    if (nodupdata(front)) {
         printf("GOOD\n");
    } else {
         printf(" .  .   .   .   FAIL!  no dups in 4,1,2,6\n");
    }
}

void testNoDupData2() {
    int data[] = {4,1,2,1,6};
    front = buildListArr(data,5);
    if (!nodupdata(front)) {
         printf("GOOD\n");
    } else {
         printf(" .  .   .   .   FAIL!   missed dups in 4,1,2,1,6\n");
    }
}

void testNoDupData3() {
    int data[] = {4,1,2,6,4};
    front = buildListArr(data,5);
    if (!nodupdata(front)) {
         printf("GOOD\n");
    } else {
         printf(" .  .   .   .   FAIL!   missed dups in 4,1,2,1,6\n");
    }
}

void testNoDupData4() {
    int data[] = {4,4,2,6};
    front = buildListArr(data,4);
    if (!nodupdata(front)) {
         printf("GOOD\n");
    } else {
         printf(" .  .   .   .   FAIL!  missed dups in 4,4,2,6 \n");
    }
}

void testNoDupData5() {
    int data[] = {4,1,2,6,7,12,15,23};
    front = buildListArr(data,8);
    if (nodupdata(front)) {
         printf("GOOD\n");
    } else {
         printf(" .  .   .   .   FAIL!  no dups in 4,1,2,6,7,12,15,23\n");
    }
}

void testLoopless1() {
    int data[] = {4,1,2,6,7,12,15,23};
    front = buildListArr(data,8);
    int n = looplesslength(front);
    if (n == 8) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,8);
    }
}

void testLoopless2() {
    int data[] = {4,1,2,4,1,2,4,1,2,4,1,2};
    front = buildListArr(data,12);
    int n = looplesslength(front);
    if (n == 12) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,12);
    }      
}

void testLoopless3() {
    int data[] = {1,1,1,1,1,1,1};
    front = buildListArr(data,7);
    int n = looplesslength(front);
    if (n == 7) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,7);
    }     
}

void addLoop(struct node*list, int fromNodeIndex,int toNodeIndex ) {
    struct node* curr = list;
    struct node* toNode;
    int i = 1;
    while (list != NULL) {
        if (i == toNodeIndex)
            toNode = list;
        else if (i == fromNodeIndex) {
            list->next = toNode;
            break;
        }
        list = list->next;
        i++;
    }
}

void testLoopless4() {
    int data[] = {1,2,3,4,5,6,7,8};
    front = buildListArr(data,8);
    addLoop(front, 8, 4);
    int n = looplesslength(front);    
    if (n == -8) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,-8);
    }     
}

void testLoopless5() {
    int data[] = {5,3,6,2,8,9,4,1,6};
    front = buildListArr(data,9);
    addLoop(front, 9, 1);
    int n = looplesslength(front);    
    if (n == -9) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,-9);
    } 
}

void testLoopless6() {
    int data[] = {6,2,8,9,4,1,6};
    front = buildListArr(data,7);
    addLoop(front, 7, 6);
    int n = looplesslength(front);    
    if (n == -7) {
         printf("GOOD\n");
    } else {
         printf("  . . . . . .  FAIL:  was %d (should be %d)\n", n,-7);
    } 
}



int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
   
    signal( SIGSEGV, handle_segfault);
    signal( SIGALRM, handle_alarm ); // Install handler first,
    alarm( 1 ); // before scheduling it to be called.    
    
    printf("Running Test %d\n", n);
    
    if (n == 1)
        testDeleteAll1();
    else if (n == 2) 
        testDeleteAll2();
    else if (n == 3) 
        testDeleteAll3();
    else if (n == 4) 
        testDeleteAll4();
    else if (n == 5) 
        testDeleteAll5();
    else if (n == 6) 
        testDeleteAll6();    
        
    else if (n == 7)
        testDoubleAll1();
    else if (n == 8)
        testDoubleAll2();   
         
    else if (n == 9)
        testMerge1();
    else if (n == 10)
        testMerge2();
    else if (n == 11)
        testMerge3();     
 
    else if (n == 12)
        testNoDupData1();
    else if (n == 13)
        testNoDupData2(); 
    else if (n == 14)
        testNoDupData3();
    else if (n == 15)
        testNoDupData4();
    else if (n == 16)
        testNoDupData5();  
        
    else if (n == 17)
        testLoopless1();
    else if (n == 18)
        testLoopless2();
    else if (n == 19)
        testLoopless3();
    else if (n == 20)
        testLoopless4();
    else if (n == 21)
        testLoopless5();
    else if (n == 22)
        testLoopless6();                                                 
                   
                                
        
        
    return 0;
}    


