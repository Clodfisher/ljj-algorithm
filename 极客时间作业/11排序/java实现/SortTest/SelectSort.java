package SortTest;

public class SelectSort {
	private int[] array;
	private int len;
	
	public SelectSort(int[] array)
	{
		this.array = array;
		this.len   = array.length;
	}
	
	public void runSort()
	{
		int tmp = 0;
		
		for (int i = 0; i < len; i++)
		{
			for (int j = i  + 1; j < len;j++)
			{
				if (array[j] < array[i])
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
			}
		}
	}
	
	public void printSort()
	{
		for(int i = 0; i < len; i++)
		{
			System.out.printf("%d ", this.array[i]);
		}
		System.out.println();
	}
}
