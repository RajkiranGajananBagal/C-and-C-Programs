/////////////////////////////////////////////////////////////////////////
//            DESCRIPTION:-
//	Program Number: 01
//	Program Name: Singly Linear Linked List
//	Author:	      Rajkiran Gajanan Bagal
////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//prototypes

struct node
{
int data;
struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node * * PPNODE;

void insert_first(PPNODE,int);
void insert_last(PPNODE,int);
void insert_atPos(PPNODE,int,int);
void delete_first(PPNODE);
void delete_last(PPNODE);
void delete_atPos(PPNODE,int);
void display(PNODE);
int count(PNODE);

int main()
{
int ch,ivalue,ipos,size;

PNODE FIRST=NULL;


while(ch!=0)
{
printf("\n**********SINGLY LINEAR LINKED LIST**********\n");
printf("\nEnter 0 to Exit\n");
printf("\nEnter 1 to Insert New Node at First Position\n"); 
printf("\nEnter 2 to Insert New Node at Last Position\n"); 
printf("\nEnter 3 to Insert New Node at Your Desired Position\n"); 
printf("\nEnter 4 to Delete First Node\n"); 
printf("\nEnter 5 to Delete Last Node\n"); 
printf("\nEnter 6 to Delete Your Desired Node\n"); 
printf("\nEnter 7 to Display Current Linked list\n");
printf("\nEnter 8 to Display Count of Nodes of Current Linked list\n");
scanf("%d",&ch);

switch(ch)
{
case 0:
printf("\nYou have Succesfully Exitted\n");
break;
case 1:
printf("The Current Linked List is:\n");
display(FIRST);
printf("Enter The Value of Data You want To Insert\n");
scanf("%d",&ivalue);
insert_first(&FIRST,ivalue);
display(FIRST);
break;
case 2:
printf("The Current Linked List is:\n");
display(FIRST);
printf("Enter The Value of Data You want To Insert\n");
scanf("%d",&ivalue);
insert_last(&FIRST,ivalue);
display(FIRST);
break;
case 3:
printf("The Current Linked List is:\n");
display(FIRST);
printf("Enter The Value of Data You want To Insert\n");
scanf("%d",&ivalue);
printf("Enter The Position at which You want to Insert\n");
scanf("%d",&ipos);
insert_atPos(&FIRST,ipos,ivalue);
display(FIRST);
break;
case 4:
printf("The Current Linked List is:\n");
display(FIRST);

delete_first(&FIRST);
printf("The Linked List after Deletion is:\n");

display(FIRST);
break;
case 5:
printf("The Current Linked List is:\n");
display(FIRST);

delete_last(&FIRST);
printf("The Linked List after Deletion is:\n");

display(FIRST);
break;
case 6:
printf("The Current Linked List is:\n");
display(FIRST);
printf("Enter The Position at which You want to Delete the Node:\n");
scanf("%d",&ipos);
delete_atPos(&FIRST,ipos);
printf("The Linked List after Deletion is:\n");

display(FIRST);
break;
case 7:
printf("The Current Linked List is:\n");
display(FIRST);
break;
case 8:
printf("The Number of Nodes in Linked List are:\n");
size=count(FIRST);
printf("%d\n",size);
break;
default: 
printf("INVALID CHOICE\n");
break;
}
}
return 0;
}

int count(PNODE head) //Singly Linear Count
{
int icnt=0;
while(head!=NULL)
{
icnt++;
head=head->next;
}
return icnt;
}

void display(PNODE head) //Singly Linear Display
{

while(head!=NULL)
{
printf("|%d|->",head->data);
head=head->next;
}
printf("|NULL|\n");
}


void insert_first(PPNODE head,int value) //Singly Linear Insert First
{

PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
newn->data=value;
newn->next=NULL;

if(*head==NULL)
{
*head=newn;
}
else
{
newn->next=*head;
*head=newn;
}
}

void insert_last(PPNODE head,int value)  //Singly Linear Insert last
{
PNODE temp=*head;
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
newn->data=value;
newn->next=NULL;
if(*head==NULL)
{
*head=newn;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newn;
}
}

void insert_atPos(PPNODE head,int ipos,int value) //Singly Linear Insert Atpos
{
PNODE temp=*head;
int i;
int isize=count(*head);
if((ipos<1) || (ipos>isize+1))
{
printf("Invalid Position");
}
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
newn->data=value;
newn->next=NULL;

if(*head==NULL)
{
*head=newn;
}
if(ipos==1)
{
insert_first(head,value);
}
else if(ipos==isize+1)
{
insert_last(head,value);
}
else
{
for(i=0;i<=ipos-2;i++)
{
temp=temp->next;
}
newn->next=temp->next;
temp->next=newn;
}
}

void delete_first(PPNODE head)  //Singly Linear Delete first
{
PNODE temp=*head;
if(*head==NULL)
{
printf("Linked list is Empty \n");
return;
}
else
{
*head=(*head)->next;
free(temp);
}
}

void delete_last(PPNODE head) //Singly Linear Delete last
{
PNODE temp=*head;
if(*head==NULL)
{
printf("Linked list is Empty \n");
return;
}
else if((*head)->next==NULL)
{
free(*head);
*head=NULL;
}
else
{
while(temp->next->next!=NULL)
{
temp=temp->next;
}
free(temp->next);
temp->next=NULL;
}
}

void delete_atPos(PPNODE head,int ipos) //Singly Linear Delete Atpos
{
PNODE temp1=*head;
PNODE temp2=NULL;
int i=0;
int isize=count(*head);
if((ipos<1) || (ipos>isize))
{
printf("Invalid Position");
}
if(*head==NULL)
{
printf("Linked list is Empty\n");
return;
}
if(ipos==1)
{
delete_first(head);
}
else if(ipos==isize)
{
delete_last(head);
}
else
{
for(i=1;i<=ipos-2;i++)
{
temp1=temp1->next;

}
temp2=temp1->next;
temp1->next=temp2->next;
free(temp2);
}
}





