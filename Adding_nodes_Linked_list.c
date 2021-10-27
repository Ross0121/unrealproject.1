#include<stdio.h>
#include<malloc.h>


struct node{
	int data;
	struct node* next;
};
struct node* head=NULL;


struct node* getnewnode(int val)
{
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data =val;
	temp->next= NULL;
	return temp;
}
insertbeg(int val)
{
	struct node* ptr;
	ptr=getnewnode(val);
	ptr->next=head;
	head= ptr;
}
insertend(int val)
{
	struct node* ptr;
	ptr=getnewnode(val);
	
	struct node* run;
	run=head;
	while(run->next!=NULL)
	{
		run=run->next;	
	}
	run->next=ptr;
	
}

insertatpos(int val, int pos)
{
	struct node* ptr;
	ptr=getnewnode(val);

	struct node* run;
	run=head;
	int i;
	for(i=0;i<pos-1;i++)
	{
		run=run->next;
	}
	ptr->next=run->next;
	run->next=ptr;
}

print()
{
	struct node* run;
	run= head;
	while(run!=NULL)
	{
		printf("%d ", run->data);
		run=run->next;
	}
	printf("\n");
}
void main()
{
	
	insertbeg(6);// Insertion at beginning
	insertbeg(5);
	insertbeg(4);
	print(); // Without Insertion at end
	insertend(7); // Insertion at end
	insertbeg(8);
	insertend(2);
	print(); // Without Insertion at position
	insertatpos(9,2);// Insertion at position
	print();
	}
