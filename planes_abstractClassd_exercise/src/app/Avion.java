package app;

public abstract class Avion
{
    private int putere;
    private String indicator_avion;
    static String[] poate_sa_faca = {"- ZBOARA","- DECOLEAZA","- ATERIZEAZA"};

    public String get_indicator_avion()
    {
        return this.indicator_avion;
    }

    public int get_putere()
    {
        return this.putere;
    }

    public void set_indicator_avion(String x)
    {
        indicator_avion=x;
    }

    public void set_putere(int x)
    {
        putere=x;
    }

    public void decoleaza()
    {
        System.out.println(this.toString() + " " + poate_sa_faca[1] );
    }

    public void zboara()
    {
        System.out.println(this.toString() + " " + poate_sa_faca[0]);
    }
    
    public void aterizeaza()
    {
        System.out.println(this.toString() + " " + poate_sa_faca[2]);
    }

}   