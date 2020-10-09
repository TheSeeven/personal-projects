package app;

public class App {
    public static void main(String[] args) 
    {
        Avion[] array = new Avion[8];
        array[0] = new Boeing(10,1000,"f234");
        array[1] = new Concorde(50,1200,"p501200");
        array[2] = new Mig(1200,"machinegun69");
        array[3] = new Tomcat(1200,"fight5");
        array[4] = new Boeing(666,2500,"disperol");
        array[5] = new Concorde(256,1028,"binaryplane");
        array[6] = new Mig(689,"f207");
        array[7] = new Tomcat(300,"smol23");

        System.out.println("Afisare lista de avioane: \n\n");
        for(int i=0;i<array.length;i++)
        {
            System.out.println(array[i].toString());
        }

        System.out.println("\n\nFunctionalitate avioane: \n\n");

        array[0].decoleaza();
        array[1].zboara();
        array[2].decoleaza();
        array[3].aterizeaza();
        array[4].zboara();
        array[5].decoleaza();
        array[6].zboara();
        array[7].aterizeaza();
        
        
    }


}