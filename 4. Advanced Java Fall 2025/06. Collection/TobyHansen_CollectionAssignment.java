/*=====================================
| Toby Hansen, October 18 2025.       |
| Collection Assignment, CSC-285-201. |
| This program builds lists of cars.  |
=====================================*/

package edu.bhcc.entrypoint;

import java.util.*;

public class CollectionAssignment {

	// Global Scanner.
	static Scanner in = new Scanner(System.in);	
    static CarBuilder builder = new CarBuilder();
	
	// This is the main function.
	public static void main(String[] args) {
		
		// This code banner is printed before the code is run.
		System.out.print("/*=====================================\n"
						+"| Toby Hansen, October 18 2025.       |\n"
						+"| Collection Assignment, CSC-285-201. |\n"
						+"| This program builds lists of cars.  |\n"
						+"=====================================*/\n");
		
		// This section is a command-loop repeating the program until the user decides to quit.
		System.out.print("Enter command ('d' for default run, 'h' for help menu): ");
		while(true) {
			switch (in.next().charAt(0)) {
				case 'a': createCar(); break;						// Adds a car to the builder.
				case 'n': builder.printCarsNaturalOrder(); break; 	// Print the cars by natural.
				case 'p': builder.printCarsByPrice(); break; 		// Print the cars by cost.
				case 'm': builder.printItemPriceMap(); break;		// Print the item price map.
				case 'd': printDefault(); break; 		// Print the default set up.
				case 'c': builder.clearList(); break; 	// Clear the car builder list.
				case 'h': printHelpText(); break; 		// Print the help text.
				case 'q': System.out.println("Exiting program..."); in.close(); return;	// Quit the program.
			}
			System.out.print("\nCommand: ");
		}
	}
	
	// This function prints the default set up.
	static public void printDefault() {
		
		// This section sets the car list to just the default three cars.
		builder.clearList();
		builder.addCar(new Car("KTN123", "Tesla", "Model S", "Red", "Turbo", "S-Steel", "Sedan-Sport"));
		builder.addCar(new Car("XRE441", "GM", "Imapla", "White", "TurboSwift", "Wheel-X", "Sedan-Coupe"));
		builder.addCar(new Car("WWR839", "Nissan", "Rouge", "Gray", "Turbo", "S-Steel", "SUV-Shape"));
		
		// This section displays all the information from the cars in the CarBuilder.
        builder.printCarsNaturalOrder();
        builder.printCarsByPrice();
	}
	
	// This function takes input from the user to add a new car to the builder.
	static public void createCar() {
		
		// This section gets the VIN.
		System.out.print("Enter VIN: ");
		String vin = in.next();
		
		// This section gets the name.
		System.out.print("Enter name: ");
		String name = in.next();
		
		// This section gets the model.
		System.out.print("Enter model: ");
		String model = in.next();
		
		// This section gets the color.
		System.out.print("Enter color: ");
		String color = in.next();
		
		// This section gets the engine.
		String engine = "";
		while(engine.isEmpty()) {
			System.out.print("Enter engine ('t' for Turbo, 's' for TurboSwift): ");
			switch (in.next().charAt(0)) {
				case 't': engine = "Turbo"; break;
				case 's': engine = "TurboSwift"; break;
			}
		}
		
		// This section gets the wheels.
		String wheels = "";
		while(wheels.isEmpty()) {
			System.out.print("Enter wheels ('s' for S-Steel, 'x' for Wheel-X): ");
			switch (in.next().charAt(0)) {
				case 's': wheels = "S-Steel"; break;
				case 'x': wheels = "Wheel-X"; break;
			}
		}
		
		// This section gets the body.
		String body = "";
		while(body.isEmpty()) {
			System.out.print("Enter body ('v' for SUV-Shape, 's' for Sedan-Sport, 'c' for Sedan-Coupe): ");
			switch (in.next().charAt(0)) {
				case 'v': body = "SUV-Shape"; break;
				case 's': body = "Sedan-Sport"; break;
				case 'c': body = "Sedan-Coupe"; break;
			}
		}
		
		// This section adds the car to the list.
		builder.addCar(new Car(vin, name, model, color, engine, wheels, body));
	}
	
