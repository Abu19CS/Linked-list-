#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
void createList ();
void insertNodeBeg ();
void insertNodeEnd ();
void insertAtAfter ();
void insertAtBefore ();
void displayList ();

int main() 
{
    int n;
    printf("Enter the capacity :");
    scanf ("%d",&n);
    createList (n);
    displayList ();
    insertNodeBeg ();
    displayList ();
    insertNodeEnd ();
    displayList ();
    insertAtAfter ();
    displayList (); 
    insertAtBefore ();
    displayList ();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value; 
    printf("Enter the elements of the list :");
    for (int i = 1; i <= range; i++) 
    {
        scanf("%d",&value);
        newNode = (struct node*)malloc(sizeof(struct node));
        if (start == NULL) {
            newNode -> data = value;
            newNode -> next = NULL;
            start = temp = newNode;
        }
        else {
            newNode -> data = value;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }
        temp -> next = start;
    }
}

void insertNodeBeg () {
    struct node *newNode, *temp, *ptr;
    int insertValue;
    printf("\nEnter the value to be inserted at the beginning :");
    scanf ("%d",&insertValue);
    newNode = (struct node*)malloc(sizeof (struct node));
    newNode -> data = insertValue;
    ptr = newNode;
    if (start == NULL) {
        newNode -> next = ptr;
        start = temp = newNode;
    }
    else {
        newNode -> next = start;
        ptr = start;
        while (ptr -> next != start) {
            ptr = ptr -> next;
        }
        ptr -> next = newNode;
        start = newNode;
    }
}

void insertNodeEnd () {
    struct node *newNode, *temp, *ptr;
    int insVal;
    printf("\nEnter the value to be inserted at the end :");
    scanf ("%d",&insVal);
    newNode = (struct node*)malloc(sizeof (struct node));
    newNode -> data = insVal;
    if (start == NULL) {
        newNode -> next = start;
        start = temp = newNode;
    }
    else {
        ptr = start;
        while (ptr -> next != start) {
            ptr = ptr -> next;
        }
        ptr -> next = newNode;
        newNode -> next = start;
    }
}

void insertAtAfter () {
    struct node *newNode, *temp, *ptr;
    int insval, positionVal;
    printf ("\nEnter the value to be inserted :");
    scanf ("%d",&insval);
    printf("\nEnter the value after to be inserted :");
    scanf("%d",&positionVal);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = insval;
    temp = start;
    while (temp -> data != positionVal) {
        temp = temp -> next;
    }ptr = temp -> next;
    temp -> next = newNode;
    newNode -> next = ptr;
}

void insertAtBefore () {
    struct node *newNode, *temp, *prePtr;
    int num, positionNum;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&num);
    printf("\nEnte the value before that to be inserted :");
    scanf ("%d",&positionNum);
    newNode = (struct node*)malloc(sizeof (struct node));
    newNode -> data = num;
    temp = start;
    prePtr = temp;
    while (temp -> data != positionNum) {
        prePtr = temp;
        temp =  temp -> next;
    }
    prePtr -> next = newNode;
    newNode -> next = temp;
}

void displayList () {
    struct node *temp, *ptr;
    if (start == NULL) {
        printf("OOPS !! list is empty");
        exit (1);
    }
    else {
        temp = start;
        printf("The elements of the list :");
        printf("%d ",temp -> data);
        ptr = temp -> next; 
        while (ptr != start) {
            printf("%d ",ptr -> data);
            ptr = ptr -> next;
        }
    }
}