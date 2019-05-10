#include "word.h"
#include "interact_with_us.h"
#define MAX_SIZE 300
#define MAX_WORD_SIZE 50

void create_sentence(word **head) {

	char str[MAX_SIZE];
	while (1) {
		getClearly(str, MAX_SIZE);
		str[strlen(str) - 1] = 0; //get rid of '\n'
		int dot_flag = 0;
		for (int i = 0; str[i]; i++) {
			if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122) && str[i] != ' ') {
				if (str[i] != '.') { puts("You should input only latin letters. Try input sentence again.\n"); break; }
				else { dot_flag++; str[i + 1] = 0; }
			}
		}
		if (!dot_flag) { puts("You should input at least one dot. Try input sentence again.\n"); continue; }
		int flag = 0;
		for(int i = 0; str[i] != '.'; i++) {
			if (str[i] != ' ') { flag++; break; }
			break; 
		}
		if(!flag) { puts("You should input at least one letter. Try input sentence again.\n"); continue; }
		break;
	}
	char *pch = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
	pch = strtok(str, " .");
	while (pch) {
		addFront(head, pch);
		pch = strtok(NULL, " .");
	}
	free(pch);
}

void addFront(word **head, char *letters) {
	word *p = malloc(sizeof(word));
	p->letters = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
	strcpy(p->letters, letters);

	if (!*head) {
		p->next = p;
		p->prev = p;
	}
	else
	{
		p->next = *head;
		p->prev = (*head)->prev;

		(*head)->prev->next = p;
		(*head)->prev = p;
	}
	*head = p;
}

void print_poly(word *head) {
	word *p = head->prev;
	while (p != head) {
		printf("%s ", p->letters);
		p = p->prev;
	}
	printf("%s.\n", head->letters);
}

void delete_last_word(word *head) {
	char *last_word_letters = head->letters;
	word *p = head->next;
	while (p != head) {
		if (!strcmp(p->letters, last_word_letters)) {
			delete_word(&p);
		}
		else p = p->next;
	}
}

void delete_word(word **p) {

	word *p0 = *p;

	(*p)->prev->next = (*p)->next;
	(*p)->next->prev = (*p)->prev;

	(*p) = (*p)->next;
	free(p0->letters);
	free(p0);
}

void delete_sentence(word *head) {
	word *p = head->next;
	while (p != head) {
		
		p = p->next;

		free(p->prev->letters);
		free(p->prev);

	}
	free(head->letters);
	free(head);
}