package pachet2;

import pachet1.MijlocDeTransport;

public class Tren extends MijlocDeTransport
{
    static int inaltime;
    int viteza;
    final int nrVagoane = 10;

    public Tren()
    {
        super();
        inaltime=0;
        this.viteza=0;
    }

    public Tren(String culoare,String producator,int anProducator,boolean functionalitate,int inaltimea,int viteza)
    {
        super(culoare,producator,anProducator,functionalitate);
        inaltime=inaltimea;
        this.viteza=viteza;
    }
    
    public void afisare()
    {
        // this.afisare_mijloc();
        System.out.println("Culoare: " + this.get_culoare() + " Producator: " + this.get_producator() + " An productie: " + this.get_anProductie() + " Functionalitate: " + this.get_functional() + " Tren -> Inaltime: " + inaltime + " Viteza: " + this.viteza + " Numare de vagoane: " + this.nrVagoane);
    }

    public static void set_inaltime(int x)
    {
        inaltime=x;
    }

    public void set_viteza(int x)
    {
        viteza=x;
    }

    public String toString()
    {  
        return "Tren " + " - " + this.get_culoare() + " -- " + this.get_producator();  
    } 

    public static void main(String[] args)
    {
        Tren a1 = new Tren("Rosu","Vasile",2012,true,20,10);
        Tren a2 = new Tren("Verde","Riky",2001,true,50,30);

        System.out.println("Trenul a1: ");
        System.out.println(inaltime);
        System.out.println(a1.viteza);
        System.out.println(" ");
        System.out.println("Trenul a2: ");
        System.out.println(inaltime);
        System.out.println(a2.viteza);
        
        a1.set_inaltime(12);
        a2.set_inaltime(33);

        System.out.println(" ");

        System.out.println("Trenul a1 (dupa schimbarea inaltimii): ");
        System.out.println(inaltime);
        System.out.println(a1.viteza);
        System.out.println(" ");
        System.out.println("Trenul a2 (dupa schimbarea inaltimii): ");
        System.out.println(inaltime);
        System.out.println(a2.viteza);
        
        // Cele doua trenuri au aceasi inaltime deoarece variabila atributul/variabila inaltime
        // este comuna celor doua trenuri

        a1.set_viteza(666);
        a2.set_viteza(555);

        System.out.println(" ");

        System.out.println("Trenul a1 (dupa schimbarea vitezei): ");
        System.out.println(inaltime);
        System.out.println(a1.viteza);
        System.out.println(" ");
        System.out.println("Trenul a2 (dupa schimbarea vitezei): ");
        System.out.println(inaltime);
        System.out.println(a2.viteza);

        System.out.println(" ");

        // Schimbarea vitezei este posibila la fiecxare tren idividual 
        // deoarece au variabila separata pentru viteza (nu este comuna)

        System.out.println("Aici am folosit metoda toString pentru a afisa trenurile a1 si a2.");

        System.out.println(a1.toString());
        System.out.println(a2.toString());
    }

    
}