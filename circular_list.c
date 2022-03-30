#include <stdio.h>
#include<stdlib.h>

void create();
void display();
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;

int main()
{
//    printf("Hello World");
    create();
    display();
    return 0;
}

void create()
{
    struct node *curr,*prev;
    int i=0,n;
    printf("Enter the no of node\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        if(curr==NULL)
        {
            printf("memory is not allocated\n");
            exit(0);
        }
        printf("Enter the data\n");
        scanf("%d",&curr->data);
        curr->link=NULL;
        if(head==NULL)
        head=prev=curr;
        else
        {
            prev->link=curr;
            prev=prev->link;
        }
    }
    prev->link=head;//to make the list  circular
}
void display()
{
  struct node *t;
  t=head;

  while(t!=NULL)
        {
            printf("%d ",t->data);
            if(t->link==head)
            {
                printf("\nlist is circular\n");
                exit(0);
            }
            
            t=t->link;
        }
        printf("\nlist is not circular\n");
}
