import java.util.*;

public class Pairs {
    static int pairs(int[] a,int k) {
      /* Complete this function */
    	Map<Integer, Integer> myMap = new HashMap<Integer, Integer>();
    	for(int i=0; i< a.length; i++){
    		if(null != myMap.get(a[i])){
    			myMap.put(a[i], myMap.get(a[i])+1);
    		}
    		else{
    			myMap.put(a[i], 1);
    		}
    	}
    	int numPairs = 0;
    	for(int j=0; j<a.length; j++){
    		if(null != myMap.get(a[j]+k)){
    			numPairs = numPairs + myMap.get(a[j]+k);
    		}
    	}
        return numPairs;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;
        
        String n = in.nextLine();
        String[] n_split = n.split(" ");
        
        int _a_size = Integer.parseInt(n_split[0]);
        int _k = Integer.parseInt(n_split[1]);
        
        int[] _a = new int[_a_size];
        int _a_item;
        String next = in.nextLine();
        String[] next_split = next.split(" ");
        
        for(int _a_i = 0; _a_i < _a_size; _a_i++) {
            _a_item = Integer.parseInt(next_split[_a_i]);
            _a[_a_i] = _a_item;
        }
        
        res = pairs(_a,_k);
        System.out.println(res);
    }
}
