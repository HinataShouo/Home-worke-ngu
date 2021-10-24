#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <malloc.h> //что за хуйня? нужно <stdlib.h>

typedef int Data; //зачем, если нигде не используешь?
typedef struct Tlist {
	int value;
	struct Tlist* next;
}Tlist;

Tlist* ScanList(int n) {

	if (n == 0) {
		return NULL;
	}

	Tlist* list = malloc(sizeof(*list)); // нужно проверить выделилась ли память
	if (scanf("%d", &list->value) == EOF) {
		return 0; // 0 - не TList* // лучше использовать assert
	}

	list->next = ScanList(n - 1);

	return list;
}

int SumList(Tlist* list) {
	if (list->next == NULL) { // при [ 10 ] сумма будет равнятся 0
		return 0;
	}
	else {
		return list->value + SumList(list->next);
	}
}

int main() {
	int n;
	if (scanf("Count of elements = %d", &n) == EOF) { //scanf ничего не печатает
		return 0;
	}
	Tlist* list = ScanList(n);

	printf("Sum = %d",SumList(list));

	return 0;
}
