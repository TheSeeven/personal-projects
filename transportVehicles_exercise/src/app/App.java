package app;
import pachet1.*;
import pachet2.*;
import pachet3.*;

public class App {
    public static void main(String[] args)
    {
        MijlocDeTransport[] sir_mijloace = new MijlocDeTransport[6];
        int nr_trenuri_functionale = 0;
        int nr_troleibuze_functionale = 0;
        int nr_trenuri = 0;
        int nr_troleibuze = 0;


        sir_mijloace[0] = new MijlocDeTransport("negru","ion",2016,true);
        sir_mijloace[1] = new Tren("purpuriu","alex",2030,true,20,30);
        sir_mijloace[2] = new Troleibuz("negru","milean",2016,true,"marcelino",25);
        sir_mijloace[3] = new MijlocDeTransport("gri","benino",1999,false);
        sir_mijloace[4] = new Troleibuz("orange","bartea",2015,false,"belodedici",30);
        sir_mijloace[5] = new Tren("lila","marcel",2005,false,666,555);

        for(int i=0;i<sir_mijloace.length;i++)
        {
            sir_mijloace[i].afisare();
            System.out.println(" ");
        }

        for(int i=0;i<sir_mijloace.length;i++)
        {
            if(sir_mijloace[i] instanceof Troleibuz && sir_mijloace[i].get_functional())
            {
                nr_troleibuze_functionale++;
            }
            else if(sir_mijloace[i] instanceof Tren && sir_mijloace[i].get_functional())
            {
                nr_trenuri_functionale++;
            }
        }

        int capacitate=0;
        int index_troleibuz=0;

        for(int i=0;i<sir_mijloace.length;i++)
        {
            if(sir_mijloace[i] instanceof Troleibuz)
            {
                if(Troleibuz.get_capacitate((Troleibuz)sir_mijloace[i]) > capacitate)
                {
                    capacitate=Troleibuz.get_capacitate((Troleibuz)sir_mijloace[i]);
                    index_troleibuz=i;
                }
            }
        }

        


        System.out.println("Numarul de trenuri functionale este: " + nr_trenuri_functionale);
        System.out.println("Numarul de troleibuze functionale este: " + nr_troleibuze_functionale);


        System.out.println(" ");
        System.out.println("Troleibuzul cu cea mai mare capacitate este: " + capacitate);
        sir_mijloace[index_troleibuz].afisare();
        System.out.println(" ");

        for(int i=0;i<sir_mijloace.length;i++)
        {
            if(sir_mijloace[i] instanceof Troleibuz)
            {
                nr_troleibuze++;
            }

            else if(sir_mijloace[i] instanceof Tren)
            {
                nr_trenuri++;
            }
        }

        System.out.println("Numarul de trenuri este: " + nr_trenuri);
        System.out.println("Numarul de troleibuze este: " + nr_troleibuze);

    }
}