#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void my_qsort(void* array, size_t sz_array, size_t sz_elem, int (*compare)(const void*, const void*));
void swap(void *arg1, void* arg2, size_t sz_elem);
int compare (const void *arg1, const void *arg2);

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"

int main()
{
	const int amount = 10;
	printf("Start mazafaka\n");
	int *nums = (int*)calloc(amount, sizeof(int));
	
	for (int i = 0; i < amount; i++)
		nums[i] = rand() % 1000;
	
	for (int i = 0; i < amount; i++)
		printf("{%3d}", nums[i]);
	printf("\n");

	my_qsort(nums, amount, sizeof(int), compare);

	for (int i = 0; i < amount; i++)
		printf("[%3d]", nums[i]);
	printf("\n");

	int j = 1; 
	for (int i = 0; i < amount - 1; i++)
	{
		if (nums[i] > nums[i+1])
			j = 0;
	}
	printf("\nCHECK WORK MYQSORT: <<%d>>\n", j);

	free(nums);
	return 0;
}

int compare (const void *arg1, const void *arg2)
{
	return *((const int*)arg1) - *((const int*)arg2);
}

void my_qsort(void* array, size_t sz_array, size_t sz_elem, int (*compare)(const void*, const void*))
{
	char *pivot      = (char*)array + (sz_array / 2) * sz_elem;
	char *array_end  = (char*)array + sz_elem * (sz_array - 1);
	char *left       = (char*)array;
	char *right      = array_end;

	if (sz_array == 2)
	{
		if (compare(left, right) > 0)
			swap(left, right, sz_elem);

		return;
	} 

	while (left < right)
	{
		while (compare(left, pivot) < 0 && left < right && left <= pivot) 
			left = left + sz_elem;

		while (compare(right, pivot) > 0 && left < right && right >= pivot)
			right = right - sz_elem;

		if (left < right)
		{	
			if (left == pivot)
			{
				swap(left, right, sz_elem);
				pivot = right;
				left += sz_elem;
			}			
			else if (right == pivot)
			{
				swap(left, right, sz_elem);
				pivot = left;
				right -= sz_elem;
			}
			else
			{
				swap(left, right, sz_elem);
				right -= sz_elem;
				left  += sz_elem;
			}
		}
		else if (left == right)
			left += sz_elem;
	}

	if (((size_t)(pivot - (char*)array) / sz_elem) > 1)
		my_qsort(array, (size_t)(pivot - (char*)array) / sz_elem, sz_elem, compare);

	if (((size_t)(array_end - pivot) / sz_elem) > 1)
		my_qsort(pivot + sz_elem, ((size_t)(array_end - pivot) / sz_elem), sz_elem, compare);
}

void swap(void *arg1, void* arg2, size_t sz_elem)
{
	size_t sz_type = sizeof(int64_t);

	while (sz_elem != 0)
	{
		size_t i = 0, j = sz_elem / sz_type;
		switch (sz_type)
		{
		case sizeof(int64_t):
			while (i < j)
			{
				int64_t tmp = *(int64_t*)arg1;
				*(int64_t*)arg1 = *(int64_t*)arg2;
				*(int64_t*)arg2 = tmp;
				arg1 = (int64_t*)arg1 + 1; 
				arg2 = (int64_t*)arg2 + 1;
				i++; 
			}
			break;		
	
		case sizeof(int32_t):
			while (i < j)
			{
				int32_t tmp = *(int32_t*)arg1;
				*(int32_t*)arg1 = *(int32_t*)arg2;
				*(int32_t*)arg2 = tmp;
				arg1 = (int32_t*)arg1 + 1; 
				arg2 = (int32_t*)arg2 + 1; 
				i++;
			}
			break;

		case sizeof(int16_t):
			while (i < j)
			{
				int16_t tmp = *(int16_t*)arg1;
				*(int16_t*)arg1 = *(int16_t*)arg2;
				*(int16_t*)arg2 = tmp;
				arg1 = (int16_t*)arg1 + 1; 
				arg2 = (int16_t*)arg2 + 1; 
				i++;
			}
			break;

		case sizeof(int8_t):
			while (i < j)
			{
				int8_t tmp = *(int8_t*)arg1;
				*(int8_t*)arg1 = *(int8_t*)arg2;
				*(int8_t*)arg2 = tmp;
				arg1 = (int8_t*)arg1 + 1; 
				arg2 = (int8_t*)arg2 + 1;
				i++; 
			}
			break;

		default:
			break;
		}

		sz_elem -= sz_type * j;
		sz_type /= 2;
	}
}