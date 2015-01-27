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



int main(void)
{	
	struct llnode *lst1=cons(3, cons(3, cons(5, empty())));
	printf("%d", length_iterative(lst1));
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