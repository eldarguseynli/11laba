#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct word{
	char *letters;
	struct word *next;
	struct word *prev;
}word;

void create_sentence(word **p);
void addFront(word **head, char *letters);
void print_poly(word *head);
void delete_word(word *word);
void delete_last_word(word *head);
void delete_sentence(word *head);