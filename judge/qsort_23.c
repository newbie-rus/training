#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2);

int main()
{
	int N = 0;
	scanf("%d", &N);
	int *nums = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &nums[i]);
	}
	qsort(nums, N, sizeof(int), compare);
	for (int i = 0; i < N; i++)
	{
		printf("%d", nums[i]);
		if (i != N - 1)
			printf(" ");
		else
			printf("\n");
	}
	free(nums);
}

int compare(const void *arg1, const void *arg2)
{
	return (*(const int*)arg2 % 10) - (*(const int*)arg1 % 10);
}

int compare1(const void *arg1, const void *arg2)
{
	return (*(const int*)arg2 % 100) - (*(const int*)arg1 % 100);
}

int compare2(const void *arg1, const void *arg2)
{
	return *(const int*)arg2 - *(const int*)arg1;
}

int compare3(const void *arg1, const void *arg2)
{
	return *(const int*)arg2 - *(const int*)arg1;
}
