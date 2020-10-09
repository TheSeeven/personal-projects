package app;

public class Student extends Persoana implements Print
{
    int anStudiu;
    static int aniStudiu;

    public Student(){}

    public Student(String nume,String prenume,int varsta,int inaltime,int anStudiu) throws Exception
    {
        super(nume,prenume,varsta,inaltime);
        this.anStudiu=anStudiu;
    }

    
    public void print() 
    {
        System.out.print(this + " ");
        System.out.println(anStudiu + " " + aniStudiu);


    }

    

}