	// This function prints the help text with the supported commands.
	static public void printHelpText() {
		System.out.print("Supported commands:\n"
				+ "     a    Add a car to the builder.\n"
				+ "     n    Print the cars by natural order.\n"
				+ "     p    Print the cars by total cost.\n"
				+ "     m    Print the map of item prices.\n"
				+ "     d    Print the default set up.\n"
				+ "     c    Clear the car builder list.\n"
				+ "     h    Print this help text.\n"
				+ "     q    Quit the program.\n");
	}
}

class CarBuilder {
    private List<Car> carList;
    private Map<String, Double> itemPriceMap;

    public CarBuilder() {
        carList = new ArrayList<>();
        itemPriceMap = new HashMap<>();
        itemPriceMap.put("Turbo", 15000.00); // Engine
        itemPriceMap.put("TurboSwift", 19000.00); // Engine
        itemPriceMap.put("Wheel-X", 90.00); // Each wheel
        itemPriceMap.put("S-Steel", 130.00); // Each wheel
        itemPriceMap.put("SUV-Shape", 10000.00); // Body
        itemPriceMap.put("Sedan-Sport", 15000.00); // Body
        itemPriceMap.put("Sedan-Coupe", 13000.00); // Body
    }
    
    public void clearList() { this.carList.clear(); }

    public void addCar(Car car) {
        double engineCost = itemPriceMap.getOrDefault(car.getEngine(), 0.0);
        double bodyCost = itemPriceMap.getOrDefault(car.getBody(), 0.0);
        double wheelCost = itemPriceMap.getOrDefault(car.getWheels(), 0.0) * 4; // 4 wheels per car
        double cost = engineCost + bodyCost + wheelCost;
        car.setTotalPrice(cost);
        carList.add(car);
    }

    public void printCarsNaturalOrder() {
        System.out.println("\nCars in Natural Order:");
        Collections.sort(carList);
        for (Car car : carList) { System.out.println(car); }
    }

    public void printCarsByPrice() {
        System.out.println("\nCars Sorted by Price:");
        carList.sort(Comparator.comparingDouble(Car::getTotalPrice));
        for (Car car : carList) { System.out.println(car); }
    }

    public void printItemPriceMap() {
        System.out.println("\nItem Price Map:");
        itemPriceMap.forEach((k, v) -> System.out.println(k + ": $" + v));
    }
}

class Car implements Comparable<Car> {
    private String vin;
    private String name;
    private String model;
    private String color;
    private String engine;
    private String wheels;
    private String body;
    private double totalPrice;

    // Constructor
    public Car(String vin, String name, String model, String color, String engine, String wheels, String body) {
        this.vin = vin;
        this.name = name;
        this.model = model;
        this.color = color;
        this.engine = engine;
        this.wheels = wheels;
        this.body = body;
    }

    // Getters
    public String getVin() { return this.vin; }
    public String getName() { return this.name; }
    public String getModel() { return this.model; }
    public String getColor() { return this.color; }
    public String getEngine() { return this.engine; }
    public String getWheels() { return this.wheels; }
    public String getBody() { return this.body; }
    public double getTotalPrice() { return this.totalPrice; }

    // Setters
    public void setVin(String v) { this.vin = v; }
    public void setName(String n) { this.name = n; }
    public void setModel(String m) { this.model = m; }
    public void setColor(String c) { this.color = c; }
    public void setEngine(String e) { this.engine = e; }
    public void setWheels(String w) { this.wheels = w; }
    public void setBody(String b) { this.body = b; }
    public void setTotalPrice(double tp) { this.totalPrice = tp; }
    

    // Overrides
    @Override public int compareTo(Car other) { return this.vin.compareTo(other.vin); }
    @Override  public String toString() {
    	return String.format(
    			"%-6s | %-8s %-8s %-8s | Engine: %-12s | Wheels: %-12s | Body: %-12s | Total: $%.2f",
    			vin, name, model, color, engine, wheels, body, totalPrice);
    }
}