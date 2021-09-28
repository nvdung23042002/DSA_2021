package Inheritance;

public class Display {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		K65_N_CLC Dung = new K65_N_CLC("Nguyen Vinh Dung", 19, 3.36, 90);
		
		System.out.println(Dung.get_mark());
		System.out.println(Dung.get_name());
		System.out.println(Dung.get_age());
		System.out.println(Dung.get_GPA());
		Monitor VinhDung = new Monitor("Nguyen Vinh Dung",19,3.36,0.2);
		System.out.println(VinhDung.get_GPA());
	}

}
