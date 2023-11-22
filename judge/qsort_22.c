#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *arg1, const void *arg2);

int main()
{
	char chars[1001] = {0};

	fgets(chars, 1001, stdin);

	qsort(chars, strlen(chars) - 2, sizeof(char), compare);

	puts(chars);
}

int compare(const void *arg1, const void *arg2)
{
	return *(const char*)arg1 - *(const char*)arg2;
}
