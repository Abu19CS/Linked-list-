#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
void createList();
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPosAfter();
void displayList();

int main() 
{
    int n;
    printf("Enter the Capacity :");
    scanf ("%d",&n);
    createList(n);
    printf("\nThe Original list Elements :");
    displayList();
    deleteAtBeg();
    displayList();
    deleteAtEnd();
    displayList();
    deleteAtPosAfter();
    displayList();
    return 0;
}

void createList(int range) {
    int readValue;
    struct node *newNode, *temp;
    printf("Enter the elements of the List :\n");
    for (int i = 1; i <= range; i++) 
    {
        scanf("%d",&readValue);
        newNode = (struct node*)malloc(sizeof(struct node));
        if (start == NULL) {
            newNode -> data = readValue;
            newNode -> next = NULL;
            start = temp = newNode;
        }
        else {
            newNode -> data = readValue;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }
    }
}
void deleteAtEnd() {
    struct node *prePtr, *ptr, *temp;
    ptr = start;
    prePtr = ptr;
    while (ptr -> next != NULL) {
        prePtr = ptr;
        ptr = ptr -> next;
    }prePtr -> next = NULL;
    temp = ptr;
    free(temp);
    printf("\nThe elements after deleting the last node :");
}
void deleteAtPosAfter () {
    struct node *ptr, *prePtr, *temp;
    int deleteValue;
    printf("\nEnter the value after which to be deleted :");
    scanf("%d",&deleteValue);
    ptr = start ;
    prePtr = ptr;
    while (ptr -> data != deleteValue) {
        prePtr = ptr;
        ptr = ptr -> next;
    }temp = ptr -> next;
    prePtr = temp -> next;
    free(temp);
    ptr -> next = prePtr;
    printf("\nThe list elements after deleting the specified item :");
}
void deleteAtBeg() {
    struct node *temp, *ptr;
    temp = start;
    ptr = temp -> next;
    start = ptr;
    free(temp);
    printf("\nThe elements after deleting the first node :");
}
void displayList() {
    struct node *temp;
    if (start == NULL) {
        printf("List is empty");
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