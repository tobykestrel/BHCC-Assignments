// Toby Hansen Nov 12 2025
// Packages Assignment

import com.toby.pk1.Emprec;

// This class declares an object of type Emprec.
class Emp_Ex {
	public static void main(String args[]) {

		// Walter White
		Emprec employee1 = new Emprec();
		employee1.name = "Walter White";
		employee1.job = "Senior Lead Chemist";
		System.err.println(employee1.toString());

		// Jesse Pinkman
		Emprec employee2 = new Emprec();
		employee2.name = "Jesse Pinkman";
		employee2.job = "Distribution Manager";
		System.err.println(employee2.toString());
		
		// Gustavo Fring
		Emprec employee3 = new Emprec();
		employee3.name = "Gustavo Fring";
		employee3.job = "Chief Executive Officer";
		System.err.println(employee3.toString());
		
		// Mike Ehrmantraut
		Emprec employee4 = new Emprec();
		employee4.name = "Mike Ehrmantraut";
		employee4.job = "Head of Security";
		System.err.println(employee4.toString());
	}
}