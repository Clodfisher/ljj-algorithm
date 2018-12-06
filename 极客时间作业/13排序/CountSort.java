package SortTest;

public class CountSort {
	public static void countingsort(int[] arr, int n) {
		//1、查找该数组中最大的元素max
		int max = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		//2、申请计数数组，大小0-max，存放数组中每个元素的计数
		int[] count = new int[max+1];
		for (int i = 0; i < max+1; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			count[arr[i]]++;
		}
		//3、遍历计数数组，idx从小到大累加
		for (int i = 1; i < max + 1; i++)
		{
			count[i] = count[i-1]+count[i];
		}
		
		//4、从大到小遍历源数组，根据计数数组中元素的个数，将源数组中的元素依次放入临时数组,
		//从大到小遍历的原因是保证稳定性
		int[] tmp = new int[n];
		for (int i = n - 1; i >= 0; i--)
		{
			int index = count[arr[i]]-1;
			tmp[index] = arr[i];
			count[arr[i]]--;
			
		}
		//5、将数据从临时数组拷贝到源数组
		for(int i =0 ;i < n;i++)
		{
			arr[i] = tmp[i];
		}
	}
	public static void main(String[] args)
	{
		int[] arr = {2,5,3,0,2,3,0,3};
		countingsort(arr,arr.length);
		for (int i = 0; i < arr.length; i++)
		{
			System.out.printf("%d ", arr[i]);
		}
		System.out.println();
	}

}
