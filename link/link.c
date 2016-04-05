/**
 * @file link.c
 * @brief this is a program of list reverse
 * @author cui
 * @version 1.0
 * @date 2016-04-05
 */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/**
 * @brief link struct
 */
typedef struct link
{
	struct link *p;///p is pointer
	int *num;///num is a data in list
}Link;

static Link *head = NULL, *tail = NULL;///head is head pointer,no data; tail is next pointer, keeping update.

static int count = 0;///count is number in list

/**
 * @brief the function creates new node
 *
 * @param val node data
 *
 * @return t list struct
 */
static Link* create_node(int* val)
{
	Link *t = NULL;
	t = (Link *)malloc(sizeof(Link));
	if(!t)
	{ printf("malloc error!\n");return NULL;}
	t->p = t;
	t->num = val;
	
	return t;
}

/**
 * @brief create a new empty list
 *
 * @return 0
 */
int create_link()
{
	head = create_node(NULL);
	if(!head)
	  return -1;

	count = 0;
	return 0;
}

/**
 * @brief get a index of list node
 *
 * @param index list subscribe
 *
 * @return pnode get result 
 */
static Link* get_node(int index)
{
	if(index<0 || index>=count)
	{
		printf("%s failed! index out of bound!\n", __func__);
		return NULL;
	}

	if(index < count)
	{
		int i = 0;
		Link *pnode = head->p;
		while((i++) < index)
		  pnode = pnode->p;

		return pnode;
	}
}

/**
 * @brief insert list data
 *
 * @param index subscribe
 * @param val value
 *
 * @return it depends on that condition 
 */
int dlink_insert(int index, int* val)
{
	if(index==0)
	  return dlink_insert_first(val);
	else
	  return dlink_append(val);
	return 0;
}

/**
 * @brief insert first value
 *
 * @param val
 *
 * @return 
 */
int dlink_insert_first(int* val)
{
	Link *pnode = create_node(val);
	if(!pnode)
	  return -1;

	pnode->p = head;
	head->p = pnode;
	tail = pnode;
	count++;
	return 0;
}

/**
 * @brief insert append value
 *
 * @param val
 *
 * @return 
 */
int dlink_append(int* val)
{
	Link *pnode = create_node(val);
	if(!pnode)
	  return -1;

	tail->p = pnode;
	pnode->p = head;
	tail = pnode;

	count++;
	return 0;
}

/**
 * @brief list reverse
 *
 * @param begin start subscribe
 * @param end end subscribe
 */
void reverse(int begin, int end)
{
	while(begin < end)
	{
		Link *tmp;
		tmp = (Link *)malloc(sizeof(Link));
		if(!tmp)
		  printf("malloc failed!\n");
		tmp->num = get_node(begin)->num;
		get_node(begin++)->num = get_node(end)->num;
		get_node(end--)->num = tmp->num;
		free(tmp);
	}

}

int main()
{
	int i,in;
	int arr[6] = {1,2,3,4,5,6};
	create_link();
	for(i=0; i<6; i++)
	{
		dlink_insert(i,&arr[i]);
	}
	for(i=0; i<6; i++)
	printf("%d ", *(get_node(i)->num));
	printf("\n");
	printf("please input data k: ");
	scanf("%d", &in);
	reverse(0,in-1);
	for(i=0; i<6; i++)
	printf("%d ", *(get_node(i)->num));
	printf("\n");
	return 0;
}

