import java.util.Arrays;

 public class MergeSort {
	public static void main(String[] args) {
		int [] unSortedArray = {5, 1, 4, 2, 7, 8, 3, 5, 9, 0, 6, 11, 19};
		int low = 0;
		int high = unSortedArray.length - 1;
		int [] sortedArray = mergeSort(unSortedArray, low, high);
		for(int i = 0; i < sortedArray.length; i++){
			System.out.println(sortedArray[i]);
		}
		// TODO Auto-generated method stub

	}
	
	private static int[] mergeSort(int [] unSortedArray, int low, int high){
		int arrayLength = high - low + 1;
		if(arrayLength == 1){
			return unSortedArray;
		}
		else if (arrayLength == 2){
			if(unSortedArray[low] >= unSortedArray[high]){
				return unSortedArray;
			}
			else {
				int temp = unSortedArray[high];
				unSortedArray[high] = unSortedArray[low];
				unSortedArray[low] = temp;
				return unSortedArray;
			}
		}else{
			int mid = low + (high - low)/2;
			int [] sortedArray1 = mergeSort(unSortedArray, low, mid );
			int [] sortedArray2 = mergeSort(unSortedArray, mid+1, high);
			int [] sortedArray = sortTwoSortedArrays(sortedArray1, sortedArray2, low, high);
			return sortedArray;
		}
	}
	
	private static int [] sortTwoSortedArrays(int [] sortedArray1, int [] sortedArray2, int low, int high){
		int mid = low + (high - low)/2;
		int length = sortedArray1.length;
		int [] sortedArray = new int [length];
		int i = low; 
		int j= mid + 1;
		for(int k = low; k <= high; k++){
			if((i <= mid) && (j <= high)){
				if(sortedArray1[i] >= sortedArray2[j]){
					sortedArray[k] = sortedArray1[i];
					i++;
				}
				else{
					sortedArray[k] = sortedArray2[j];
					j++;
				}
			}
			else{
				if(i > mid){
					sortedArray[k] = sortedArray2[j];
					j++;
				}
				else{
					sortedArray[k] = sortedArray1[i];
					i++;
				}
			}
		}
		return sortedArray;
	}
}
