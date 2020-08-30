#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
void createList();
void displayList();

int main() 
{
    int n;
    printf("Enter the capacity :");
    scanf("%d",&n);
    createList(n);
    displayList();
    return 0;
}

void createList (int range) {
    struct node *newNode, *temp;
    int value;
    printf("Enter the elements of the list : \n");
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
            temp -> next = newNode ;
            temp = newNode;
        }
        temp -> next = start;
    }
}

void displayList () {
    struct node *temp, *ptr;
    if (start == NULL) {
        printf("List is Empty");
        exit (1);
    }
    else {
        temp = start;
        printf("\nThe elements of the circular linked list : ");
        printf("%d ",temp -> data);
        ptr = temp -> next;
        while (ptr != start) {
            printf("%d ",ptr -> data);
            ptr = ptr -> next;
        }
    }
}