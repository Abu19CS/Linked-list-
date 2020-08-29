#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
void createList();
void insertNodeAtBeg();
void insertNodeAtEnd();
void insertAtPosAfter();
void insertAtPosBefore();
void displayList();

int main() 
{
    int n;
    printf("Enter the length of the list :");
    scanf("%d",&n);
    createList(n);
    displayList();
    insertNodeAtBeg();
    displayList();
    insertNodeAtEnd();
    displayList();
    insertAtPosAfter();
    displayList();
    insertAtPosBefore();
    displayList();
    return 0;
}

void createList(int range) 
{
    int value;
    struct node *newNode, *temp;
    printf("Enter the elements of the list :\n");
    for (int i = 1; i <= range; i++) 
    {
        scanf("%d",&value);
        newNode = (struct node*)malloc(sizeof(struct node));
        if (start == NULL) {
            newNode -> data = value;
            newNode -> next = NULL;
            start = temp = newNode;
        }
        else 
        {
            newNode -> data = value;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp = newNode;
        }
    }
}
void insertNodeAtBeg () {
    struct node *newNode;
    int newVal;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the new element to be inserted at the beginning : ");
    scanf("%d",&newVal);
    if (start == NULL) {
        newNode -> data = newVal;
        newNode -> next = NULL;
        start = newNode;
    }
    else {
        newNode -> data = newVal;
        newNode -> next = start;
        start = newNode;
    }
}
void insertNodeAtEnd() {
    struct node *newNode, *temp;
    int insertValue;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value to be entered at the end :");
    scanf("%d",&insertValue);
    if (start == NULL) {
        newNode -> data = insertValue;
        newNode -> next = NULL;
        start = newNode;
    }
    else {
        temp = start;
        while (temp -> next != NULL) 
            temp = temp -> next;
        newNode -> data = insertValue;
        newNode -> next = NULL;
        temp -> next = newNode;
    }
}
void insertAtPosAfter() {
    struct node *newNode, *ptr, *prePtr;
    int readValue, positionVal;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&readValue);
    printf("\nEnter the position after to that to be inserted :");
    scanf("%d",&positionVal);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = readValue;
    ptr = start;
    prePtr = ptr; //1000 5
    while (prePtr -> data != positionVal) { 
        prePtr = ptr; //2000
        ptr = ptr -> next; //3000
    }    
    prePtr -> next = newNode ;
    newNode -> next = ptr;
}
void insertAtPosBefore() {
    struct node *newNode, *ptr, *postPtr, *previous;
    int val, posVal;
    printf("\nEnter the value to be inserted :");
    scanf("%d",&val);
    printf("\nEnter the position before that the value to be inserted :");
    scanf("%d",&posVal);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = val;
    ptr = previous = start;
    postPtr = ptr;
    while (postPtr -> data != posVal) {
        previous = ptr;
        ptr = ptr -> next;
        postPtr = ptr;
    }
    previous -> next = newNode;
    newNode -> next = ptr;
}
void displayList() 
{
    struct node *temp;
    if (start == NULL) {
        printf("List is empty");
        exit(1);
    }
    else 
    {
        temp = start;
        printf("\nList elements are :");
        while (temp != NULL) {
            printf ("%d ",temp -> data);
            temp = temp -> next ;
        }
    }
}