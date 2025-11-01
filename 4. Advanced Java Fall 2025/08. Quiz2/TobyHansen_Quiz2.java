/*=======================================
| Toby Hansen, November 1 2025.         |
| Quiz 2, CSC-285-201.           		|
| This program deals with input/output  |
| and performs operations on csv files. |
=======================================*/

package edu.bhcc.entrypoint;

import java.io.*;
import java.util.*;

public class Quiz2 {
	
	// This is the main function.
	public static void main(String[] args) {
		
		// The cwd and code banner is printed before the code is run.
		System.out.println(System.getProperty("user.dir")+"\n"
				+"/*=======================================\n"
				+"| Toby Hansen, November 1 2025.         |\n"
				+"| Quiz 2, CSC-285-201.           		  |\n"
				+"| This program deals with input/output  |\n"
				+"| and performs operations on csv files. |\n"
				+"=======================================*/\n");

		// This section reads in the student data.
		Set<Student> students = new HashSet<>();
		int totalRecords = 0;
		String fileName = "StudentData.csv";
		try (BufferedReader in = new BufferedReader(new FileReader(fileName))) {
			String line = in.readLine(); // Skip the header line.
			while ((line = in.readLine()) != null) {
				String[] csv = line.split(",");
				students.add(new Student(csv[0], csv[1], csv[2], Integer.parseInt(csv[3])));
				totalRecords++;
			}
		} catch (FileNotFoundException e) { System.out.println("Error: File not found \"" + fileName + "\""); 
		} catch (IOException e) { System.out.println("Error reading file: \"" + fileName + "\""); }
		
		// This section outputs the total number of records and unique students.
		System.out.println("Out of " + totalRecords + " total records, only " + students.size() + " are unique students.\n");
		
		// This section gets all the students enrolled in the java course, and their total average score.
		int totalJavaScore = 0;
		int totalJavaStudents = 0;
		System.out.println("All students enrolled in the Java course:");
        for (Student s : students) {
        	if (s.getCourse().equals("Java")) System.out.println(s.toString());
        	totalJavaScore += s.getScore();
        	totalJavaStudents++;
        }
		System.out.println("Average score in the Java course: " + (totalJavaScore/totalJavaStudents) +"\n\n");

		// This section gets the student with the highest score overall.
		System.out.println("Highest scoring student:");
		ArrayList<Student> studentsArray = new ArrayList<>(students);
		Student highest = studentsArray.get(0);
        for (Student s : students) if (s.getScore() > highest.getScore()) highest = s; 
        System.out.println(highest.toString());
        
		// This section gets how many students are enrolled in each course.
		System.out.println("\n\nHow many students are enrolled in the each course:");
        HashMap<String, Integer> courseCount = new HashMap<>();
        for (Student s : students) {
            String c = s.getCourse();
            courseCount.put(c, courseCount.getOrDefault(c, 0) + 1); // Increment from 0.
        }
        for (String c : courseCount.keySet()) {
            System.out.println(c + ": " + courseCount.get(c));
        }
	}
}


// POJO class for students.
class Student {
	private String id;
	private String name;
	private String course;
	private int score;

	public Student(String i, String n, String c, int s) {
		this.id = i;
	    this.name = n;
	    this.course = c;
	    this.score = s;
	}

	public String getID() { return this.id; }
	public String getName() { return this.name; }
	public String getCourse() { return this.course; }
	public int getScore() { return this.score; }

	public void setID(String i) { this.id = i; }
	public void setName(String n) { this.name = n; }
	public void setCourse(String c) { this.course = c; }
	public void setScore(int s) { this.score = s; }
	 
	@Override
	public String toString() {
		return String.format("%-3s %-14s %-7s %d", id, name, course, score);
	}
	 
	@Override
	public boolean equals(Object o) {
	    if (this == o) return true;
	    if (!(o instanceof Student)) return false;
	    Student s = (Student) o;
	    return Objects.equals(this.name, s.name);
	}

	@Override
	public int hashCode() {
	    return Objects.hash(this.name);
	}
	 
}