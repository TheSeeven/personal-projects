package app;

public class App 
{
    public static void main(String[] args)
    {
        ContBancar[] x = new ContBancar[2];
        ContBancar[] y = new ContBancar[2];
        x[0]= new ContBancar("BRLRON321115", 297.32);
        x[1]= new ContBancar("INGEURO321115", 666.6);
        y[0]= new ContBancar("BCRRON321115", 999.9);
        y[1]= new ContBancar("BSSLEURO321115", 100.576);

        Client[] z = new Client[2];

        z[0]=new Client("ion","M",x);
        z[1]=new Client("das","BC",y);

        Banca b = new Banca(z,"B");
        System.out.println(b);
        
    }
}