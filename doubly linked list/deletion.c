#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
void createList ();
void deleteAtBeg ();
void deleteAtEnd ();
void deleteAtPosAfter ();
void deleteAtPosBefore ();
void displayList ();

int main () 
{
    int n;
    printf("Enter the capacity :");
    scanf ("%d",&n);
    createList (n);
    printf("\nThe elements of the Original List :");
    displayList ();
    deleteAtBeg ();
    printf ("\nThe elements of the list after deleting the first node :");
    displayList ();
    deleteAtEnd ();
    printf("\nThe elements of the list after deleting the last Node :");
    displayList ();
    deleteAtPosAfter ();
    printf ("\nThe elements of the list after deleting the specified node :");
    displayList ();
    deleteAtPosBefore ();
    printf ("\nThe elements of the list after deleting the specified node :");
    displayList ();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value;
    printf("Enter the elements of the list :\n");
    for (int i = 1; i <= range; i++) 
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        if (start == NULL) {
            newNode -> data = value;
            newNode -> prev = NULL;
            newNode -> next = NULL;
            start = temp = newNode;
        }
        else {
            newNode -> data = value;
            newNode -> prev = temp;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }
    }
}

void deleteAtBeg () {
    struct node *temp, *nxtPtr;
    temp = start;
    nxtPtr = start -> next;
    nxtPtr -> prev = NULL;
    start = nxtPtr;
    free(temp);
}

void deleteAtEnd () {
    struct node *temp, *prePtr;
    temp = start;
    while (temp -> next != NULL) {
        prePtr = temp;
        temp = temp -> next;
    }
    prePtr -> next = NULL;
    free(temp);
}

void deleteAtPosAfter () {
    struct node *temp, *ptr, *freeMemo;
    int posVal;
    printf ("\nEnter the value after which to be deleted :");
    scanf ("%d",&posVal);
    temp = start;
    while (temp -> data != posVal) {
        temp = temp -> next;
    }
    freeMemo = temp -> next;
    ptr = (temp -> next) -> next;
    temp -> next= ptr;
    ptr -> prev =  temp;
    free(freeMemo);
}

void deleteAtPosBefore () {
    struct node *temp, *ptr, *prePtr;
    int posVal;
    printf("\nEnter  the value before which to be deleted :");
    scanf("%d",&posVal);
    temp = start;
    while (temp -> data != posVal) {
        prePtr = temp;
        temp = temp -> next;
    }ptr = start;
    while (ptr -> next != prePtr) {
        ptr = ptr -> next;
    }
    ptr -> next =  temp;
    temp -> prev = ptr;
    free(prePtr);
}

void displayList () {
    struct node *temp;
    if (start == NULL) {
        printf ("List is Empty !!");
        exit (1);
    }
    else {
        temp = start;
        while (temp != NULL) {
            printf ("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}