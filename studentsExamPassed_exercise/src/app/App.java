package app;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class App
{
    static void print_studenti(ArrayList<Student> arr)
    {
        for(Student i:arr)
        {
            i.print_student();
        }
    }


    public static void main(String[] args)
    {

        ArrayList<Student> arr = new ArrayList<Student>();

        int[] sample1={10,5,7,3};
        int[] sample2={8,7,6,9};
        int[] sample3={4,2,7,8};
        int[] sample4={10,9,9,8};
        int[] sample5={7,6,4,7};
        int[] sample6={6,3,2,1};

        arr.add(new Student("Edward",4,sample1));
        arr.add(new Student("Alex",1,sample2));
        arr.add(new Student("Jessica",1,sample3));
        arr.add(new Student("Leon",3,sample4));
        arr.add(new Student("Robert",4,sample5));
        arr.add(new Student("Vasile",2,sample6));

        System.out.println("Studentii inainte de eliminare: \n");

        print_studenti(arr);

        System.out.println("\nStudentii dupa eliminarea unui student: \n");

        Student.remove_student(arr, "Jessica", 1);
        print_studenti(arr);

        System.out.println("\nStudentii dupa adaugarea unui student: \n");

        Student.add_student(arr,"Mihai",5,sample3);
        print_studenti(arr);

        System.out.println("\nCalcularea mediei unui student: \n");

        System.out.println(Student.medie_student(arr, "Edward"));

        System.out.println("\nStudenti care nu au promovat: \n");

        for(Student i:arr)
        {
            if (!Student.promovat(arr, i.getNume_student()))
            {
                i.print_student();
                
            }
        }

        System.out.println("\nStudentii sortati dupa medie: \n");
        Collections.sort(arr, comparare_medie);
        print_studenti(arr);

        System.out.println("\nStudentii sortati dupa nume: \n");
        Collections.sort(arr, comparare_nume);
        print_studenti(arr);

        System.out.println("\nStudentii care au prea putine examene luate: \n");

        for(Student i:arr)
        {
            if(Student.prea_putine_examene(arr, i.getNume_student()))
            {
                i.print_student();
            }
        }
        
    }

    static Comparator<Student> comparare_nume = new Comparator<Student>()
    {       
        public int compare(Student o1, Student o2) 
        {
            if((o1.getNume_student()).compareTo(o2.getNume_student()) > 0)
            {
                return 1;
            }
            else if ((o1.getNume_student()).compareTo(o2.getNume_student()) < 0)
            {
                return -1;
            }
            return 0;
        }
    };

    static Comparator<Student> comparare_medie = new Comparator<Student>()
    {       
        public int compare(Student o1, Student o2) 
        {
            if(o1.getMedie()<(o2.getMedie()))
            {
                return 1;
            }
            else if (o1.getMedie()>o2.getMedie())
            {
                return -1;
            }
            return 0;
        }
    };


}