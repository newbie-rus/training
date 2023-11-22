#include <stdio.h>
#include <stdlib.h>

const int amount_nums = 10;

int* bubble_sort(int* nums);
int* bubble_sort2(int* nums);

int main()
{
	int nums[amount_nums] = {};
	int nums0[amount_nums] = {};

	for (int i = 0; i < amount_nums; i++)
	{
		nums[i] = rand() % 1000;
		nums0[i] = nums[i];
	}
	for (int i = 0; i < amount_nums; i++)
		printf("[%3d]", nums[i]);
	printf("\n");
	
	int* nums1 = bubble_sort(nums);

	for (int i = 0; i < amount_nums; i++)
		printf("[%3d]", nums1[i]);
	printf("\n");

	int* nums2 = bubble_sort2(nums0);

	for (int i = 0; i < amount_nums; i++)
		printf("[%3d]", nums2[i]);
	printf("\n");

}


int* bubble_sort(int* nums)
{
	int amounts = 0;

	for (int j = 0, step = amount_nums - 1; j < amount_nums; j++)
	{
		for (int p = 0; p < step; p++)
		{
			if (nums[p] > nums[p+1])
			{
				amounts++;
				int tmp = nums[p];
				nums[p] = nums[p+1];
				nums[p+1] = tmp;
			}
		}
		step--;
	}
	printf("Bubble_sort сделал %d обменов\n", amounts);
	return nums;
}

int* bubble_sort2(int* nums)
{
	int amount = 0;

	for (int j = 0, step = amount_nums - 1; j < amount_nums / 2; j++)
	{
		for (int p = 0; p < step; p++)
		{
			if (nums[p] > nums[p+1])
			{
				amount++;
				int tmp = nums[p];
				nums[p] = nums[p+1];
				nums[p+1] = tmp;
			}
		}

		for (int i = step; i > amount_nums - step - 2; i--)
		{
			if (nums[i] < nums[i-1])
			{
				amount++;
				int tmp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = tmp;
			}
		}

		step--;
	}

	printf("Bubble_sort2 сделал %d обменов\n", amount);
	return nums;
}