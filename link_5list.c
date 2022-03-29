#include <stdio.h>
#include <stdlib.h>

void display();
void creat(int n);
void addpos(int k);
void print_odd();
void reverseList();
void add_beg();
int circular();

struct node
{
        int data;
        struct node *adr;
};

struct node *h=NULL;
void display()
{
        struct node *dis;
        dis=h;
        printf("Linklist is\n");
        while(dis!=NULL)
        {
                printf("%d\t",dis->data);
                dis=dis->adr;
        }
        printf("\n");
}

void creat(int n)
{
        int i,item;
        struct node *curr,*next;
        printf("Enter the data\n");
        scanf("%d",&item);
        curr=(struct node*)malloc(sizeof(struct node));
	if(curr==NULL)
	{
	printf("memory is not allocated\n");
	exit(0);
	}
        curr->data=item;
	curr->adr=NULL;
        next=h=curr;
        for(i=1;i<n;i++)
        {
                printf("Enter the data\n");
                scanf("%d",&item);
                curr=(struct node*)malloc(sizeof(struct node));
		if(curr==NULL)
        	{
        	printf("memory is not allocated\n");
        	exit(0);
        	}

                curr->data=item;
		curr->adr=NULL;	
                next->adr=curr;
                next=next->adr;
        }
}

void addpos(int k)
{
        struct node *s,*temp;
        s=h;
        int count=0,pos=2;
        while(s->adr!=0)
        {
                ++count;
                if(count==pos)
                {
                        temp=(struct node*)malloc(sizeof(struct node));
			if(temp==NULL)
                	{
                	printf("memory is not allocated\n");
                	exit(0);
                	}

                        temp->data=k;
                        temp->adr=s->adr;
                        s->adr=temp;
                }
                 s=s->adr;

        }
}


int main()
{
        int n,m;
        printf("Enter the node\n");
        scanf("%d",&n);
        creat(n);
        display();
        printf("\nEnter the data to add in list\n");
        scanf("%d",&m);
	addpos(m);
        display();
	print_odd();
	reverseList();
	display();
	add_beg();
	display();
	if(circular()==1)
	printf("Linked list is circular\n");
	else
	printf("Linked list is not circular\n");
}	


void print_odd()
{
	struct node *odd;
	odd=h;
	printf("odd number is\n");
	int count=0,value=0,flag=0;
	while(odd!=NULL)
	{
		++count;
		value=odd->data;
		if((value&1)==1)
		{
		flag=1;
		printf("the value is odd %d and node is %d\n",value,count);
		}
		odd=odd->adr;
	}
	if(flag==0)
	printf("no odd number in the list\n");
	
}

void reverseList()
{
    struct node *prevnode, *currnode;
    if(h!= NULL)
    {
        prevnode = h;
        currnode = h->adr;
        h = h->adr;
        prevnode->adr = NULL; // Make first node as last node
        while(h != NULL)
        {
            h = h->adr;
            currnode->adr = prevnode;
            prevnode = currnode;
            currnode = h;
        }
        h = prevnode; // Make last node as head
    }
}

void add_beg()
{
	struct node  *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
	printf("memory not allocated\n");
	exit(0);
	}
	printf("Enter the data\n");
	scanf("%d",&temp->data);
	temp->adr=h;
	h=temp;
	printf("after adding the node at begining\n");
}

int circular()
{
	struct node *temp;
	temp=h;
	temp=temp->adr;
	while(temp->adr!=NULL)
	{
		if(temp->adr==h)
		return 1;
		temp=temp->adr;
	}
}
	
