public class MaximumSubArrayRecursion {
	public static void main(String[] args) {
		int [] array = {-3, -2, 6, -7, -10, 33};
		int low = 0;
		int high = array.length - 1;
		Triplet myTriplet = getMaximumSubArray(array, low, high);
		System.out.println("i "+myTriplet.maxLow+ " j "+myTriplet.maxHigh + " value "+ myTriplet.maxValue);
	}
	
	private static Triplet getMaximumSubArray(int [] array, int low, int high){
		Triplet lowTriplet = new Triplet();
		Triplet highTriplet = new Triplet();
		Triplet crossingTriplet = new Triplet();
		
		int mid = low + (high - low)/2;
		
		if(low == high){
			Triplet triplet = new Triplet();
			triplet.maxHigh = low;
			triplet.maxLow = low;
			triplet.maxValue = array[low];
			return triplet;
		}
		
		lowTriplet = getMaximumSubArray(array, low, mid);
		highTriplet = getMaximumSubArray(array, mid + 1, high);
		crossingTriplet = getCrossingSubArray(array, low, high);
		
		if(lowTriplet.maxValue > highTriplet.maxValue && lowTriplet.maxValue > crossingTriplet.maxValue){
			return lowTriplet;
		}
		else if(highTriplet.maxValue > lowTriplet.maxValue && highTriplet.maxValue > crossingTriplet.maxValue){
			return highTriplet;
		}
		else{
			return crossingTriplet;
		}
	}
	
	private static Triplet getCrossingSubArray(int [] array, int low, int high){
		Triplet crossingTriplet = new Triplet();
		int mid = low + (high - low)/2;
		int maxLeftValue = Integer.MIN_VALUE;
		int maxRightValue = Integer.MIN_VALUE;
		int currentValue = 0;
		for(int i = mid; i>=low; i--){
			currentValue = currentValue + array[i];
			if(currentValue > maxLeftValue){
				maxLeftValue = currentValue;
				crossingTriplet.maxLow = i;
			}
		}
		currentValue = 0;
		for(int j=mid+1; j<=high; j++){
			currentValue = currentValue + array[j];
			if(currentValue > maxRightValue){
				maxRightValue = currentValue;
				crossingTriplet.maxHigh = j;
			}
		}
		crossingTriplet.maxValue = maxLeftValue + maxRightValue;
		return crossingTriplet;
	}

}
