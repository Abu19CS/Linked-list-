#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void createList ();
void displayList ();

int main () 
{
    int n;
    printf("Enter the capacity :");
    scanf("%d",&n);
    createList (n);
    printf("\nThe elements of the Original List :");
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

void displayList () {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is Empty !!");
        exit (1);
    }
    else {
        temp = start;
        while (temp -> next != start) {
            printf ("%d ",temp -> data);
            temp = temp -> next;
        }printf("%d",temp -> data);
    }
}