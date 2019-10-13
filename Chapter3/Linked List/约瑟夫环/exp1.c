#include <stdlib.h>
#include <stdio.h>

struct Node;
typedef struct Node* pNode;
typedef int ElementType;

struct Node
{
	int number;
	ElementType Element;
	pNode Next;
};

/* Create a linked list */
void InitList(pNode L)
{
	L = (pNode)malloc(sizeof(struct Node));
	L->Next = NULL;
}

/* Delete node that p points to */
/* Only for circylar linked list */
void Delete(pNode p)
{
	pNode previous = p;
	while (previous->Next != p && previous->Next != NULL) {
		previous = previous->Next;
	}
	
	previous->Next = p->Next;
	free(p);
}

/* Insert a node after position P */

void Add(ElementType X, pNode P)
{
	pNode newNode = NULL;

	newNode = (pNode)malloc(sizeof(struct Node));
	
	newNode->Element = X;
	newNode->Next = NULL;
	P->Next = newNode;
}

/* Get the last element's position */
pNode Last(pNode L)
{
	pNode p = NULL;
	p = L;
	while (p->Next != NULL) {
		p = p->Next;
	}
	return p;
}

/* get the x th element after p */
pNode GetPosition(pNode p, int x)
{
	int i;
	for (i = 0; i < x && p->Next != NULL; i++) {
		p = p->Next;
	}
	return p;
}

/* Put an array[n] in a list, */
void PutArrayInList(pNode L, int array[], int n)
{
	int i;
	pNode position = NULL;
	position = L;
	for (i = 0; i < n; i++) {
		Add(array[i], position);
		position->Next->number = i + 1;
		if(position->Next != NULL)
		position = position->Next;
	}
}

/* switch a single linked list to a circylar linked list */
pNode SwitchToCircylarLinkList(pNode L)
{
	pNode position = NULL, deletePosition = NULL;
	position = Last(L);
	position->Next = L->Next;
	deletePosition = L;
	free(deletePosition);
	return position->Next;
}

int main(){
	int n, m, i, pchange, keys[n];
	struct Node node;
	pNode list,position,deletedPosition;
	list = &node;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n ; i++ ){
		scanf("%d", &keys[i]);
	}
	if(n==1){printf("1");return 0;}

	InitList(list);//initialization of a linked list
	PutArrayInList(list, keys, n);//put an array into the list while its initialization
	list = SwitchToCircylarLinkList(list);//switch single linked list to circylar linked lists
	
	position = list;
	for(i=0;n>0;i++){
		
		pchange = m%n-1;// pchange is position of the next elected player which must be positive
		while(pchange<0)
			pchange+=n;
			 
		position = GetPosition(position, pchange); //change position to that of next elected player
		printf("%d ", position->number);//print lucky number

		m = position->Element;//get new m value
		
		deletedPosition = position;
		position = position->Next;//move position in order to get into next round
		Delete(deletedPosition);//delete elected player
		
		n--;//players decrease
	}
}
