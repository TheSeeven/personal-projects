package pachet3;

import pachet1.MijlocDeTransport;

public class Transport 
{
    public static void main(String[] args)
    {   
        MijlocDeTransport x1 = new MijlocDeTransport(); // Nu sunt vizibile atributele deoarece sunt private
        MijlocDeTransport x2 = new MijlocDeTransport("Verde","Marinel",2010,false); // Nu sunt vizibile atributele deoarece sunt private
        MijlocDeTransport x3 = new MijlocDeTransport();
        
        x1.set_culoare("Verde");
        x1.set_producator("Ioanel");
        x1.set_anProductie(2000);
        x1.set_functional(true);
        
        System.out.println("Acesta este trenule x3: ");
        System.out.println(x3.get_anProductie());
        System.out.println(x3.get_culoare());
        System.out.println(x3.get_functional());
        System.out.println(x3.get_producator());
        System.out.println(" ");
        
        
    }
}