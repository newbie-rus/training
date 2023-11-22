#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2);

int main()
{
	int N = 0;
	scanf("%d", &N);
	double *nums = (double*)calloc(N, sizeof(double));
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &nums[i]);
	}
	qsort(nums, N, sizeof(double), compare);
	for (int i = 0; i < N; i++)
	{
		printf("%.2lf", nums[i]);
		if (i != N - 1)
			printf(" ");
		else
			printf("\n");
	}
	free(nums);
}

int compare(const void *arg1, const void *arg2)
{
	double different = *(const double*)arg1 - *(const double*)arg2;
	if (different > 0.0001)
		return 1;
	else if (different < -0.0001)
		return -1;
	else
		return 0;
}
