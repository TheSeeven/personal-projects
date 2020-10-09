package bec_comenzi;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;

final class Database
{
    final static boolean csv_exist(String path_string)
    {
        Path path = Paths.get(path_string);
        boolean bool = (path.toFile()).exists();
        return bool;
    }

    final static void create_csv(String path_string)
    {
        Path path = Paths.get(path_string);
        final String [] cap_tabel = {"Pret","Numar_Bucati","Lumeni","Cod Unic","Brand","Model","Destinatie","Provenienta","Data"};
    
    try
        {
            FileWriter file = new FileWriter(path.toString());
            for(int i=0;i<cap_tabel.length;i++)
            {
                file.append(cap_tabel[i] + ",");
            }
            file.flush();
        }
    catch (IOException e) 
        { 
            e.printStackTrace(); 
        }
    } 

    final static String string_bec(Bec order)
    {
        String string = order.pret + "," + order.nr_bucati  + "," + order.lumeni + "," + order.cod_unic + "," + order.brand + "," + order.model + "," + order.destinatie + "," + order.provenienta;
        return string;
    }



    final static void add_order(Bec order) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Onedrive\\Desktop\\bec_comenzi.csv"));
        String line = br.readLine();

        
        while((line = br.readLine()) != null)
        {
            String[] cols = line.split(",");
        }
        
        FileWriter outputfile = new FileWriter("C:\\Onedrive\\Desktop\\bec_comenzi.csv");
        outputfile.append(string_bec(order));
        outputfile.flush();

    }


}