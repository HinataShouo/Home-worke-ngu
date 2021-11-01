#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Tlist {
	int value;
	struct Tlist* next;
}Tlist;

struct Tlist* ScanList(int n) { //нахер тогда писал typedef, если всё равно пишешь struct?
	if (n == 0) {
		return NULL;
	}
	Tlist* list = malloc(sizeof(*list));
	assert(list > 0); //что за хуйня?

	if (scanf("%d", &list->value) != 1) {
		return NULL;
	}//не совсем согласен, лучше assert

	list->next = ScanList(n - 1);

	return list;
}

void PrintList(Tlist* list) {
	if (list) {
		printf("%d ", list->value);
		PrintList(list->next);
	}
}

int EnterTheSize() {
	int n;

	printf("enter the size: ");
	if (scanf("%d", &n) != 1) {
		return 0;
	}//assert

	return n;
}

int DelElem(Tlist** list) {//чуууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууууть-чуть колхозное название функции
	if (*list) {//во-первых неправильное условие, во-вторых assert
		return 0;
	}

	Tlist* new = *list;
	int value = new->value;
	*list = (*list)->next;
	free(new);

	return value;
}

struct TList* PushFront(int value, Tlist** list) { //Неправильно написал тип данных
	Tlist* new = malloc(sizeof(*new));
	assert(new > 0);//опять хуйня

	new->value = value;
	new->next = (*list);
	(*list) = new;

	return *list;
}

struct Tlist* AddToTheEnd(Tlist* list, int value) { //опять немноооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооооого колхозное название
	while ((list)->next) { //а если список пустой, то ошибка
		list = (list)->next; //зачем скобки?
	}

	list->next = PushFront(value, &(list->next)); //Элемент, который ты вставляешь никак не связан со списком

	return list->next;
}
void Rotate(Tlist** list) {
	int value = DelElem(list);
	AddToTheEnd(*list, value);
}

void FreeList(Tlist** list) {
	if (*list == NULL) {
		return;
	}
	Tlist* p = *list; //можно же использовать DelElem
	*list = (*list)->next;
	free(p);
	FreeList(list);
}

int main() {
	Tlist* list = ScanList(EnterTheSize());

	PrintList(list);
	printf("\n");

	Rotate(&list);

	PrintList(list);

	FreeList(&list);

	return 0;
}
