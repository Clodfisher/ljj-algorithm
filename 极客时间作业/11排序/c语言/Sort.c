#include<stdio.h>

void insertSort(int *array, int len)
{
	int i = 0,j = 0, k = 0;
	int tmp = 0;

	for (i = 1; i< len; i++)
	{
		tmp = array[i];
		for (j = 0; j < i; j++)
		{
			if (tmp < array[j])
			{
				for (k = i; k > j; k--)
				{
					array[k] = array[k-1];
				}
				array[j] = tmp;
				break;
			}
		}
	}
	
}

void insertSortAdvance(int *array, int len)
{
	int i =0, j = 0;
	int tmp = 0;

	for (i= 1; i < len; i++)
	{	//相当于对于内部已经排序好的数组，根据位置为j的数据调整顺序，
		//比上面的方法少了一次for循环，也是利用数据已经排序好的特点
		for (j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
			else
			{
				break;
			}
		}
	}
}
/*本次优化点在于移动，不需要额外的存储空间*/
 void insertSortFinal(int *arr, int len)
{
	int i = 0, j = 0;
	int value = 0;

	for (i = 1; i < len; i++)
	{
		value = arr[i];
		j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] > value)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = value;

	}
}

void selectSort(int *array, int len)
{
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}

	}

}
/* 本次优化在于不用每次比较都要交换位置，只需要记录每次循环中最小的值即可 */
void selectSortAdvance(int *arr, int len)
{
	int i = 0, j = 0;
	int min=  0, tmp = 0;

	for (i = 0; i < len; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}

		}
		if (min != i)
		{
			tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}		
	}
}

void bubbleSort(int *array, int len)
{
	int i = 0, j = 0;
	int tmp = 0;

	for (; i < len; i++)
	{
		for (j = 1; j < len - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
			}

		}
	}

}
/* 本次改进增加了一个标记，在某次内层比较中如果没有交换的数据，说明数组已经有序 */
void bubbleSortAdvance(int * arr, int len)
{
	int i = 0, j = 0;
	int sorted = 0;
	int tmp    = 0;

	for (i = 0; i < len; i++)
	{
		sorted = 0;
		
		for (j = 1; j < len - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;

				sorted = 1;
			}
		}

		if (0 == sorted)
		{
			break;
		}

	}

}

void  printSortArray(int *array, int len)
{
	int i = 0;
	
	for (;i < len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	return;
}

int main(int argc, char *argv[])
{
	int array[] = {1,3,7,2,4};
	int len = sizeof(array)/sizeof(int);

	/*
	insertSort(array, len);
	printSortArray(array, len);

	insertSortAdvance(array, len);
	printSortArray(array, len);

	
	selectSort(array, len);
	printSortArray(array, len);

	bubbleSort(array, len);
	printSortArray(array, len);

	insertSortFinal(array, len);
	printSortArray(array, len);
	selectSortAdvance(array, len);
	printSortArray(array, len);*/

	bubbleSortAdvance(array, len);
	printSortArray(array, len);

	return;
}


