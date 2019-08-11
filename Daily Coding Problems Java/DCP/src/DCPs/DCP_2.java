package DCPs;

import java.util.Arrays;


/**
 * 
 * Given an array of integers, return a new array such that each 
 * element at index i of the new array is the product of all the 
 * numbers in the original array except the one at i.
 * For example, if our input was [1, 2, 3, 4, 5], 
 * the expected output would be [120, 60, 40, 30, 24]. 
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
 * 
 * 
 * 
 * */
public class DCP_2 {

	public static void main(String args[]) {
		//print result using division
		if(args == null) {
			return;
		}

		System.out.println(divisionSolition(args[0]));
	}

	private static String divisionSolition(String list) {

		//add null check

		//get max value
		int max = calculateProduct(list);

		String newList =calculateProductList(max, list);


		return newList;
	}

	private static String calculateProductList(int max, String list) {
		String answer = "";

		if(list.indexOf(',') ==-1) {
			answer += Integer.toString(max / Integer.parseInt(list));
			return answer;
		}

		int currentCommaIndex = list.indexOf(',');

		int nextCommaIndex  = list.indexOf(',', currentCommaIndex+1);

		//calculate values for list
		answer += Integer.toString( max / Integer.parseInt(list.substring(0,currentCommaIndex)));

		while ( currentCommaIndex != -1 ) {
			if(nextCommaIndex ==-1) {
				answer += "," +Integer.toString(max / Integer.parseInt(list.substring(currentCommaIndex+1, list.length())));
				currentCommaIndex =-1;
			}

			else {
				answer += "," + Integer.toString(max / Integer.parseInt(list.substring(currentCommaIndex+1, nextCommaIndex))) ;
				currentCommaIndex = nextCommaIndex;
				nextCommaIndex = list.indexOf(',', currentCommaIndex+1);
			}

		}		return answer;
	}

	private static int calculateProduct(String list) {
		int max   = 0;

		if(list.indexOf(',') ==-1) {
			max = Integer.parseInt(list);
			return max;
		}

		int currentCommaIndex = list.indexOf(',');

		max = Integer.parseInt(list.substring(0,currentCommaIndex));

		int nextCommaIndex  = list.indexOf(',', currentCommaIndex+1);

		while ( currentCommaIndex != -1 ) {
			if(nextCommaIndex ==-1) {
				max *= Integer.parseInt(list.substring(currentCommaIndex+1, list.length()));
				currentCommaIndex =-1;
			}

			else {
				max *= Integer.parseInt(list.substring(currentCommaIndex+1, nextCommaIndex));
				currentCommaIndex = nextCommaIndex;
				nextCommaIndex = list.indexOf(',', currentCommaIndex+1);
			}
		}		return max;
	}
}
