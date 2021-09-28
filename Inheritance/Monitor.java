package Inheritance;

public class Monitor extends Student {
	private double bonus;
	public Monitor(String name, int age, double GPA, double bonus) {
		super(name, age, GPA);
		// TODO Auto-generated constructor stub
		this.bonus = bonus;
	}
	
	double get_GPA()
	{
		return super.get_GPA()+bonus;
	}
}
