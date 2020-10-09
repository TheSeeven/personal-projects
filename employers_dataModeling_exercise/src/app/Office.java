package app;

public class Office {

	private int nume;
	private boolean isHeadquarter;

	public int getNume() {
		return this.nume;
	}

	public void setNume(int nume) {
		this.nume = nume;
	}

	public boolean isIsHeadquarter() {
		return this.isHeadquarter;
	}

	public void setIsHeadquarter(boolean isHeadquarter) {
		this.isHeadquarter = isHeadquarter;
	}

	public String toString()
	{
		String headq;
		if(this.isHeadquarter == true)
		{
			headq = "Headquarter";
		}
		else
		{
			headq = "";
		}
		return "Office: " +  Integer.toString(this.nume) + " " + headq + "\n";
	}

	public Office(int nume,boolean isHeadquarter){
		this.nume=nume;
		this.isHeadquarter=isHeadquarter;
	}

}