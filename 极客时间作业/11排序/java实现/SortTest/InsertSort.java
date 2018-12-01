package SortTest;

public class InsertSort {
	private int[] array;
	private int   len;
	
	public InsertSort(int[] array)
	{
		this.array = array;
		this.len = array.length;
	}
	
	public void runSort()
	{
		int tmp = 0;
		
		for (int i = 1; i < len; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (array[j] < array[j-1])
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
	
	public void printSort()
	{
		for (int i = 0; i < len; i++)
		{
			System.out.printf("%d ",array[i]);
		}
		
		System.out.println();
	}

}
