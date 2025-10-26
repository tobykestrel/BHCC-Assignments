/*======================================
| Toby Hansen, September 6 2025.       |
| Assignment 1, CSC-285-201.           |
| This program solves an equation with |
| a formula and converts temperatures. |
======================================*/

package edu.bhcc.entrypoint;

import java.util.Scanner;
import java.text.DecimalFormat;

public class EquationAndTempConversion {
	
	static Scanner in = new Scanner(System.in); 		// Global Scanner.
	static DecimalFormat df = new DecimalFormat("#.##");// Global Decimal Formatter.
	
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*======================================\n"
						+"| Toby Hansen, September 6 2025.       |\n"
						+"| Assignment 1, CSC-285-201.           |\n"
						+"| This program solves an equation with |\n"
						+"| a formula and converts temperatures. |\n"
						+"======================================*/\n\n");
	    
		// This section is a command-loop repeating the program until the user decides to quit.
		System.out.print("Enter command ('h' for list of supported commands): ");
		while(true) {
			switch (in.next().charAt(0)) {
				case 'e': equationSolverWrapper(); break;	// Solve the equation.
				case 'f': fToCWrapper(); break; 			// Convert Fahrenheit to Celsius.
				case 'c': cToFWrapper(); break; 			// Convert Celsius to Fahrenheit.
				case 'h': printHelpText(); break; 			// Print the help text.
				case 'q': System.exit(0);					// Quit the program.
			}
			System.out.print("Command: ");
		}
	}
	
	// Formula functions that take variable parameters and return the solution.
	static private double equationSolver(double x1, double x2, double y1, double y2) { return ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1)); }
	static private double fToC(double f) { return (5 * (f - 32)) / 9.0; }
	static private double cToF(double c) { return ((9 * c) / 5.0) + 32; }
	
	// This function takes input from the user for formula variables and outputs the solution.
	static public void equationSolverWrapper() {
		System.out.println("The Formula is (x2-x1)^2 + (y2-y1)^2");
		System.out.print("Enter x1: ");
		double x1 = in.nextInt();
		System.out.print("Enter x2: ");
		double x2 = in.nextInt();
		System.out.print("Enter y1: ");
		double y1 = in.nextInt();
		System.out.print("Enter y2: ");
		double y2 = in.nextInt();
		System.out.println("Equation Solver: " + String.valueOf(df.format(equationSolver(x1, x2, y1, y2))));
	}
	
	// This function takes fahrenheit input from the user and outputs the temperature in celsius.
	static public void fToCWrapper() {
		System.out.print("Enter F: ");
		double f = in.nextInt();
		System.out.println(df.format(f) + "F = " + String.valueOf(df.format(fToC(f))) + "C");
	}

	// This function takes celsius input from the user and outputs the temperature in fahrenheit.
	static public void cToFWrapper() {
		System.out.print("Enter C: ");
		double c = in.nextInt();
		System.out.println(df.format(c) + "C = " + String.valueOf(df.format(cToF(c))) + "F");
	}
	
	// This function prints the help text with the supported commands.
	static public void printHelpText() {
		System.out.print("Supported commands:\n"
				+ "     e    Solve the equation with values.\n"
				+ "     f    Convert fahrenheit to celsius.\n"
				+ "     c    Convert celsius to fahrenheit.\n"
				+ "     h    Print the help text.\n"
				+ "     q    Quit the program.\n");
	}
}
