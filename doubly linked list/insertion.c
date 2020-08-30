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
    printf ("Enter the capacity :");
    scanf ("%d",&n);
    createList (n);
    printf("\nThe elements of the Original list :");
    displayList ();
    insertAtBeg ();
    printf("\nThe elements of the list after insertion at Beginning :");
    displayList ();
    insertAtEnd ();
    printf ("\nThe elements of the list after insertion at End :");
    displayList ();
    insertAtPosAfter ();
    printf("\nList elements :");
    displayList ();
    insertAtPosBefore ();
    printf("\nList elements :");
    displayList ();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value;
    printf("Enter the elements of the list :");
    for (int i = 1; i <= range; i++) 
    {
        newNode = (struct node*)malloc(sizeof (struct node));
        scanf("%d",&value);
        if (start == NULL) {
            newNode -> data = value;
            newNode -> next = NULL;
            newNode -> prev = NULL;
            start = temp = newNode;
        }
        else {
            newNode -> data = value;
            newNode -> next = NULL;
            newNode -> prev = temp;
            temp -> next = newNode ;
            temp = newNode;
        }
    }
}

void insertAtBeg () {
    struct node *newNode, *temp;
    int readval;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&readval);
    newNode = (struct node*)malloc (sizeof(struct node));
    if (start == NULL) {
        newNode -> data = readval;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        start = newNode;
    }
    else {
        temp = start;
        newNode -> data = readval;
        newNode -> prev = NULL;
        newNode -> next = start;
        temp -> prev = newNode;
        start = newNode;
    }
}

void insertAtEnd () {
    struct node *newNode, *temp;
    int readval;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&readval);
    newNode = (struct node*)malloc(sizeof (struct node));
    if (start == NULL) {
        newNode -> data = readval;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        start = newNode;
    }
    else {
        temp = start;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev =  temp;
        newNode -> data = readval;
        newNode -> next = NULL;
    }
}
void insertAtPosAfter () {
    struct node *newNode, *temp;
    int insVal, readval;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&insVal);
    printf("\nEnter the position value :");
    scanf("%d",&readval);
    newNode = (struct node*)malloc(sizeof(struct node));
    temp = start;
    while (temp -> data != readval) {
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    newNode -> data = insVal;
    newNode -> prev = temp;
    temp -> next = newNode;
}

void insertAtPosBefore () {
    struct node *newNode, *temp, *prePtr, *ptr;
    int readValue, posValue;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&readValue);
    printf ("\nEnter the value before that to be inserted :");
    scanf ("%d",&posValue);
    newNode = (struct node*)malloc(sizeof (struct node));
    newNode -> data = readValue;
    temp = start;
    while (temp -> data != posValue) {
        prePtr = temp;
        temp = temp -> next;
    }
    prePtr -> next = newNode;
    newNode -> prev = prePtr;
    newNode -> next = temp;
    temp -> prev = newNode;
}

void displayList () {
    struct node *temp;
    if (start == NULL) {
        printf("List is empty !!");
        exit(1);
    }
    else {
        temp = start;
        while (temp != NULL) {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}