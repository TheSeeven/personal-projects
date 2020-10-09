package app;

public class Employee {

	private String nume;
	private boolean isManager;

	public String getNume() {
		return this.nume;
	}

	public void setNume(String nume) {
		this.nume = nume;
	}

	public boolean isIsManager() {
		return this.isManager;
	}

	public void setIsManager(boolean isManager) {
		this.isManager = isManager;
	}

	public String toString()
	{
		String manager;
		if(this.isManager==true)
		{
			manager = "Manager";
		}
		else
		{
			manager = "Emmployee";
		}

		return "Nume: " + this.nume + " " + manager;
	}

	public Employee(String nume, boolean isManager){
		this.nume=nume;
		this.isManager=isManager;
	}

}