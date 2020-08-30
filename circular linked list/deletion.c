#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void createList ();
void deleteAtBeg ();
void deleteAtEnd ();
void deleteAtPosAfter ();
void deleteAtPosBefore ();
void displayList ();

int main() 
{
    int n;
    printf("Enter the capacity :\n");
    scanf("%d",&n);
    createList(n);
    printf("\nThe elements of the Original List :");
    displayList();
    deleteAtBeg ();
    printf("\nThe elements of the list after deleting the first node :");
    displayList ();
    deleteAtEnd ();
    printf("\nThe elements of the list after deleting the last node :");
    displayList ();
    deleteAtPosAfter ();
    printf("\nThe elements after deleting the specified node :");
    displayList ();
    deleteAtPosBefore ();
    printf ("\nThe elements after deleting the specified node :");
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
            newNode -> next = newNode;
            start = temp = newNode;
        }
        else {
            newNode -> data = value;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }temp -> next = start;
    }
}

void deleteAtBeg () {
    struct node *temp, *ptr;
    int count = 0;
    temp = start;
    ptr = temp -> next;
    while (temp -> next != start) {
        count++;
        temp = temp -> next;
    }
    if (temp -> next == start && count == 0) {
        start = NULL;
        ptr = temp -> next;
        free (ptr);
    }
    else if (count >= 1) {
        temp -> next = ptr;
        start = ptr;
    }
}

void deleteAtEnd () {
    struct node *temp, *prePtr, *ptr;
    int count = 0;
    temp = start;
    while (temp -> next != start) {
        prePtr = temp;
        temp = temp -> next;
    }prePtr -> next = start;
    free(temp);
}

void deleteAtPosAfter () {
    struct node *temp, *ptr, *currNode;
    int readVal;
    printf ("\nEnter the element after that to be deleted :");
    scanf ("%d",&readVal);
    temp = start;
    while (temp -> data != readVal) {
        temp = temp -> next;
        currNode = temp;
    }
    ptr = temp -> next;
    currNode -> next = ptr -> next;
    free (temp);
}
void deleteAtPosBefore () {
    struct node *temp, *prePtr, *ptr, *currNode;
    int readValue;
    printf("\nEnter the element before that to be deleted :");
    scanf ("%d",&readValue);
    temp = start;
    while (temp -> data != readValue) {
        prePtr = temp;
        temp = temp -> next;
    }
    ptr = start;
    while (ptr -> next != prePtr) {
        ptr = ptr -> next;
    }ptr -> next = temp;
    free(ptr);
}
void displayList () {
    struct node *temp, *ptr;
    if (start == NULL) {
        printf("List is Empty !!");
        exit (1);
    }
    else {
        temp = start;
        printf("%d ",temp -> data);
        ptr =  temp -> next;
        while (ptr != start) {
            printf("%d ",ptr -> data);
            ptr = ptr -> next;
        }
    }
}