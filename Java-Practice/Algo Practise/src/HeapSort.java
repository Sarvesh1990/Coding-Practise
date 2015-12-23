import java.util.Arrays;

public class HeapSort {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] unSortedArray = {0, 3, 1, 2, 13, 5, 9, 6, 4, 8, 4, 3};
		int [] heapifiedArray = MaxHeapify(unSortedArray);
		System.out.println("Heapified array is "+Arrays.toString(heapifiedArray));
		int [] sortedArray = HeapSort(heapifiedArray);
		System.out.println("Sorted array is "+ Arrays.toString(sortedArray));
	}
	
	private static int [] MaxHeapify(int [] unSortedArray){
		int length = unSortedArray.length;
		for ( int i = length/2 - 1; i >= 0; i--){
			unSortedArray = Heapify(unSortedArray, i, unSortedArray.length);
		}
		return unSortedArray;
	}
	
	private static int [] HeapSort(int [] heapifiedArray){
		for(int i = heapifiedArray.length - 1 ; i > 0; i--	 ){
			int temp = heapifiedArray[0];
			heapifiedArray[0] = heapifiedArray[i];
			heapifiedArray[i] = temp;
			heapifiedArray = Heapify(heapifiedArray, 0, i);
		}
		return heapifiedArray;
	}
	
	private static int [] Heapify(int [] unSortedArray, int i, int length){
		if(i > length/2 - 1){
			return unSortedArray;
		}
		else{
			int leftNumber = unSortedArray[2*i + 1];
			int rightNumber = 0;
			if(length > 2*i + 2 ){
				rightNumber = unSortedArray[2*i + 2];
			}
			int max;
			int temp = 0;
			if(leftNumber >= rightNumber){
				if(leftNumber > unSortedArray[i]){
					temp = unSortedArray[2*i + 1];
					unSortedArray[2*i + 1] = unSortedArray[i];
					unSortedArray[i] = temp;
					unSortedArray = Heapify(unSortedArray, 2*i + 1, length);
							return unSortedArray;
				}
				else{
					return unSortedArray;
				}
			}
			else{
				if(rightNumber > unSortedArray[i]){
					temp = unSortedArray[2*i + 2];
					unSortedArray[2*i + 2] = unSortedArray[i];
					unSortedArray[i] = temp;
					unSortedArray = Heapify(unSortedArray, 2*i + 2, length);
					return unSortedArray;
				}
				else{
					return unSortedArray;
				}
			}
		}
	}

}
