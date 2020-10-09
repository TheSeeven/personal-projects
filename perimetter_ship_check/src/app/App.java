package app;

public class App 
{
    public static void main(String[] args) 
    {
        Nava[] sir_nave = new Nava[5];

        sir_nave[0] = new Nava(50.2,19.3,"f20","Amarghioale"); 
        sir_nave[1] = new Nava(500,600,"c20","Alex");
        sir_nave[2] = new Nava(55.5,20.23,"cae22","Mozart");
        sir_nave[3] = new Nava(500,700,"Bismark","");
        sir_nave[4] = new Nava(300,400,"Deni5s","");


        System.out.println("Toate navele din sir: \n\n");

        for(int i=0;i<sir_nave.length;i++)
        {
            try
            {
                System.out.println(sir_nave[i].toString());
            }
            catch(NullPointerException e)
            {
                i++;
            }
        }

        System.out.println("\n\nToate navele din sir care nu apartin unui proprietar: \n\n");

        for(int i=0;i<sir_nave.length;i++)
        {
            try
            {
                if(sir_nave[i].get_proprietar() != args[0])
                System.out.println(sir_nave[i].toString());
            }
            catch(NullPointerException e)
            {
                i++;
            }
        }
        
        System.out.println("\n\nNave in perimetru unei nave: \n\n");

        for(int i=0;i<sir_nave.length;i++)
        {
            try
            {
                if(sir_nave[0].proximitate(sir_nave[i], 500))
                System.out.println(sir_nave[i].toString());
            }
            catch(NullPointerException e)
            {
                i++;
            }
        }
    }
}