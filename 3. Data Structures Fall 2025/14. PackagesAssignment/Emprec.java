// Toby Hansen Nov 12 2025
// Packages Assignment

package com.toby.pk1;

public class Emprec {
	public String name;
	public String job;
    public double hours;
	public double rate;
	
	public double calc_gross_pay() { return (hours*rate); }
	public String toString() { return name + " (" + job + ")"; }
}

