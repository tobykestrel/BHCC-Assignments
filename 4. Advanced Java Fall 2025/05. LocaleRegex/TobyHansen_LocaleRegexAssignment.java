/*============================================
| Toby Hansen, October 17 2025.              |
| Locale Regex Assignment, CSC-285-201.      |
| This program does locale pattern matching. |
============================================*/



import java.util.Scanner;
import java.util.regex.Pattern;
import java.text.DateFormat;
import java.util.Date;
import java.util.Locale;

public class Quiz1 {

	// Global Scanner.
	static Scanner in = new Scanner(System.in);	
	
	// This is the main function.
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*============================================\n"
						+"| Toby Hansen, October 17 2025.              |\n"
						+"| Locale Regex Assignment, CSC-285-201.      |\n"
						+"| This program does locale pattern matching. |\n"
						+"============================================*/\n\n");
		
		// This section is a command-loop repeating the program until the user decides to quit.
		System.out.print("Enter command ('h' for list of supported commands): ");
		while(true) {
			switch (in.next().charAt(0)) {
				case 'd': printDates(); break;			// Prints several unique locales' dates.
				case 'e': checkEmailValidity(); break; 	// Check an email's validity.
				case 'h': printHelpText(); break; 		// Print the help text.
				case 'q': in.close(); System.exit(0);	// Quit the program.
			}
			System.out.print("\nCommand: ");
		}
	}
	
	// This function prints several unique locales' dates.
	static public void printDates() {
		Date today = new Date();
		
		Locale china = new Locale("zh", "CN");
		Locale egypt = new Locale("ar", "EG");
		Locale germany = new Locale("de", "DE");
		Locale india = new Locale("en", "IN");
		Locale canada = new Locale("en", "CA");
		Locale japan = new Locale("ja", "JP");

		DateFormat nfChina = DateFormat.getDateInstance(DateFormat.DEFAULT, china);
		DateFormat nfEgypt = DateFormat.getDateInstance(DateFormat.DEFAULT, egypt);
		DateFormat nfGermany = DateFormat.getDateInstance(DateFormat.DEFAULT, germany);
		DateFormat nfIndia = DateFormat.getDateInstance(DateFormat.DEFAULT, india);
		DateFormat nfCanada = DateFormat.getDateInstance(DateFormat.DEFAULT, canada);
		DateFormat nfJapan = DateFormat.getDateInstance(DateFormat.DEFAULT, japan);
		
		System.out.println("Today's date in China's Locale  : " + nfChina.format(today));
		System.out.println("Today's date in Egypt's Locale  : " + nfEgypt.format(today));
		System.out.println("Today's date in Germany's Locale: " + nfGermany.format(today));
		System.out.println("Today's date in India's Locale  : " + nfIndia.format(today));
		System.out.println("Today's date in Canada's Locale : " + nfCanada.format(today));
		System.out.println("Today's date in Japan's Locale  : " + nfJapan.format(today));
	}
	
	// This function takes an email as input and returns a boolean whether it is valid or not.
	static public void checkEmailValidity() {
		System.out.print("Enter an email address: ");
		String email = in.next().trim();
		String emailRegex = "^[A-Za-z0-9._]+@[A-Za-z0-9]+\\.[A-Za-z]{2,}$";
		if (Pattern.matches(emailRegex, email)) {
            System.out.println("The email address is valid.");
        } else {
            System.out.println("The email address is invalid.");
        }
	}
	
	// This function prints the help text with the supported commands.
	static public void printHelpText() {
		System.out.print("Supported commands:\n"
				+ "     d    Prints several unique locales' dates.\n"
				+ "     e    Check an email's validity.\n"
				+ "     h    Print this help text.\n"
				+ "     q    Quit the program.\n");
	}
}
