#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int bigger(int a, int b) {

	return a>b;

}

int smaller(int a, int b) {

	return a<b;

}

typedef struct heap {
	int arr[50];
	int size;
	int(*cmp)(int a, int b);
}heap;

int getParent(int index) {

	if (index == 0)
		return index;

	return index % 2 ? index / 2 : index / 2 - 1;
}


int getChild(int index, heap* mHeap) {

	if (mHeap->size < 2 * index + 1)
		return mHeap->size;

	if (mHeap->size == 2 * index + 1)
		return 2 * index + 1;

	return mHeap->cmp(mHeap->arr[2 * index + 1], mHeap->arr[2 * index + 2]) ? 2 * index + 1 : 2 * index + 2;

}

void printHeap(heap* h) {
	int index = 0;
	printf("heap size: %d\n", h->size);
	while (index < h->size) {
		printf("%d, ", h->arr[index++]);
	}
	printf("\n");

}


void addHeap(heap* mHeap, int elem) {
	mHeap->arr[mHeap->size] = elem;

	//put in the last place

	int index = mHeap->size;
	int parentIndex = getParent(index);

	// heapify
	while (mHeap->cmp(elem, mHeap->arr[parentIndex])) {
		swap(&mHeap->arr[parentIndex], &mHeap->arr[index]);
		index = parentIndex;
		parentIndex = getParent(index);
	}


	mHeap->size++;
}

void removeHead(heap* mHeap) {
	mHeap->size--;
	mHeap->arr[0] = mHeap->arr[mHeap->size];
	int index = 0;
	int childIndex = getChild(index, mHeap);
	while (mHeap->cmp(mHeap->arr[childIndex], mHeap->arr[index])) {
		swap(&mHeap->arr[childIndex], &mHeap->arr[index]);
		index = childIndex;
		childIndex = getChild(index, mHeap);

	}
}

int take(int elem) {
	static heap lowers = { 0 };
	static heap highers = { 0 };

	//max heap
	lowers.cmp = &bigger;
	// min heap
	highers.cmp = &smaller;

	// add to one of the heaps
	if (lowers.arr[0] > elem)
		addHeap(&lowers, elem);
	else
		addHeap(&highers, elem);

	// balance the heaps
	if (lowers.size > highers.size + 1) {
		addHeap(&highers, lowers.arr[0]);
		removeHead(&lowers);
	}

	if (highers.size > lowers.size) {
		addHeap(&lowers, highers.arr[0]);
		removeHead(&highers);
	}

	return lowers.arr[0];
}


int main() {
	printf("%d\n", take(20));
	printf("%d\n", take(10));
	printf("%d\n", take(30));
	printf("%d\n", take(5));
	printf("%d\n", take(40));
	printf("%d\n", take(0));
}