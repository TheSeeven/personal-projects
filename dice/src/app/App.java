package app;
import java.util.Arrays;
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


public class App 
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

    static void afisare_matrix(int[][] matrix)
    {
        for(int i=0;i<matrix.length;i++)
        {
            int contor_randuri=1;
            for(int j=0;j<matrix.length;j++)
            {
                System.out.print(matrix[i][j] + " ");
                contor_randuri++;
                if(contor_randuri==20)
                {
                    contor_randuri=1;
                    System.out.println(" ");
                }
            }
        }
    }

    static int min(int x, int y)
    {
        if(x<y)
        {
            return x;
        }
        return y;
    }

    static void min_2_array(int array[],int x[],int y[])
    {
        for(int i=0;i<x.length;i++)
        {
            array[i]=min(x[i],y[i]);
        }
    }
    public static void main(String[] args)
    {
            Zar zarul1 = new Zar();
            zarul1.print_zar();
    
            int x = factorial(5);
            System.out.println(x);
    
            int[] array_aleator = generare(15);

            Arrays.sort(array_aleator);

            afisare_greater(array_aleator,5);
            System.out.println(" ");
            afisare_array(array_aleator);
    
            int palindrom = Integer.parseInt(args[0]);
            System.out.println(" ");
            verificare_palindrom(palindrom);
            
            verificare_prim_random();

            int[] array_x=generare(10);
            int[] array_y=generare(10);
            int[][] Matrix_A = new int[array_x.length][array_y.length];
            int[] array_z = new int[10];
            
            for(int i=0;i<10;i++)
            {
                int valoare = 0;
                for(int j=0;j<10;j++)
                {
                    valoare = array_x[i]*array_y[j];
                    Matrix_A[i][j]=valoare;
                }
            }

            //afisare_matrix(Matrix_A);
            min_2_array(array_z,array_x,array_y);
            System.out.println(" ");
            afisare_array(array_x);
            System.out.println(" ");
            afisare_array(array_y);
            System.out.println(" ");
            afisare_array(array_z);
            System.out.println(" ");

            String sir = "caracatita";

            // for(int i=0;i<sir.length();i++)
            // {
            //     if(args[1].charAt(0) == sir.charAt(i))
            //     {
            //         System.out.println("pozitia: " + i + " caracterul: " + args[1] );
            //     }
            // }

            // if(sir.contains(args[1]))
            // {
            //     System.out.println("Subsirul: " + args[1] + " exista in sirul " + sir);
            // }
            
            System.out.println("Lungime sirului este: " + args[1].length());
            
            System.out.println("args UPPERCASE: " + args[1].toUpperCase());
            for(int i=1;i<args[1].length()/2;i++)
            {
                System.out.print(sir.charAt(i));
            }
            System.out.println("");
            System.out.println(sir.getClass());
            
            System.out.println("args LOWERCASE: " +args[1].toLowerCase());

                
    }
}