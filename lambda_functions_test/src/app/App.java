package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

interface Functii
{
    int adunare(int x,int y);
}
interface Functii2
{
    int scadere(int x,int y);
}

public class App {
    public static void main(String[] args) throws SQLException 
    {
        // final String URL="jdbc:derby:C:\\Onedrive\\Desktop\\DB:create=true";
        System.out.println("Hello Java");
        // Connection connection = DriverManager.getConnection(URL);

        Functii f1 = (int x,int y)->x+y;    
        Functii f2 = (int x,int y)->x-y; 
        System.out.println(f1.adunare(5,7));
        System.out.println(f2.adunare(5,7));
        
    }
}