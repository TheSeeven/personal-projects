package app;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

public class Student implements Serializable
{
    
    private static final long serialVersionUID = 14455L;
    
    private int prezente;
    private int nota;
    private String nume;
    private String curs;

    public Student(){}
    
    public Student(String nume,String curs,int nota,int prezente)
    {
        this.nume=nume;
        this.curs=curs;
        this.nota=nota;
        this.prezente=prezente;
    }

    public String getCurs() {
        return curs;
    }
    
    public int getNota() {
        return nota;
    }
    
    public String getNume() {
        return nume;
    }

    public int getPrezente() {
        return prezente;
    }

    public void setCurs(String curs) {
        this.curs = curs;
    }
    
    public void setNota(int nota) {
        this.nota = nota;
    }
    
    public void setNume(String nume) {
        this.nume = nume;
    }

    public void setPrezente(int prezente) {
        this.prezente = prezente;
    }

    public String toString()
    {
        return this.nume + " " + this.curs + " " + this.nota + " " + this.prezente;
    }

    public void serializare(String filename)
    {
        
        File fisier = new File(filename);
        try
        {
            FileOutputStream file = new FileOutputStream(fisier);
            ObjectOutputStream out = new ObjectOutputStream(file);

            out.writeObject(this);

            out.close();
            file.close();
            System.out.println("Obiectul a fost serializat!");
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }

    public static void serializarea(ArrayList<Student> arr,String filename)
    {
        
        File fisier = new File(filename);
        try
        {
            FileOutputStream file = new FileOutputStream(fisier);
            ObjectOutputStream out = new ObjectOutputStream(file);

            out.writeObject(arr);
            

            out.close();
            file.close();
            System.out.println("Obiectul a fost serializat!");
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }

    public static void deserealizare(String filename) throws ClassNotFoundException
    {
        try
        {
            FileInputStream file = new FileInputStream(filename); 
            ObjectInputStream in = new ObjectInputStream(file);


            ArrayList<Student> object = (ArrayList<Student>)in.readObject();

            for(Student j:object)
                System.out.println(j.toString());
            
            in.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}