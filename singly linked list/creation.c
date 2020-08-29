#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
void createList();
void search();
void displayList();

int main() 
{
    int n;
    printf("Enter the length of the list :");
    scanf("%d",&n);
    createList(n);
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