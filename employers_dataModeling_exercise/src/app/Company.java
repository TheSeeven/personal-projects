package app;

public class Company {

	private String nume;
	private String location;
	private Departament[] departaments;

	public String getNume() {
		return this.nume;
	}

	public void setNume(String nume) {
		this.nume = nume;
	}

	public String getLocation() {
		return this.location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public Departament[] getDepartaments() {
		return this.departaments;
	}

	public void setDepartaments(Departament[] departaments) {
		this.departaments = departaments;
	}

	private String get_departaments()
	{
		StringBuffer rez = new StringBuffer();
		for(Departament i: this.departaments)
		{
			rez.append(i.toString()+"\n");
		}
		return rez.toString();


	}

	public String toString()
	{
		return "Company:" + this.nume + "\nLocation:"+this.location + "\nDepartaments:\n"+this.get_departaments();
	}

	public Company(String nume,String location, Departament[] departaments){
		this.nume=nume;
		this.location=location;
		this.departaments=departaments;
	}

}