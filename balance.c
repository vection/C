// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *prev;
}node;

bool isStringBalanced(char* sentence, int size);
void add(node **head, char c);
char pop(node **head);


int main()
{
	char *word = "{[]}{}";
	int size = strlen(word);
	if (isStringBalanced(word, size))
		printf("true\n");
	else
		printf("false\n");


	return 0;
}bool isStringBalanced(char* sentence, int size)
{
	node *head = NULL;
	char c, b;
	for (int i = 0;i < size;i++)
	{
		c = *(sentence + i);
		if (c == '{' || c == '[' || c == '(')
			add(&head, c);
		else if (c == '}' || c == ']' || c == ')')
		{
			if ((head) == NULL)
			{
				printf("null\n");
				return false;
			}
			else
			{
				b = pop(&head);
				if (b == '{'&&c == '}' || b == '['&&c == ']' || b == '('&&c == ')')
					;
				else
					return false;
			}
		}
	}
	if ((head) == NULL)
		return true;
	else
		return false;

}

void add(node **head, char c)
{


	node *temp = (node*)malloc(sizeof(node));
	temp->data = c;
	if ((head) == NULL)
		*head = temp;
	else
	{
		temp->prev = *head;
		*head = temp;
	}

}
char pop(node **head)
{
	if ((head) == NULL)
		return 'g';
	else
	{
		char c = (*head)->data;
		*head = (*head)->prev;
		return c;
	}
}