#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
typedef struct node 
{
	int data;
	struct node *next;
}node;
void display(node **head)
{
	node *temp = *head;
	if(*head==NULL)
	{
		cout<<"LIST IS EMPTY !!!";
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" -> ";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	
}
void add_beg(node **head)
{
	node *new_node = (node*)malloc(sizeof(node));
	cout<<"Enter at beg :";
	cin>>new_node->data;
	new_node->next = NULL;
	new_node->next=(*head);
	(*head)=new_node;
	
	cout<<"INSERTION SUCCESSFULLY !!!"<<endl;
}
void add_middle(node **head)
{
	node *new_node = (node*)malloc(sizeof(node));
	node *temp = *head;
	int i,pos;
	cout<<"Enter position to enter :"<<endl;
	cin>>pos;
	cout<<"Enter node data :"<<endl;
	cin>>new_node->data;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}	
	new_node->next=temp->next;
	temp->next=new_node;
	
	cout<<"INSERTION SUCCESSFULLY !!!"<<endl;
	
}

void add_end(node **head)
{	
	node *new_node = (node*)malloc(sizeof(node));
	node *temp = *head;
	cout<<"Enter at end :";
	cin>>new_node->data;
	if((*head)==NULL)
	{
		cout<<"LIST IS EMPTY !!!!"<<endl;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}	
	temp->next=new_node;
	new_node->next=NULL;
	
	cout<<"INSERTION SUCCESSFULLY !!!"<<endl;
}
void del_beg(node **head)
{
	node *temp = *head;
	if(*head==NULL)
	{
		cout<<"LIST IS EMPTY !!!"<<endl;
	}
	else
	{
		*head = temp->next;
		delete(temp);
		cout<<"DELETION SUCCESSFULLY !!!"<<endl;
	}
	
}
void del_end(node **head)
{
	node *temp = *head;
	node *p;
	if(*head==NULL)
	{
		cout<<"LIST IS EMPTY !!!"<<endl;
	}
	else if(temp->next==NULL)
	{
		temp->next=NULL;
		cout<<"DELETION SUCCESSFULLY !!!"<<endl;
		delete(*head);
	}
	else
	{
		while(temp->next!=NULL)
		{
			p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		delete(temp);
		cout<<"DELETION SUCCESSFULLY !!!"<<endl;
	}
	
}
void del_pos(node **head)
{
	node *temp = *head;
	node *p;
	int i=0,pos;
	cout<<"Enter position to delete :"<<endl;
	cin>>pos;
	
	if(*head==NULL)
	{
		cout<<"LIST IS EMPTY !!!"<<endl;
	}
	else if(pos<=i)
	{
		cout<<"OOPS! BEGINING NODE CAN'T DELETE"<<endl;	
	}
	else
	{
		while(i<pos)
		{
			p=temp;
			temp=temp->next;
			i++;
		}
		p->next=temp->next;
		free(temp);
	}
}
void del_key(node **head)
{
	node *new_node=(node*)malloc(sizeof(node));
	node *temp = *head;
	node *p;
	int key;
	cout<<"Enter key to delete :"<<endl;
	cin>>key;

	
		while(temp->data!=key)
		{
			p=temp;
			temp=temp->next;
		
		}
		p->next=temp->next;
		free(temp);
	
	
}
void cnt(node **head)
{
	node *temp = *head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"Length of list is "<<count<<endl;
}
int main()
{
	node *head = NULL;
	int ch;
	while(1)
	{
		cout<<" ******* MENU ******* "<<endl;
		cout<<" 1. At Beg "<<endl;
		cout<<" 2. At Middle "<<endl;
		cout<<" 3. At end "<<endl;
		cout<<" 4. Display "<<endl;
		cout<<" 5. Delete at Beg "<<endl;
		cout<<" 6. Delete at End "<<endl;
		cout<<" 7. Delete at Position "<<endl;
		cout<<" 8. Count nodes "<<endl;
		cout<<" 9. Delete by key "<<endl;
		cout<<"Enter ur choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1 : add_beg(&head);	break;
			case 2 : add_middle(&head);	break;
			case 3 : add_end(&head);	break;
			case 4 : display(&head);	break;
			case 5 : del_beg(&head);	break;
			case 6 : del_end(&head);	break;
			case 7 : del_pos(&head);	break;
			case 8 : cnt(&head);		break;
			case 9 : del_key(&head);	break;
			
			default :cout<<"OOPS! You made a wrong choice"<<endl;
		}
	}
	return 0;
}
