#include <iostream>
#include <stdlib.h>

typedef char SElemType;
typedef char QElemType;

typedef struct STNode
{
	SElemType data;
	struct STNode* next;
}STNode, *LinkStack;

void InitStack(LinkStack& S)
{
	S = NULL;
}

void GetTop(LinkStack S, SElemType& e)
{
	e = S->data;
}

void Push(LinkStack& S, SElemType e)
{
	LinkStack p;
	p = (LinkStack)malloc(sizeof(STNode));
	if(p)
	{
		p->data = e;
		p->next = S;
		S = p;
	}

}

void Pop(LinkStack& S, SElemType& e)
{
	LinkStack p;
	e = S->data;
	p = S;
	S = S->next;
	free(p);
}

typedef struct QNode {
	QElemType    data;
	struct QNode* next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr  front;
	QueuePtr  rear;
}LinkQueue;

void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
}

void EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

void DeQueue(LinkQueue& Q, QElemType& e)
{
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
		if(Q.rear == p)  Q.rear = Q.front;
	delete p;
}

void Interpret(LinkStack& S)
{
	LinkQueue Q;
	InitQueue(Q);
	char letter, theta;
	Pop(S, letter);

	while (S!=NULL)
	{
		if (letter == ')')
		{
			Pop(S,letter);
		}
		if (letter == 'B')
		{
			std::cout<<"tsaedsae";
			Pop(S, letter);
		}
		if (letter == 'A')
		{
			std::cout<<"sae";
			Pop(S, letter);
		}
		if(letter>='a'&&letter<='z')
		{
			std::cout<<letter;
			Pop(S,letter);
		}
		if(letter>='0'&&letter<='9')
		{
			std::cout<<letter;
			Pop(S,letter);
		}
		if (letter == '(')
		{
			Pop(S, letter);
			
			if(letter!=')')
			{
				while (letter != ')')
				{
					EnQueue(Q, letter);
					Pop(S, letter);
					if (letter == ')')
					{
						Push(S, ')');
						break;
					}
				}
				DeQueue(Q, theta);
				while (Q.front!=Q.rear)
				{
					DeQueue(Q, letter);
					Push(S, theta);
					Push(S, letter);
				}
				Push(S, theta);
				while (letter!=')'&&S!=NULL)
				{
					Pop(S, letter);
					if(letter!=')'){
						if(letter=='A')
							std::cout<<"sae";
						else if(letter=='B')
							std::cout<<"tsaedsae";
						else std::cout<<letter;
					}
						
				}
			}else if(letter==')');
		}

	}
}
int main()
{
	LinkStack S;
	LinkQueue Q;
	InitStack(S);
	InitQueue(Q);
	char letter;
	while (true)
	{
		letter=std::cin.get();
		Push(S, letter);
		if (letter == '\n')break;
	}
	while (S != NULL)
	{
		Pop(S, letter);
		EnQueue(Q, letter);
	}
	while (Q.front != Q.rear)
	{
		DeQueue(Q, letter);
		Push(S, letter);
	}
	Interpret(S);
	return 0;
}

