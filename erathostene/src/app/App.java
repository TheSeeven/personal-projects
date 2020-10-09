package app;
import java.lang.System;

public class App 
{
    static void fill_array(boolean array[])
    {
        for(int i=2;i<array.length;i++)
        {
            array[i]=true;
        }
    }

    static void remove_nonprime(boolean array[])
    {
        for(int i=2;i<array.length;i++)
        {
            for(int j=i+i;j<array.length;)
            {
               array[j] = false; 
               j=j+i;
            }
        }
    }

    static void print_array(boolean array[])
    {
        int contor_rand=1;
        for(int i=0;i<array.length;i++)
        {
            if(array[i]!=false)
            {
                System.out.print(i + " ");
                contor_rand++;
                if(contor_rand==20)
                {
                    System.out.println(" ");
                    contor_rand=0;
                }
            }
        }
        System.out.println(" ");
    }

    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        boolean array[] = new boolean[n];

        long start = System.currentTimeMillis();
        fill_array(array);
        remove_nonprime(array);
        long end = System.currentTimeMillis();
        double sec = (end - start) / 1000F;
        System.out.println("Timpul de executie al algoritmului: " + sec);
        print_array(array);










        

    }
}