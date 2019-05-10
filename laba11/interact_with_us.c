#include "interact_with_us.h"

void clear(void) //func clears stdin buffer
{
	char c = 1;
	while (c = getchar() != '\n' && c != EOF); //read all symbols from stdin buffer until the EOF or \n
}

void getClearly(char *buf, int n) {
	fgets(buf, n, stdin); if (strlen(buf) == n - 1 && buf[n - 2] != '\n') clear();  //if user inputed more than limited number of symbols then clear buffer
}