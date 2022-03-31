#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link; 
};

void Display(struct node **,struct node **);
void sll_create(struct node **);
void cll_create(struct node **);
void sll_create(struct node **);
void check_cll_sll(struct  node**,struct node **);

int main()
{
	struct node *head=NULL,*head1=NULL;;
//	struct stu *head1=NULL;
	int c;
	while(1)
	{
		printf("1.create circularlist\n2.create sll\n3.check_cll_sll\n4.Display\n5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: cll_create(&head);
				break;
				
			case 2: sll_create(&head1);
				break;
				
			case 3:check_cll_sll(&head,&head1);
			       break;
			       
			case 4: Display(&head,&head1);
				break;
				
			case 5:exit(0);
		}
	}
}
void cll_create(struct node **head)
{
	struct node *newnode,*temp=NULL;
	int i,l;
	printf("Enter the no of node in the list: \n");
	scanf("%d",&l);
	for(i=1;i<=l;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data %d\n",i);
	 	scanf("%d",&newnode->data);
		newnode->link=NULL;
		
		if((*head)==NULL)//check null condition
		{
			(*head)=temp=newnode;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
		temp->link=(*head);//to make circular link list
	}
}
void sll_create(struct node **head1)
{
	struct node *newnode,*temp=NULL;
	int i,l;
	printf("enter the length of list\n");
	scanf("%d",&l);
	for(i=1;i<=l;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data %d\n",i);
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		
		if((*head1)==NULL)//check null condition
		{
			(*head1)=temp=newnode;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
 	}  
}

void check_cll_sll(struct node **head,struct node **head1)
{
	if((*head)==NULL)
	{
		printf("Circular list is empty\n");
        }
	else
	{
       		struct node *temp_node=(*head);
      		while(temp_node->link!=(*head))
       		{
	   		printf("%d\t",temp_node->data);
	                temp_node=temp_node->link;
	         }
		printf("%d\n",temp_node->data);
		if((temp_node)->link==(*head))
		{
			printf("List is a Circular single list*************************\n");
	      	}
		else
    		{
			printf("List is not a Circular single list\n");
		}
	}
	if((*head1)==NULL)
	{
		printf("SLL list is empty\n");
	}
	else
	{
		struct node *temp_node1=(*head1);
		while((temp_node1->link)!=NULL)
		{
			printf("%d\t",temp_node1->data);
			temp_node1=temp_node1->link;
		}
		printf("%d\n",temp_node1->data);
    		if((temp_node1)->link==(*head1))
		{
			printf("List is a Circular single list\n");
		}
		else
		{
			printf("List is not a Circular single list##############################\n");
		}
	}
}
void Display(struct node **head,struct node **head1)
{
	struct node *ptr=NULL,*ptr1=NULL;
 	ptr=*head;
	ptr1=*head1;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while((ptr->link)!=*head)
		{
 			printf("%d\t",ptr->data);
                         ptr=ptr->link;
 		}
		printf("%d\n",ptr->data);
	}
	if(ptr1==NULL)
	{
		printf("Sll is List is empty\n");
	}
	else      	    	    		    
	{
		while((ptr1->link)!=NULL)
		{
			printf("%d\t",ptr1->data);
			ptr1=ptr1->link; 
		}
		printf("%d\n",ptr1->data);
	}
}

