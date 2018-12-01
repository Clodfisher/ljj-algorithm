package SortTest;

public class InsertSortAdvance {
	private int[] arr;
	private int len = 0;
	
	public InsertSortAdvance(int[] arr)
	{
		this.arr = arr;
		this.len = arr.length;
	}
	
	public void runSort()
	{
		int value = 0;
		
		for (int i = 1; i < len; i++)
		{
			value = arr[i];
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (arr[j] > value)
				{
					arr[j + 1] = arr[j];
				}
				else
				{
					break;
				}
				
			}
			arr[j + 1] = value;
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
