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

int main (void) 
{
    int n;
    printf ("Enter the capacity :");
    scanf ("%d",&n);
    createList (n);
    printf ("\nOriginal List :");
    displayList ();
    deleteAtBeg ();
    printf ("\nModified List After deletion at beginning :");
    displayList ();
    deleteAtEnd ();
    printf ("\nModified List after deletion at End :");
    displayList ();
    deleteAtPosAfter ();
    printf ("\nList after deletion at specified position :");
    displayList ();
    deleteAtPosBefore ();
    printf ("\nList after deletion at specified position :");
    displayList ();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value;
    printf ("Enter the value to be inserted in the list :\n");
    for (int i = 1; i <= range; i++) 
    {
        newNode = (struct node*)malloc(sizeof (struct node));
        scanf("%d",&value);
        if (start == NULL) {
            newNode -> data = value;
            newNode -> next = newNode;
            newNode -> prev = newNode;
            start = temp = newNode;
        }
        else {
            newNode -> data = value;
            newNode -> prev = temp;
            temp -> next = newNode ;
            newNode -> next = NULL;
            temp = newNode;
        }temp -> next = start;
    }
}

void deleteAtBeg () {
    struct node *temp, *delptr, *ptr;
    temp = start;
    while (temp -> next != start) {
        temp = temp -> next;
    }delptr = start;
    ptr = start -> next;
    start =  ptr;
    start -> prev = temp;
    temp -> next = ptr;
    free(delptr);
}

void deleteAtEnd () {
    struct node *temp, *prePtr;
    temp = start;
    while (temp -> next != start) {
        prePtr = temp;
        temp = temp -> next;
    }
    prePtr -> next = start;
    start -> prev = prePtr;
    free(temp);
}

void deleteAtPosAfter () {
    struct node *temp, *ptr;
    int delValue;
    printf ("\nEnter the value after which to be deleted :");
    scanf ("%d",&delValue);
    temp = start;
    while (temp -> data != delValue) {
        temp = temp -> next;
    }ptr = temp -> next;
    temp -> next = ptr -> next;
    (ptr -> next) -> prev = temp;
    free(ptr);
}

void deleteAtPosBefore () {
    struct node *temp, *prePtr, *ptr;
    int delvalue;
    printf ("\nEnter the value before which to be deleted :");
    scanf ("%d",&delvalue);
    temp = start;
    while (temp -> data != delvalue) {
        prePtr =  temp;
        temp = temp -> next;
    }ptr = start;
    while (ptr -> next != prePtr) {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    temp -> prev = ptr;
    free(prePtr);
}

void displayList () {
    struct node *temp;
    if (start == NULL) {
        printf ("List is empty !!");
        exit (1);
    }
    else {
        temp = start;
        printf("%d ",temp -> data);
        temp = temp -> next;
        while (temp != start) {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}