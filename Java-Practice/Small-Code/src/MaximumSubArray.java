public class MaximumSubArray {
	public static void main(String[] args) {
		int [] array = {-3, -2, 6, 7, -10, 33};
		printMaximumSubArray(array);
	}
	
	private static void printMaximumSubArray(int [] array){
		int maxStart = 0;
		int maxEnd = 0;
		int currentStart = 0;
		int maxValue = array[0];
		int currentSum = 0;
		
		for(int i=0; i < array.length; i++){
			currentSum = currentSum + array[i];
			if(currentSum > maxValue){
				maxValue = currentSum;
				maxEnd = i;
				maxStart = currentStart;
			}
			if(currentSum <= 0){
				currentStart = i+1;
				currentSum = 0;
			}
		}
		System.out.println("Maximum sum "+maxValue + " start "+maxStart + " end " + maxEnd);
	}

}
