import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Fractions {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int A[] = new int[N];
        for(int A_i=0; A_i < N; A_i++){
            A[A_i] = in.nextInt();
        }
        //Find minimum from A
        int min = 2000;
        for(int i= 0; i<N; i++){
        	if(A[i] < min){
        		min = A[i];
        	}
        }
        int floorValue = (int) Math.floor(min/2);
        int sum = 0;
        for(int j=0; j<N; j++){
        	System.out.println(Math.floor(A[j]/(floorValue+1)) + 1);
        	sum = sum + (int) Math.floor(A[j]/(floorValue+1)) + 1;
        }
        System.out.println(sum);
        // your code goes here
    }
}
