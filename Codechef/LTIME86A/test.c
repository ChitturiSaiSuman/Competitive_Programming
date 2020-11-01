#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#define is ==
#define or ||
#define size ((int)(1e6+1))
#define mod ((int)(1e9+7))
typedef long long int ll;
typedef struct list
{
	int data;
	struct list *next;
    struct list *prev;
}list;
list *new_list(int data)
{
    list *node = (list *)malloc(sizeof(list));
    node->data=data;
    node->prev=NULL;
    node->next=NULL;
    return node;
}
list *append(list *node, int data)
{
    list *temp = (list*)malloc(sizeof(list));
    temp->data=data;
    temp->prev=node;
    temp->next=NULL;
    node->next=temp;
    node=temp;
    return node;
}
list *delete(list *node)
{
    if(node->next is NULL)
        return NULL;
    list *temp=node;
    node=node->next;
    free(temp);
    node->prev=NULL;
    return node;
}
list *pop(list *node)
{
	if(node->prev is NULL)
		return NULL;
	list *temp=node;
	node=node->prev;
	free(temp);
	node->next=NULL;
	return node;
}
bool empty(list *node)
{
    return node is NULL;
}
void print_list(list *node)
{
    list *temp = node;
    while (!empty(temp))
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
	printf("\n");
}
int main()
{
	list *head = new_list(100);
	list *tail=head;
	for(int i=200;i<=1000;i+=100)
	{
		head=append(head,i);
		print_list(tail);
	}
	for(int i=1;i<=3;i++)
	{
		head=pop(head);
		print_list(tail);
	}
	return 0;
}