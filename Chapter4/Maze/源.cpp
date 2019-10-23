#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate
{
	int x;
	int y;
	int direction;
}Coordinate;

typedef Coordinate ElementType;

typedef struct LinkNode
{
	ElementType coordinate;
	struct LinkNode *next;
};

typedef struct
{
	LinkNode *top;
}LinkStack;

void initStack(LinkStack *stack)
{
	stack->top = NULL;
}

int isEmpty(LinkStack *stack)
{
	if (stack->top != NULL)
		return 0;
	else
		return 1;
}

void pushStack(LinkStack* stack, ElementType x)
{
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));

	s->coordinate = x;
	s->next = stack->top;
	stack->top = s;
}

ElementType popStack(LinkStack* stack)
{
	ElementType x;
	LinkNode *p;
	ElementType tmpNull = { 0,0,0 };
	if (stack->top == NULL)
	{
		return tmpNull;
	}
	else
	{
		x = stack->top->coordinate;
		p = stack->top;
		stack->top = p->next;
		free(p);
		return x;
	}
}

int sizeOfStack(LinkStack stack)
{
	int i;
	LinkNode* Numb;
	i = 0;
	Numb = stack.top;
	while (Numb != NULL)
	{
		Numb = Numb->next;
		i++;
	}
	return i;
}

