package SortTest;

public class BubbleSortAdvance {
	private int[] arr;
	private int len = 0;
	
	public BubbleSortAdvance(int[] array)
	{
		this.arr = array;
		this.len = array.length;
	}

	public void runSort()
	{
		boolean sorted = false;
		int tmp = 0;
		
		for (int i = 0; i < len; i++)
		{
			sorted = true;
			for (int j = 1; j < len - i; j++)
			{
				if (arr[j] < arr[j -1])
				{
					tmp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = tmp;
					
					sorted = false;
				}
			}
			
			if(sorted)
			{
				break;
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
