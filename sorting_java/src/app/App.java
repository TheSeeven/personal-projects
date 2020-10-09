package app;
import java.util.Random;
import java.util.Arrays;
import java.lang.System; 

public class App {

    static int randInt(int min, int max) 
    {
        Random rand = new Random();
        int randomNum = rand.nextInt((max - min) + 1) + min;
    
        return randomNum;
    }

    static void fill_array(int array[],int a, int b)
    {
        for(int i=0;i<array.length;i++)
        {
            array[i] = randInt(a,b);
        }
    }
    
    static void print_array(int array[])
    {
        int contor = 0;
        for(int i=0;i<array.length;i++)
        {
            System.out.print(array[i] + " ");
            contor++;
            if(contor == 10)
            {
                System.out.println("");
                contor = 0;
            }
        }
        System.out.println("");
    }

    public static void main(String[] args) throws InterruptedException 
    {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int n = 10;

        int array[] = new int[n]; 
        fill_array(array, a, b);
        int array_backup[] = array.clone();

        long start1 = System.currentTimeMillis();
        Sort.bubbleSort(array);
        long end1 = System.currentTimeMillis();
        double sec1 = (end1 - start1) / 1000F; 
        System.out.println("Bubble sort: " + sec1);
        array = array_backup.clone();

        long start2 = System.currentTimeMillis();
        Sort.mergesort(array,0,array.length - 1);
        long end2 = System.currentTimeMillis();
        double sec2 = (end2 - start2) / 1000F; 
        System.out.println("Merge sort: " + sec2);
        array = array_backup.clone();

        long start3 = System.currentTimeMillis();
        Arrays.sort(array);
        long end3 = System.currentTimeMillis();
        double sec3 = (end3 - start3) / 1000F; 
        System.out.println("Cu functia array: " + sec3);   
    }
}