
#include <stdio.h>

struct node {
	int data;
	struct node* next;
};
int count = 0;
struct node* midlle;
struct node* head;

int take(int a)
{
	count++;
	struct node* temp = malloc(sizeof(struct node));
	temp->data = a;
	if (count == 1) {
		midlle = temp;
		head = temp;
	}
	else
		head->next = temp;
	head = temp;
	if (count % 2 == 0)
		midlle = midlle->next;

	return midlle->data;
}

int main()
{
	int b = 0;
	for (int i = 0; i < 5; ++i)
	{
		scanf_s("%d", &b);
		printf("midlle=%d\n", take(b));
	}

	return 0;
