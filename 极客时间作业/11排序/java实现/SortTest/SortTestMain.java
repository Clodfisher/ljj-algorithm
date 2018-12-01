package SortTest;

public class SortTestMain{
	
	public static void main(String[] args)
	{
		int[] array = {2,4,3,1,5};
		
		SelectSortAdvance testobj = new SelectSortAdvance(array);
		//InsertSortAdvance testobj = new InsertSortAdvance(array);
		//BubbleSortAdvance testobj = new BubbleSortAdvance(array);
		testobj.runSort();
		testobj.printSort();
	}

}