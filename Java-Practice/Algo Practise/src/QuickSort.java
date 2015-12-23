import java.util.Arrays;

public class QuickSort {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] unSortedArray = {0, 3, 1, 2, 13, 5, 9, 6, 4, 8, 4, 3, 1, 5, 9, 8, 17, 12};
		int [] sortedArray = QuickSort(unSortedArray, 0, unSortedArray.length - 1);
		System.out.println("Sorted array is "+ Arrays.toString(sortedArray));

	}
	
	private static int [] QuickSort(int [] unSortedArray, int start, int end){
		int i = start - 1;
		if(start >= end){
			return unSortedArray;
		}
		for(int j = start; j <= end; j++ ){
			if(unSortedArray[j] <= unSortedArray[end]){
				i = i + 1;
				int temp = unSortedArray[i];
				unSortedArray[i] = unSortedArray[j];
				unSortedArray[j] = temp;
			}
		}
		int [] leftSortedArray = QuickSort(unSortedArray, start, i-1);
		int [] rightSortedArray = QuickSort(unSortedArray, i+1, end);
		
		int [] sortedArray = new int [unSortedArray.length];
		int j;
		for(j = start; j < i; j++){
			sortedArray[j] = leftSortedArray[j];
		}
		sortedArray[j] = unSortedArray[i];
		for(j = i+1; j<=end; j++){
			sortedArray[j] = rightSortedArray[j];
		}
		return sortedArray;
	}

}
