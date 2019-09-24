#include <stdlib.h>
#include <stdio.h>

struct Node;
typedef struct Node* List;
typedef int ElementType;

struct Node
{
	int number;
	ElementType Element;
	List Next;
};

/* Create a linked list */
void InitList(List L)
{
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
}

/* Delete node that p points to */
void Delete(List p)
{
	List previous = p;
	while (previous->Next != p && previous->Next != NULL) {
		previous = previous->Next;
	}
	
	previous->Next = p->Next;
	free(p);
}

/* Insert a node after position P */

void Add(ElementType X, List P)
{
	List newNode = NULL;

	newNode = (List)malloc(sizeof(struct Node));
	
	newNode->Element = X;
	newNode->Next = NULL;
	P->Next = newNode;
}

/* Get the last element's position */
List Last(List L)
{
	List p = NULL;
	p = L;
	while (p->Next != NULL) {
		p = p->Next;
	}
	return p;
}

/* get the x th element after p */
List GetPosition(List p, int x)
{
	int i;
	for (i = 0; i < x && p->Next != NULL; i++) {
		p = p->Next;
	}
	return p;
}

/* Put an array[n] in a list, */
void PutArrayInList(List L, int array[], int n)
{
	int i;
	List position = NULL;
	position = L;
	for (i = 0; i < n; i++) {
		Add(array[i], position);
		position->Next->number = i + 1;
		if(position->Next != NULL)
		position = position->Next;
	}
}

/* switch a single linked list to a circylar linked list */
List SwitchToCircylarLinkList(List L)
{
	List position = NULL, deletePosition = NULL;
	position = Last(L);
	position->Next = L->Next;
	deletePosition = L;
	free(deletePosition);
	return position->Next;
}

int main(){
	int n, m, i, pchange, keys[n];
	struct Node node;
	List list,position,deletedPosition;
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
		
		pchange = m%n-1;
		while(pchange<0)
			pchange+=n;
			 
		position = GetPosition(position, pchange); //change position to that of next elected player
		
		m = position->Element;//get new m value
		printf("%d ", position->number);//print lucky number
		
		deletedPosition = position;
		position = position->Next;//move position in order to get into next round
		Delete(deletedPosition);//delete elected player
		
		n--;//players are less
	}
}
