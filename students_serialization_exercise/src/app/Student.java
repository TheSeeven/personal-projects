package app;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

import org.omg.Messaging.SyncScopeHelper;

public class Student implements Serializable
{
    String nume;
    String numeCurs;
    int[] note;
    int nrPrezente;

    private static final long serialVersionUID=111l;

    Student(){};

    Student(String nume, String numeCurs,int[] note,int nrPrezente)
    {
        this.nume=nume;
        this.numeCurs=numeCurs;
        this.note=note;
        this.nrPrezente=nrPrezente;
    } 

    static void serializare(ArrayList lista,File f)
    {
        try
        {
            FileOutputStream fos = new FileOutputStream(f);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(lista);
            oos.close(); fos.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }

}