package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import gui.Data;

public class Adress
{

    private String company;
    private String street;
    private String city;
    private String country;
    private String zip_code;

    public Adress(){};

    public Adress(String company,String country,String city,String street,String zip_code)
    {
        this.company=company;
        this.street=street;
        this.city=city;
        this.country=country;
        this.zip_code=zip_code;
    }

    public String getCompany() {return company;}
    public String getCity() {return city;}
    public String getCountry() {return country;}
    public String getStreet() {return street;}
    public String getZip_code() {return zip_code;}

  
    public void setCompany(String company) {this.company = company;}
    public void setCity(String city) {this.city = city;}
    public void setCountry(String country) {this.country = country;}
    public void setStreet(String street) {this.street = street;}
    public void setZip_code(String zip_code) {this.zip_code = zip_code;}

    public String toString()
    {
        return "COMPANIE: " + this.getCompany() + "\nTARA:" + this.getCountry() + " ORAS:" + this.getCity() + "\n" + "STRADA:" + this.getStreet() + " ZIP:" + this.getZip_code();
    }
    
    public void add_adress(String cod)
    {
        String SQL1 = "insert into adress values('"+ this.company + "','" +this.country + "','" +this.city + "','" + this.street +"','"+this.zip_code+"','"+cod+"')";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            stmt.execute(SQL1);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
    public void add_adressprov(String cod)
    {
        String SQL1 = "insert into adressprov values('"+ this.company + "','" +this.country + "','" +this.city + "','" + this.street +"','"+this.zip_code+"','"+cod+"')";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            stmt.execute(SQL1);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public void remove_adress(String cod)
    {

        String SQL1 = "delete from adress where code='"+cod+"'";
        String SQL2 = "delete from adressprov where code='"+cod+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            stmt.execute(SQL1);
            stmt.execute(SQL2);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public GroupAdress view_adress(String cod)
    {

        String SQL1 = "select * from adress where code='"+cod+"'";
        String SQL2 = "select * from adressprov where code='"+cod+"'";
        GroupAdress rez = new GroupAdress();

        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet a = stmt.executeQuery(SQL1);
            ResultSet b = stmt.executeQuery(SQL2);
            Adress x = new Adress(a.getNString("company"),a.getNString("street"),a.getNString("city"),a.getNString("country"),a.getNString("zipcode"));
            Adress y = new Adress(b.getNString("company"),b.getNString("street"),b.getNString("city"),b.getNString("country"),b.getNString("zipcode"));
            rez = new GroupAdress(x,y);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return rez;
    }

}