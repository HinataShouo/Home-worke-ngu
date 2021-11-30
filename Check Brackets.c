#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>


typedef struct Tlist {
	char value;
	struct Tlist* next;
}Tlist;

Tlist* ScanList(int n) {
	if (n == 0) {
		return NULL;
	}
	Tlist* list = malloc(sizeof(*list));
	assert(list != NULL);

	if (scanf("%c", &list->value) != 1) {
		return NULL; //assert
	}

	list->next = ScanList(n - 1);

	return list;
}

void Push(Tlist** list, char value) {
	struct Tlist* new = malloc(sizeof(*new)); //заебал, ты же написал typedef (8 строка), можно не писать struct
	assert(new != NULL);

	new->value = value;
	new->next = *list;
	*list = new;
}

char Pop(Tlist** list) {
	assert(*list);

	char c = (*list)->value;

	Tlist* new = (*list);
	*list = (*list)->next;

	free(new);
	return c;
}

bool StartBrackets(char a) {
	return a == '(' || a == '{' || a == '[';
}

bool EndBrackets(char b) {
	return b == ')' || b == '}' || b == ']';
}

bool IsMatch(char a, char b) {
	return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
}

void Check(Tlist** list) {
	Tlist* s = NULL; //когда-нибудь я заслужу уважение и буду читать код с нормально названными переменными

	while (list) {
		char c = (*list)->value;
		if ( c == EndBrackets(c) ) { //нахуя ты присваиваешь значение? char и bool?

			if (s == NULL || !IsMatch(Pop(&s), c)){
				printf("not ok...\n");

				return;
			}

		}

		else { //А зачем тебе StartBrackets? В твой список будет заноситься всё кроме EndBrackets
			Push(&s, c);
		}
	}

	if (s!=NULL) {
		printf("not ok...\n");
	}
	else {
		printf("ok\n");
	}

}

int main(void) {
	Tlist* list = ScanList(3);

	Check(&list);

	return 0;
}
