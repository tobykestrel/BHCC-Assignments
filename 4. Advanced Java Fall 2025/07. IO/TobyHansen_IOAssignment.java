/*=======================================
| Toby Hansen, October 26 2025.         |
| IO Assignment, CSC-285-201.           |
| This program deals with input/output  |
| and performs operations on csv files. |
=======================================*/

package edu.bhcc.entrypoint;

import java.io.*;
import java.util.*;

public class IOAssignment {
	
	// This is the main function.
	public static void main(String[] args) {
		
		// The cwd and code banner is printed before the code is run.
		System.out.println(System.getProperty("user.dir")+"\n"
				+"/*=======================================\n"
				+"| Toby Hansen, October 26 2025.         |\n"
				+"| IO Assignment, CSC-285-201.           |\n"
				+"| This program deals with input/output  |\n"
				+"| and performs operations on csv files. |\n"
				+"=======================================*/\n");

		// This section reads in the student data.
		List<Student> students = new ArrayList<>();
		String fileName = "Student_Data.csv";
		try (BufferedReader in = new BufferedReader(new FileReader(fileName))) {
			String line = in.readLine(); // Skip the header line.
			while ((line = in.readLine()) != null) {
				String[] csv = line.split(",");
				students.add(new Student(csv[0], csv[1], csv[2], csv[3], csv[4]));
			}
		} catch (FileNotFoundException e) { System.out.println("Error: File not found \"" + fileName + "\""); 
		} catch (IOException e) { System.out.println("Error reading file: \"" + fileName + "\""); }
		
		// This section gets how many students are at Columbia.
		int atColumbia = 0;
        for (Student s : students) if (s.getUniversity().equals("Columbia")) atColumbia++;
		System.out.println("Students at Columbia (including duplicates): " + atColumbia);

		// This section gets how many students are in Michigan.
		int inMichigan = 0;
        for (Student s : students) if (s.getState().equals("Michigan")) inMichigan++;
		System.out.println("Students in Michigan (including duplicates): " + inMichigan);

		// This section gets how unique states are present.
		Set<String> uniqueStates = new HashSet<>();
        for (Student s : students) uniqueStates.add(s.getState());
		System.out.println("Unique States: " + uniqueStates.size());

		// This section gets how unique states are present.
		Set<String> uniqueStudents = new HashSet<>();
        for (Student s : students) { uniqueStudents.add(s.getName()); }
		System.out.println("Unique Students: " + uniqueStudents.size());

		// This section gets the student who lives at 12 State Street.
        for (Student s : students) { if (s.getAddress().equals("12 State Street")) { 
        	System.out.println("Resident of 12 State St: " + s.getName()); break; 
        }}
	}
}


// POJO class for students.
class Student {
	private String name;
	private String state;
	private String zipcode;
	private String university;
	private String address;

	public Student(String n, String s, String z, String u, String a) {
	     this.name = n;
	     this.state = s;
	     this.zipcode = z;
	     this.university = u;
	     this.address = a;
	 }
	
	 public String getName() { return this.name; }
	 public String getState() { return this.state; }
	 public String getZipcode() { return this.zipcode; }
	 public String getUniversity() { return this.university; }
	 public String getAddress() { return this.address; }
}