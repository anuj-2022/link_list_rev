#include<stdio.h>
#include<stdlib.h>

void display();
void create_node(int n);
struct node
{
        int data;
        struct node *prev;
        struct node *next;
};

struct node *head=NULL,*tail=NULL;

void main()
{
        int n;
        printf("enter the node\n");
        scanf("%d",&n);
        create_node(n);
        display();
}

void create_node(int n)
{
        struct node *newnode;
        int i=0;
        for(i=0;i<n;i++)
        {
        printf("Enter the data\n");
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("memory is not allocated\n");
        scanf("%d",&newnode->data);

        if(head==NULL)
        {
        head=tail=newnode;
        head->prev=NULL;
        tail->next=NULL;
        }
        else
        {
        tail->next = newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=NULL;
        }
        }
}

void display()
{
        struct node *display=head;
        if(head==NULL)
        {
        printf("list is empty\n");
        exit(0);
        }
        printf("The list is\n");
        while(display!=NULL)
        {
        printf("%d ",display->data);
        display=display->next;
        }
}

