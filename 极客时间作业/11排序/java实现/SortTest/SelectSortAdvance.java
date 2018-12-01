package SortTest;

public class SelectSortAdvance {
	private int[] arr;
	private int len = 0;
	
	public SelectSortAdvance(int[] array)
	{
		this.arr = array;
		this.len = array.length;
	}
	
	public void runSort()
	{
		int min = 0;
		int tmp = 0;
		
		for (int i = 0; i < len; i++)
		{
			min = i;
			for (int j = i + 1; j < len; j++)
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
	
	public void printSort()
	{
		for (int i = 0; i < len; i++)
		{
			System.out.printf("%d ",arr[i]);
		}
		
		System.out.println();
	}

}
