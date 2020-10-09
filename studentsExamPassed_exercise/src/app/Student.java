package app;

import java.util.ArrayList;
import java.util.Iterator;

public class Student
{
    private String nume_student;
    private int[] note;
    private int grupa;
    private double medie;

    public Student(){}

    public Student(String nume_student,int grupa,int[] note)
    {
        this.nume_student=nume_student;
        this.note=note;
        this.grupa=grupa;

        int suma_note=0;

        for(int i:note)
        {
            suma_note+=i;
        }

        this.medie=(double)suma_note/(double)this.note.length;

    }

    private void print_note()
    {
        for(int i:note)
        {
            System.out.print(i + " ");
        }
    }

    public void print_student()
    {
        System.out.print("Nume: " + this.nume_student + " Grupa: " + this.grupa + " Note: " );
        this.print_note();
        System.out.println("");
    }

    public static void add_student(ArrayList<Student> arr,String nume,int grupa, int[] note)
    {
        arr.add(new Student(nume,grupa,note));
    }

    public static double medie_student(ArrayList<Student> arr,String nume)
    {
        Student temp = new Student();
        for(Student i:arr)
        {
            if(i.nume_student==nume)
            {
                temp=i;
            }
        }
        double impartitor = temp.note.length;
        double suma_note=0;
        for(int i:temp.note)
        {
            suma_note+=i;
        }
        double medie=suma_note/impartitor;
        return medie;
    }
    
    public String getNume_student() {
        return nume_student;
    }
  
    public double getMedie() {
        return medie;
    }

    public static boolean prea_putine_examene(ArrayList<Student> arr,String nume)
    {
        for(Student i:arr)
        {
            int examene_neluate=0;

            if(i.nume_student==nume)
            {
                for(int j:i.note)
                {
                    if(j<5)
                    {
                        examene_neluate++;
                    }
                    if(examene_neluate>=2)
                    {
                        return true;
                    }
                }
            }
            
        }
        return false;
    }

    public static boolean promovat(ArrayList<Student> arr,String nume)
    {
        for(Student i:arr)
        {
            if(i.nume_student==nume)
            {
                for(int j:i.note)
                {
                    if(j<5)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    public static void remove_student(ArrayList<Student> arr,String nume,int grupa)
    {
        Iterator<Student> it = arr.iterator();
        while(it.hasNext())
        {
            Student i = it.next();

            if(nume == i.nume_student &&  grupa == i.grupa)
            {
                it.remove();
            }
        }
    }


}
