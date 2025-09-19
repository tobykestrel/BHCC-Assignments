/*=======================================
| Toby Hansen, September 18 2025.       |
| Assignment 2, CSC-285-201.            |
| This program prints triangles with    |
| loops, and does simple variable math. |
=======================================*/

package edu.bhcc.entrypoint;

import java.util.Scanner;
import java.text.DecimalFormat;

public class TrianglePrinting {
	
	static Scanner in = new Scanner(System.in); 		// Global Scanner.
	
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*=======================================\n"
						+"| Toby Hansen, September 18 2025.       |\n"
						+"| Assignment 2, CSC-285-201.            |\n"
						+"| This program prints triangles with    |\n"
						+"| loops, and does simple variable math. |\n"
						+"=======================================*/\n\n");
	    
		// This section is a command-loop repeating the program until the user decides to quit.
		System.out.print("Enter command ('h' for list of supported commands): ");
		while(true) {
			switch (in.next().charAt(0)) {
				case 'm': doSimpleMath(); break;			// Do math with a given variable.
				case 'e': printEquilateralTriangle(); break;// Print an equilateral triangle.
				case 'r': printRightTriangle(); break; 		// Print a right triangle.
				case 'h': printHelpText(); break; 			// Print the help text.
				case 'q': System.exit(0);					// Quit the program.
			}
			System.out.print("Command: ");
		}
	}
	
	// This function takes an int input from the user and uses conditional logic to perform unique outputs.
	static public void doSimpleMath() {
		System.out.println("The Formula is ((x*15)-3+22)/4");
		System.out.print("Enter x: ");
		int x = in.nextInt();
		int newX = ((x*15)-3+22);
		int remX = newX % 4;
		newX = newX/4;
		System.out.println("New value of x after formula: " + newX);
		System.out.println("Remainder of x after division: " + remX);
		if (x > 5) { System.out.println("I am the King (newX > 5)");
		} else { System.out.println("I Lost (newX <= 5)"); }
		if (remX > 2) {
			newX += 10;
			System.out.println("Value after adding 10 (remX > 2): " + newX); // String.valueOf(newX)
		}
	}
	
	// This function uses for loops to print a right triangle of asterisks.
	static public void printRightTriangle() {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < (i*2)+1; j++) { System.out.print('*'); }
			System.out.println("");
		}
	}

	// This function uses for loops to print an equilateral triangle of asterisks.
	static public void printEquilateralTriangle() {
		for (int asterisks = 1, spaces = 3; asterisks <= 7; asterisks+=2, spaces--) {
			for (int i = spaces; i > 0; i--) { System.out.print(' '); }
			for (int i = asterisks; i > 0; i--) { System.out.print('*'); }
			System.out.println("");
		}
	}
	
	// This function prints the help text with the supported commands.
	static public void printHelpText() {
		System.out.print("Supported commands:\n"
				+ "     m    Do math with a given variable.\n"
				+ "     e    Print an equilateral triangle.\n"
				+ "     r    Print a right triangle.\n"
				+ "     h    Print this help text.\n"
				+ "     q    Quit the program.\n");
	}
}
