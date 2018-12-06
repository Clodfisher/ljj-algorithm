package SortTest;

public class CountSort {
	public static void countingsort(int[] arr, int n) {
		//1�����Ҹ�����������Ԫ��max
		int max = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		//2������������飬��С0-max�����������ÿ��Ԫ�صļ���
		int[] count = new int[max+1];
		for (int i = 0; i < max+1; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			count[arr[i]]++;
		}
		//3�������������飬idx��С�����ۼ�
		for (int i = 1; i < max + 1; i++)
		{
			count[i] = count[i-1]+count[i];
		}
		
		//4���Ӵ�С����Դ���飬���ݼ���������Ԫ�صĸ�������Դ�����е�Ԫ�����η�����ʱ����,
		//�Ӵ�С������ԭ���Ǳ�֤�ȶ���
		int[] tmp = new int[n];
		for (int i = n - 1; i >= 0; i--)
		{
			int index = count[arr[i]]-1;
			tmp[index] = arr[i];
			count[arr[i]]--;
			
		}
		//5�������ݴ���ʱ���鿽����Դ����
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
