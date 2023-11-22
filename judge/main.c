#include <stdio.h>
#include <string.h>

char* my_strcat(char* s1, const char* s2);

int main()
{
	char s1[10] = "aboba";
	char* s2 = "popa";

	my_strcat(s1, s2);
	
	printf("%s\n", s1);
}

char* my_strcat(char* s1, const char* s2)
{
	short index;
	for (index = 0; s1[index] != '\0'; index++){};

	for (int i = 0; s2[i] != '\0'; i++)
	{
		s1[index] = s2[i];
		index++;
	}
	s1[index] = '\0';

	return s1;
}
