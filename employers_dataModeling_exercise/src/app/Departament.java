package app;

public class Departament {

	private String nume;
	private Office[] offices;
	private Employee[] employees;

	public String getNume() {
		return this.nume;
	}

	public void setNume(String nume) {
		this.nume = nume;
	}

	public Office[] getOffices() {
		return this.offices;
	}

	public void setOffices(Office[] offices) {
		this.offices = offices;
	}

	public Employee[] getEmployees() {
		return this.employees;
	}

	public void setEmployees(Employee[] employees) {
		this.employees = employees;
	}

	public String get_offices()
	{
		StringBuffer x = new StringBuffer();
		for(Office i: this.offices)
		{
			x.append(i.toString());
		}
		return x.toString();
	}

	public String get_employees()
	{
		StringBuffer x = new StringBuffer();
		for(Employee i: this.employees)
		{
			x.append(i.toString()+"\n");
		}
		return x.toString();
	}

	public String toString()
	{
		return "Departament: " + this.nume + "\nOffices:\n" + this.get_offices() + "\nEmployees: \n" + this.get_employees();
	}

	public Departament(String nume,Office[] offices,Employee[] employees){
		this.nume=nume;
		this.offices=offices;
		this.employees=employees;
	}

}