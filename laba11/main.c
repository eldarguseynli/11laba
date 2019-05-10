#include "word.h"
int main() {
	word *head = NULL;
	puts("Input sentence which consists only of latin letters and end with a dot.");
	puts("Everything after dot will not be read.\n");
	create_sentence(&head);
	puts("\nSentence which is built with words from double linked list:\n");
	print_poly(head);
	delete_last_word(head);
	puts("\nThe same sentence but without words which match the last word in the sentence:\n");
	print_poly(head);
	delete_sentence(head);
}