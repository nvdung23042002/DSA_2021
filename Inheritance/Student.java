package Inheritance;

public class Student extends Person
{
	public Student(String name, int age, double GPA) {
		super(name, age);
		// TODO Auto-generated constructor stub
		this.GPA = GPA;
	}
	private double GPA;	
	double get_GPA()
	{
		return GPA;
	}
}
