package app;

import java.util.Arrays;

public class Client
{
    private String nume;
    private String adresa;
    private ContBancar[] conturi = new ContBancar[5];

    public Client(){}

    public Client(String x,String y,ContBancar[] z)
    {
        nume=x;
        adresa=y;
        conturi=z;
    }

    public void set_nume(String x)
    {nume=x;}

    public void set_adresa(String x)
    {adresa=x;}

    public void set_conturi(ContBancar[] x)
    {conturi=x;}

    public String get_nume()
    {return nume;}

    public String get_adresa()
    {return adresa;}

    public ContBancar[] get_conturi()
    {return conturi;}

    public String toString(String x)
    {
        return nume + " " + adresa + " " + Arrays.toString(conturi); 
    }
    
}