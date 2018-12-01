package SortTest;

public class BubbleSort {
	private int[] array;
	private int len;
	
	public BubbleSort(int[] array)
	{
		this.array = array;
		this.len   = array.length;
	}
	
	public void runSort()
	{
		int tmp = 0;
		
		for (int i = 0; i < len; i++)
		{
			for (int j = 1; j < len - i; j++)
			{
				if (array[j] < array[j - 1])
				{
					tmp = array[j];
					array[j] = array[j-1];
					array[j-1] = tmp;
				}
			}
		}
	}
	
	public void printSort()
	{
		for (int i = 0; i < len; i++)
		{
			System.out.printf("%d ", array[i]);
		}
		
		System.out.println();
	}

}
