package Inheritance;

public class Person {
	 private String name;
	 private int age;
	 
	 private Person() {}
	 
	 public Person(String name, int age)
	 {
		 this.age = age;
		 this.name = name;
	 }
	 
	 void set_age(int age)
	 {
		 this.age = age;
	 }
	 int get_age()
	 {
		 return age;
	 }
	 void set_name(String name)
	 {
		 this.name = name;
	 }
	 String get_name()
	 {
		 return name;
	 }
}
