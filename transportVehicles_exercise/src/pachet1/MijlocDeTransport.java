package pachet1;

public class MijlocDeTransport
{
    private String culoare;
    private String producator;
    private int anProductie;
    private boolean functional;

    public MijlocDeTransport()
    {
        this.culoare="fara";
        this.producator="fara";
        this.anProductie=0;
        this.functional=false;
    }
    
    public MijlocDeTransport(String culoare,String producator,int anProductie,boolean functional)
    {       
        this.culoare=culoare;
        this.producator=producator;
        this.anProductie=anProductie;
        this.functional=functional;
    }
    
    public String get_culoare()
    {
        return this.culoare;
    }

    public String get_producator()
    {
        return this.producator;
    }

    public int get_anProductie()
    {
        return this.anProductie;
    }

    public boolean get_functional()
    {
        return this.functional;
    }

    public void set_culoare(String x)
    {
        this.culoare=x;
    }

    public void set_producator(String x)
    {
        this.producator=x;
    }

    public void set_anProductie(int x)
    {
        this.anProductie=x;
    }   
    
    public void set_functional(boolean x)
    {
        this.functional=x;
    }

    public void afisare()
    {
        System.out.println("Culoare: " + this.culoare + " Producator: " + this.producator + " An productie: " + this.anProductie + " Functionalitate: " + this.functional);
    }

}