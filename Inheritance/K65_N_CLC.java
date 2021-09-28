package Inheritance;

public class K65_N_CLC extends Student
{
	private int practise_mark;
	K65_N_CLC(String name, int age, double GPA, int practise_mark)
	{
		super(name, age, GPA);
		this.practise_mark = practise_mark;
	}
	int get_mark() {
		return practise_mark;
	}
}
