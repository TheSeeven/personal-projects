package pachet2;

import pachet1.MijlocDeTransport;

public class Troleibuz extends MijlocDeTransport
{
    private String sofer;
    private int capacitate_persoane;
    
    public Troleibuz(String culoare,String producator,int anProductie,boolean functional,String sofer,int capacitate_persoane)
    {
        super(culoare,producator,anProductie,functional);
        this.sofer=sofer;
        this.capacitate_persoane=capacitate_persoane;
    }

    public void afisare()
    {
        System.out.println("Culoare: " + this.get_culoare() + " Producator: " + this.get_producator() + " An productie: " + this.get_anProductie() + " Functionalitate: " + this.get_functional() + " Troleibuz -> Sofer: " + this.sofer + " Capacitate de persoane: " + this.capacitate_persoane);
    }

    public static int get_capacitate(Troleibuz x)
    {
        return x.capacitate_persoane;
    }
}