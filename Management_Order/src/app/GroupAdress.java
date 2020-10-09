package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import gui.Data;

public class GroupAdress
{
    public Adress provenienta;
    public Adress destinatie;

    public GroupAdress(){}

    public GroupAdress(Adress x, Adress y)
    {
        provenienta=x;
        destinatie=y;
    }

    public static void add_adressgroup(Order x)
    {   
        GroupAdress adress = new GroupAdress(x.getProvenience(),x.getDestination());
        String SQL2 = "insert into adressprov values('"+ adress.provenienta.getCompany() + "','" +adress.provenienta.getCountry() + "','" +adress.provenienta.getCity() + "','" + adress.provenienta.getStreet() +"','"+ adress.provenienta.getZip_code() +"','"+x.getCode()+"')";
        String SQL1 = "insert into adress values('"+ adress.destinatie.getCompany() + "','" + adress.destinatie.getCountry() + "','" + adress.destinatie.getCity() + "','" + adress.destinatie.getStreet() +"','"+adress.destinatie.getZip_code()+"','"+x.getCode()+"')";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            Statement stmt2 = con.createStatement();
            stmt.execute(SQL1);
            stmt2.execute(SQL2);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static GroupAdress view_adress(String code)
    {

        GroupAdress rez = new GroupAdress();
        
        String SQL1 = "select * from adressprov where code='"+code+"'";
        String SQL2 = "select * from adress where code='"+code+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            Statement stmt2 = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            ResultSet rs2 = stmt2.executeQuery(SQL2);
            rs.next();
            rs2.next();

            Adress a = new Adress(rs.getString("company"),rs.getString("street"),rs.getString("city"),rs.getString("country"),rs.getString("zipcode"));
            Adress b = new Adress(rs2.getString("company"),rs2.getString("street"),rs2.getString("city"),rs2.getString("country"),rs2.getString("zipcode"));
            rez = new GroupAdress(a,b);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }

        return rez;
    }


}