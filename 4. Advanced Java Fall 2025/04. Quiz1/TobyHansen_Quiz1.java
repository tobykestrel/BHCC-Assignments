/*=================================
| Toby Hansen, September 27 2025. |
| Quiz 1, CSC-285-201.            |
| This program is the first quiz. |
=================================*/

package edu.bhcc.entrypoint;

import java.util.Scanner;

public class Quiz1 {
	
	// This is the main function.
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*================================\n"
						+"| Toby Hansen, September 27 2025. |\n"
						+"| Quiz 1, CSC-285-201.            |\n"
						+"| This program is the first quiz. |\n"
						+"=================================*/\n\n");
		
		Q2(new int[]{23, 45, 26, 12, 3});
		Q3("Tanya, Jordan and Lily saved some money. Tanya saved 100 dollars, Jordan saved 250 and Lily 350 dollars. What is the total?");
	}
	
	// This function takes two integers and returns true 
	// if either is 15 or their sum or difference is 15.
	static public boolean Q1(int a, int b) {
		return a == 15 || b == 15 || a+b == 15 || a-b == 15 || b-a == 15;
	}
	
	// This function takes values in an integer array.
	static public void Q2(int[] array) {
		int[] arr = array;
		
		// Section 2.1: Calculate and print the average.
		double avg = 0;
		for (int i = 0; i < arr.length; i++) { avg += arr[i]; }
		avg = avg/arr.length;
		System.out.println("Array average: " + avg);
		
		// Section 2.2: Print values at index 2, 5, 7, and 0 in order.
		try { System.out.println("[2]: " + arr[2]); } catch (IndexOutOfBoundsException e) { System.out.println("Exception: Index 2 is out of bounds."); } 
		try { System.out.println("[5]: " + arr[5]); } catch (IndexOutOfBoundsException e) { System.out.println("Exception: Index 5 is out of bounds."); } 
		try { System.out.println("[7]: " + arr[7]); } catch (IndexOutOfBoundsException e) { System.out.println("Exception: Index 7 is out of bounds."); } 
		try { System.out.println("[0]: " + arr[0]); } catch (IndexOutOfBoundsException e) { System.out.println("Exception: Index 0 is out of bounds."); }
	}
	
	// This function calculates the sum of the numerical values from the string.
	static public void Q3(String s) {
		// This section gets the character value sum of the string.
		char[] charArr = s.toCharArray();
		int stringValue = 0;
		for (char c : charArr) { stringValue += c; }
		System.out.println("Sum of chars in string: " + stringValue);
		
		// This section gets the numerical sum of all ints in the string.
		Scanner in = new Scanner(s);
		int stringIntSum = 0;
		while (in.hasNext()) {
            if (in.hasNextInt()) {
                stringIntSum += in.nextInt();
            } else { in.next(); }
        }
        in.close();
		System.out.println("Sum of ints  in string: " + stringIntSum);
		
	}
}