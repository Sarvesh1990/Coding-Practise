import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class TimeInWords {

    public static void main(String[] args) {
    	final String[] numNames = {
    	    "",
    	    "one",
    	    "two",
    	    "three",
    	    "four",
    	    "five",
    	    "six",
    	    "seven",
    	    "eight",
    	    "nine",
    	    "ten",
    	    "eleven",
    	    "twelve",
    	    "thirteen",
    	    "fourteen",
    	    "fifteen",
    	    "sixteen",
    	    "seventeen",
    	    "eighteen",
    	    "nineteen"
    	};
    	final String[] tensNames = {
    	    "",
    	    "ten",
    	    "twenty",
    	    "thirty",
    	    "forty",
    	    "fifty",
    	    "sixty",
    	    "seventy",
    	    "eighty",
    	    "ninety"
    	  };

        Scanner in = new Scanner(System.in);
        int hour = in.nextInt();
        in = new Scanner(System.in);
        int minute = in.nextInt();
        if(minute == 00){
        	System.out.println(numNames[hour] + " o' clock");
        }
        else if(minute == 30){
        	System.out.println("half past " + numNames[hour]);
        }
    }
}
