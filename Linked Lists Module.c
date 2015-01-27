#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct llnode
{
	int item;
	struct llnode *next;
};

int first(struct llnode *lst);
struct llnode *rest(struct llnode *lst);
struct llnode *empty(void);
bool is_empty(struct llnode *lst);
struct llnode *cons(int f, struct llnode *r);
int length_iterative(struct llnode *lst);
struct llnode *sqr_list(struct llnode *lst);
struct llnode *insert(int n, struct llnode *slst);
void sqr_list_m(struct llnode *lst);
struct llnode *copy_list(struct llnode *lst);
void add_to_front (int n, struct llnode **ptr_front);
void remove_from_front (struct llnode **ptr_front);
void insert_sorted(int n, struct llnode **ptr_front);

int main(void)
{	
}

int first(struct llnode *lst)
{
	assert(lst!=NULL);
	return (*lst).item;
}

struct llnode *rest(struct llnode *lst)
{
	assert(lst!=NULL);
	return (*lst).next;	
}


struct llnode *empty(void)
{
	return NULL;
}

bool is_empty (struct llnode *lst)
{
	return lst==empty();
}

struct llnode *cons(int f, struct llnode *r)
{
	struct llnode *new=malloc(sizeof(struct llnode));
	(*new).item=f;
	(*new).next=r;
	return new;
}

int length_iterative(struct llnode *lst)
{
	int length=0;
	while (!is_empty(lst))
{
	length++;
	lst=rest(lst);
}

return length;}

struct llnode *sqr_list(struct llnode *lst)
{
	if(is_empty(lst)==true)
	{
		return empty();
	}
	
	else
	{
		return cons(first(lst)*first(lst), rest(lst));
	}
}

struct llnode *insert(int n, struct llnode *slst)
{
	if (is_empty(slst)==true)
	{
		return cons(n, empty());
	}
	
	if(n<=first(slst))
	{
		return cons(n, slst);
	}
	
	else
	{
		return cons(first(slst), insert(n,rest(slst)));
	}
}

void sqr_list_m(struct llnode *lst)
{
	while (lst!=NULL)
	{
		(*lst).item=(*lst).item*(*lst).item;
		lst=(*lst).next;
	}
}

struct llnode *copy_list(struct llnode *lst)
{
	if (lst==NULL)
	{
		return NULL;
	}
	else
	{
		return cons((*lst).item, copy_list((*lst).next));
	}
}

void add_to_front (int n, struct llnode **ptr_front)
{
	struct llnode *new=malloc(sizeof(struct llnode));
	(*new).item=n;
	(*new).next=*ptr_front;
	*ptr_front=new;
}

void remove_from_front (struct llnode **ptr_front)
{
	struct llnode *new=malloc(sizeof(struct llnode));
	(*new).item=first(rest(*ptr_front));
	(*new).next=rest(rest(*ptr_front));
	*ptr_front=new;
}

void insert_sorted(int n, struct llnode **ptr_front)
{
	struct llnode *cur=*ptr_front;
	struct llnode *prev=NULL;
	while ((cur!=NULL) && (n>(*cur).item))
	{
		prev=cur;
		cur=(*cur).next;
	}
	
	struct llnode *new=malloc(sizeof(struct llnode));
	(*new).item=n;
	(*new).next=cur;
	if (prev==NULL)
	{
		*ptr_front=new;
	}
	else
	{
		(*prev).next=new;	
	}
	
}