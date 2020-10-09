package app;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class App 
{
    public static void main(String[] args) 
    {
        int[] not1 = {4,5,3,5,67,7,3,3};
        int[] not2 = {3,4,9,9,7,2,5,6};
        ArrayList<Student> studenti = new ArrayList<Student>();

        studenti.add(new Student("ion","vasile",not1,5));
        studenti.add(new Student("ion2","alexle",not2,15));
        studenti.add(new Student("ion3","vadsale",not2,10));
        studenti.add(new Student("ion5","vasilssse",not1,8));
        try{
        RandomAccessFile raf = new RandomAccessFile("src/numere.dat","rw");
        raf.writeInt(7);
        raf.writeInt(-8);
        raf.writeInt(7);
        System.out.println(raf.readInt());

        while(raf.getFilePointer()<raf.length())
        {
            
        }

        for(int i=0;i<raf.length();i++)
        {
            System.out.println(raf.readInt());
        }

        }

        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}