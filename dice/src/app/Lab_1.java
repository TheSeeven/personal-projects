package Java;

import java.util.Random;

class Zar
{
    int valoare;

    Zar()
    {   
        Random random = new Random();
        this.valoare = random.nextInt(7);
    }

    void print_zar()
    {
        System.out.println("Valoarea zarului este: " + this.valoare);
    }
}

class Start
{
    static int factorial(int n)
    {
        if(n>0 && n<13)
        {
           return factorial(n-1)*n; 
        }
        return 1;
    }

    static int[] generare(int n)
    {
        int[] array = new int[n];
        Random random = new Random();

        for(int i=0;i<n;i++)
        {
            array[i]=random.nextInt(20);
        }
        return array;
    }

    static void afisare_greater(int[] array, int n)
    {
        for(int i=0;i<array.length;i++)
        {
            if(array[i]<n)
            {
                System.out.print(array[i] + ",");
            }
        }
    }

    static void afisare_array(int[] array)
    {
        for(int i=0;i<array.length;i++)
        {
                System.out.print(array[i] + ",");
        }
    }

    static void verificare_palindrom(int n)
    {
        int temp=n;
        int r=0;
        int sum=0;
        while(n>0)
        {
            r=n%10;
            sum=(sum*10)+r;
            n=n/10;        
        }
        if(temp==sum)
        {
            System.out.println("Este palindom: " + temp);
        }
        else
        {
            System.out.println("Nu este palindom: " + temp);
        }
    
        
    }

    static int verificare_prim(int n)
    {
        for(int i=2;i<n/2;i++)
        {
            if(n%i == 0)
            {
                return 0;
            }
        }
        return n;
    }

    static void verificare_prim_random()
    {

        Random random = new Random();
        int x = random.nextInt(300);
        if(verificare_prim(x)==0)
        {
            System.out.println("Numarul " + x + " nu este prim!");
        }
        else
        {
            System.out.println("Numarul " + x + " este prim!");
        }
    }

    public static void main(String[] args)
    {   
        Zar zarul1 = new Zar();
        zarul1.print_zar();

        int x = factorial(5);
        System.out.println(x);

        int[] array_aleator = generare(15);;
        afisare_greater(array_aleator,5);
        System.out.println(" ");
        afisare_array(array_aleator);

        int palindrom = Integer.parseInt(args[0]);
        System.out.println(" ");
        verificare_palindrom(palindrom);

        
        verificare_prim_random();

    }
}