#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void createList ();
void insertAtBeg ();
void insertAtEnd ();
void insertAtPosAfter ();
void insertAtPosBefore ();
void displayList ();

int main () 
{
    int n;
    printf("Enter the capacity :");
    scanf("%d",&n);
    createList (n);
    printf("\nThe elements of the Original List :");
    displayList ();
    insertAtBeg ();
    printf ("\nThe elements of the list after inserting at beginning :");
    displayList ();
    insertAtEnd ();
    printf("\nThe elements of the list after inserting at end :");
    displayList ();
    insertAtPosAfter ();
    printf("\nList elements after inserting at specified position :");
    displayList ();
    insertAtPosBefore ();
    printf("\nList elements after inserting at specified position :");
    displayList ();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value;
    printf ("\nEnter the elements of the List :\n");
    for (int i = 1; i <= range; i++) 
    {
        newNode = (struct node*)malloc(sizeof(struct node));
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
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }
        temp -> next = start;
    }
}

void insertAtBeg () {
    struct node *newNode, *temp, *ptr;
    int readValue;
    printf("\nEnter the value to be inserted at the beginning :");
    scanf ("%d",&readValue);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = readValue;
    if (start == NULL) {
        newNode -> prev = newNode;
        newNode -> next = newNode;
        start = newNode;
    }
    else {
        temp = start;
        while (temp -> next != start) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
        newNode -> next = start;
        start -> prev = newNode;
        start = newNode;
    }
}

void insertAtEnd () {
    struct node *newNode, *temp;
    int readValue;
    printf("\nEnter the value to be inserted at the end :");
    scanf("%d",&readValue);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = readValue;
    if (start == NULL) {
        newNode -> prev = newNode;
        newNode -> next = newNode;
        start =  newNode;
    }
    else {
        temp = start;
        while (temp -> next != start) {
            temp = temp -> next;
        }temp -> next = newNode;
        newNode -> prev =  temp;
        newNode -> next = start;
        start -> prev = newNode;
    }
}

void insertAtPosAfter () {
    struct node *newNode, *temp, *ptr;
    int value, position;
    printf ("\nEnter the value to be inserted :");
    scanf ("%d",&value);
    printf ("\nEnter the value after that to be inserted :");
    scanf ("%d",&position);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    temp = start;
    while (temp -> data != position) {
        temp = temp -> next;
    }
    ptr = temp -> next;
    temp -> next = newNode;
    newNode -> prev = temp;
    newNode -> next = ptr;
    ptr -> prev = newNode;
}

void insertAtPosBefore () {
    struct node *newNode, *temp, *ptr, *prePtr;
    int value, position;
    printf ("\nEnter the value to be inserted :");
    scanf ("%d",&value);
    printf ("\nEnter the value before which to be inserted :");
    scanf ("%d",&position);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    temp = start;
    while (temp -> data != position) {
        prePtr = temp;
        temp = temp -> next;
    }
    prePtr -> next = newNode;
    newNode -> prev = prePtr;
    newNode -> next = temp;
}

void displayList () {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is Empty !!");
        exit (1);
    }
    else {
        temp = start;
        while (temp -> next != start) {
            printf ("%d -> ",temp -> data);
            temp = temp -> next;
        }printf("%d",temp -> data);
    }
}