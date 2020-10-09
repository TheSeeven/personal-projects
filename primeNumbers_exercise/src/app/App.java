package app;
import java.util.Random;

public class App 
{   
    static boolean is_prim(int numar)
    {
        if(numar != 0)
        {
        for(int i=2;i<numar/2;i++)
        {
            if(numar % i == 0)
            {
                return false;
            }
        }}
        else
        {
            return false;
        }
        return true;
    }    
    
    static boolean is_impar(int numar)
    {
        if(numar%2==1)
        {
            return true;
        }
        return false;
    }
    
    static int numere_prime_impare(int array[][])
    {
        int contor_prime = 0;
        int contor_impare = 0;
        int randuri = 1;

        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array[i].length;j++)
            {
                if(is_prim(array[i][j]))
                {
                    System.out.print(array[i][j] + " ");
                    randuri ++;
                    contor_prime ++;
                    if(randuri == array.length)
                    {
                        System.out.println("");
                        randuri = 1;
                    }
                }
            }
        }
        System.out.println("");
        System.out.println("Sunt " + contor_prime + " numere prime");

        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array[i].length;j++)
            {
                if(is_impar(array[i][j]))
                {
                    contor_impare++;
                }
            }
        }

        System.out.println("Sunt " + contor_impare + " numere impare");

        return 0;
    }

    static int[][] generare_random_numere_array(int array[][])
    {
        Random rand = new Random();
        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array[i].length;j++)
            {
                array[i][j] = rand.nextInt(100);
            }
        }
        return array;
    }

    static void print_array(int array[][])
    {
        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array[i].length;j++)
            {
                System.out.print(array[i][j] + " ");
            }
            System.out.println("");
        }
    }

    
    static void print_div_5(int array[][])
    {
        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array[i].length;j++)
            {
                if(array[i][j]%5==0)
                {
                    Div obj = new Div(array[i][j],i,j);
                    obj.print_div();
                }
            }
            
        }
    }

    static int vertical_array_size(int array[][])
    {
        return array[0].length;
    }

    static int max_vertical_orizontal_array(int array[][])
    {
        if(vertical_array_size(array)<array.length)
        {
            return array.length;
        }
        return vertical_array_size(array);
    }

   static void coloane_sum_min(int array[][])
   {
       int suma_coloana = 0;
       SumCol[] array_coloane_valoare = new SumCol[max_vertical_orizontal_array(array)];
       int index_SumCol = 0;

       for(int i=0;i<vertical_array_size(array);i++)
       {
           for(int j=0;j<array.length;j++)
           {
                suma_coloana += array[j][i];
           }
           SumCol obj = new SumCol(suma_coloana, i);
           array_coloane_valoare[index_SumCol] = obj;
           index_SumCol ++;
           suma_coloana = 0;
       }

       SumCol smallest = array_coloane_valoare[0];

       for(int i=0;i<array_coloane_valoare.length;i++)
       {
           if(array_coloane_valoare[i]!=null){
           if(array_coloane_valoare[i].suma<=smallest.suma)
           {
                smallest = array_coloane_valoare[i];
           }}
           else
           {
            break;
           }
       }
       smallest.print_sumcol();
   }

   static boolean punct_sa(int array[][],int index_linie,int index_coloana)
   {
    int x = array[index_linie][index_coloana];
    if(max_linie(array,index_linie,x) && min_coloana(array,index_coloana,x))
        {
            return true;
        }
    return false;
   }
   
   static boolean max_linie(int array[][],int linie,int numar)
   {
       for(int i=0;i<vertical_array_size(array);i++)
        {
        if(numar<array[linie][i])
            {
                return false;
            }
        }
        return true;
   }
   
   static boolean min_coloana(int array[][],int coloana,int numar)
   {
    for(int i=0;i<array.length;i++)
        {
        if(numar>array[i][coloana])
            {
                return false;
            }
        }
        return true;
   }

   static void print_saddle_points(int array[][])
   {
    for(int i=0;i<array.length;i++)
    {
        for(int j=0;j<vertical_array_size(array);j++)
        {
            if(punct_sa(array,i,j))
            {
                System.out.println("Linia: " + (i+1) +" Coloana: " + (j+1) + " Numarul: " + array[i][j]);
            }
        }
    }
   }

    public static void main(String[] args)
    {
        int[][] array = new int[Integer.parseInt(args[0])][Integer.parseInt(args[1])];
        array = generare_random_numere_array(array);
        
        print_array(array);
        System.out.println("\n\n" + "Exercitiul 1" + "\n\n");
        numere_prime_impare(array);
        print_div_5(array);
        coloane_sum_min(array);
        print_saddle_points(array);

    }
}