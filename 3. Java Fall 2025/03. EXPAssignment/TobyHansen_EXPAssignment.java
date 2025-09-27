/*====================================
| Toby Hansen, September 26 2025.    |
| EXP Assignment, CSC-285-201.       |
| This program handles student data. |
====================================*/

package edu.bhcc.entrypoint;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Student {
    private String name;
    private String citizenship;

    // Constructor
    public Student(String name, String citizenship) {
        this.name = name;
        this.citizenship = citizenship;
    }

    // Getters
    public String getName() { return name; }
    public String getCitizenship() { return citizenship; }
}

public class EXPAssignment {
	
	static Scanner in = new Scanner(System.in);	// Global Scanner.
	static List<Student> students = new ArrayList<>(); // Global list of students
	
	// This is the main function.
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*====================================\n"
						+"| Toby Hansen, September 26 2025.    |\n"
						+"| EXP Assignment, CSC-285-201.       |\n"
						+"| This program handles student data. |\n"
						+"====================================*/\n\n");
	    
		// This section is a command-loop repeating the program until the user decides to quit.
		System.out.print("Enter command ('h' for list of supported commands): ");
		while(true) {
			switch (in.next().charAt(0)) {
				case 'd': runDefault(); break;			// Run the default values for the program.
				case 'a': addStudent(); break;			// Add a student to the list.
				case 's': printStudentAtIndex(); break;	// Print a student at a specified index.
				case 'p': printStudents(); break; 		// Print all the students in the list.
				case 'h': printHelpText(); break; 		// Print the help text.
				case 'r': students.clear(); break; 		// Reset (clear the list of students).
				case 'q': System.exit(0);				// Quit the program.
			}
			System.out.print("Command: ");
		}
	}
	
	// This function adds a student to the global student array.
	static public void runDefault() {
		// This section creates student instances using the constructor with fields.
		students.clear();
		System.out.println("Creating five student instances.");
		students.add(new Student("Adam", "United Kingdom"));
		students.add(new Student("John", "Germany"));
		students.add(new Student(null, "Italy"));
		students.add(new Student("James", "Spain"));
		students.add(new Student(null, "Germany"));
		
		// This section gets a list of all the student names and stores them in a string array. 
		// If a name is null, a Null Pointer Exception is caught.
		System.out.println("Creating a string array of all the student names.");
		String[] studentNames = new String[students.size()];
        for (int i = 0; i < students.size(); i++) {
            try {
                if (students.get(i).getName() == null) {
                    throw new NullPointerException("Student name cannot be null at index " + i + ".");
                }
                studentNames[i] = students.get(i).getName();
            } catch (NullPointerException e) {
                System.out.println("Exception: " + e.getMessage());
                studentNames[i] = "Unknown";
            }
        }
        
        // This section prints all the names.
        System.out.println("Printing all student names:");
        for (int i = 0; i < studentNames.length; i++) {
            System.out.println(i + ". " + studentNames[i]);
        }
	}
	
	// This function adds a student to the global student array.
	static public void addStudent() {
		System.out.print("Enter name: ");
		String name = in.next();
		System.out.print("Enter citizenship: ");
		String citizenship = in.next();
		students.add(new Student(name, citizenship));
	}

	// This function prints a student at a specified index.
	static public void printStudents() {
		if (students.size() == 0) System.out.println("No students are currently in the list.");
        for (int i = 0; i < students.size(); i++) {
            System.out.println(i + ". " + students.get(i).getName() + ", " + students.get(i).getCitizenship());
        }
	}

	// This function prints all the current students.
	static public void printStudentAtIndex() {
		System.out.print("Enter index: ");
		int i = in.nextInt();
        try {
            if (students.get(i).getName() == null) {
                throw new NullPointerException("Student at index " + i + " has no recorded name.");
            }
            System.out.println("Name of student " + i + ": " + students.get(i).getName());
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Exception: Index " + i + " is out of bounds of the array.");
        } catch (NullPointerException e) {
            System.out.println("Exception: " + e.getMessage());
        }
	}
	
	// This function prints the help text with the supported commands.
	static public void printHelpText() {
		System.out.print("Supported commands:\n"
				+ "     d    Run the default set up.\n"
				+ "     a    Add a student to the list.\n"
				+ "     s    Print the student name at a specified index.\n"
				+ "     p    Print the list of students.\n"
				+ "     h    Print this help text.\n"
				+ "     r    Reset (clear the list of students).\n"
				+ "     q    Quit the program.\n");
	}
}
