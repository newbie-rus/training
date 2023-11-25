#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int partition(size_t sz_elem, void *left, void *right);
void my_qsort(void* array, size_t sz_array, size_t sz_elem, int (*compare)(const void*, const void*));
void swap(void *arg1, void* arg2, size_t sz_elem);
int compare (const void *arg1, const void *arg2);


int main()
{
	printf("Start mazafaka\n");
	int nums[10] = {};
	
	for (int i = 0; i < 10; i++)
		nums[i] = rand() % 1000;
	
	for (int i = 0; i < 10; i++)
		printf("{%3d}", nums[i]);
	printf("\n");

	my_qsort(nums, sizeof(nums) / sizeof(nums[0]), sizeof(int), compare);

	for (int i = 0; i < 10; i++)
		printf("[%3d]", nums[i]);
	printf("\n");

	return 0;
}

int compare (const void *arg1, const void *arg2)
{
	printf("[COMPARE]\n");
	printf("arg1 %3d / arg2 %3d / return %d\n\n", *((int*)arg1), *((int*)arg2), *((int*)arg1) - *((int*)arg2));

	return *((int*)arg1) - *((int*)arg2);
}

void my_qsort(void* array, size_t sz_array, size_t sz_elem, int (*compare)(const void*, const void*))
{
	char *pivot      = (char*)array + (sz_array / 2) * sz_elem;
	char *array_end  = (char*)array + sz_elem * (sz_array - 1);
	char *left       = (char*)array;
	char *right      = (char*)array + sz_elem * (sz_array - 1);
	bool sort_finish = true;

	printf("<<new_array>>\n");
	for (int i = 0; i < sz_array; i++)
		printf("(%3d)", *((int*)array + i));
	printf("\n");

	printf("pivot <%3d>\n", *(int*)pivot);
	printf("left  <%3d>\n", *(int*)left);
	printf("right <%3d>\n", *(int*)right);
	printf("\n");

	while (left <= right)
	{
		while (compare(left, pivot) <= 0)
			left += sz_elem;
	
		while (compare(right, pivot) > 0)
			right -= sz_elem;
		
		if (left <= right)
		{	
			if (left == pivot)
			{
				swap(left, right, sz_elem);
				pivot = right;
			}			
			else if (right == pivot)
			{
				swap(left, right, sz_elem);
				pivot = left;
			}
			else
				swap(left, right, sz_elem);
			
			sort_finish = false;
			
			for (int i = 0; i < sz_array; i++)
				printf("(%3d)", ((int*)array)[i]);
			printf("\n");
		}
		if (left <= right)
		{
			right -= sz_elem;
			left += sz_elem;
		}
	}

	if (!sort_finish && ((right - (char*)array) / sz_elem + 1) > 1)
		my_qsort(array, (right - (char*)array) / sz_elem + 1, sz_elem, compare);

	if (!sort_finish && ((array_end - left) / sz_elem + 1) > 1)
		my_qsort(left, (array_end - left) / sz_elem + 1, sz_elem, compare);
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