package app;

import java.util.Arrays;

public class Banca
{
    private Client[] Clienti;
    private String cod;

    public Banca(){}

    public Banca(Client[] Clienti,String cod)
    {
        this.Clienti=Clienti;
        this.cod=cod;
    }
    
    public Client[] get_Clienti() 
    {
        return Clienti;
    }
    
    public String get_Cod() 
    {
        return cod;
    }
    
    public void set_Clienti(Client[] clienti) 
    {
        Clienti = clienti;
    }
    
    public void set_Cod(String cod) 
    {
        this.cod = cod;
    }

    public String toString()
    {
        return "Client: " + Arrays.toString(this.Clienti) + " " + cod;
    }

}