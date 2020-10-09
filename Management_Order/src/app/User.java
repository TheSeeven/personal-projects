package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import gui.Data;

public class User {

    private String name;
    private String job;
    private String passwd;

    public User(String name, String job, String passwd) {
        this.name = name;
        this.job = job;
        this.passwd = passwd;
    }
    public User(String name, String job) 
    {
        this.name = name;
        this.job = job;
    }

    public String getName() {
        return name;
    }

    public String getJob() {
        return job;
    }

    public String getPass() {
        return passwd;
    }

    public void setJob(String job) {
        this.job = job;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPasswd(String passwd) {
        this.passwd = passwd;
    }

    public boolean add()
    {   String name = this.getName();
        String job = this.getJob();
        String pass = this.getPass();
        try{String SQL1 = "insert into users values('"+name+"','"+pass+"','"+job+"')";
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            if(stmt.execute(SQL1))
            {return true;}}
        catch(Exception e)
        {e.printStackTrace();}
        return false;
    }

    public static boolean remove(String username)
    {
        String SQL1 = "delete from users where name='"+username+"'";
        try
            {Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            stmt.execute(SQL1);
            return true;}
        catch(Exception e)
            {e.printStackTrace();}
        return false;
    }

    public static boolean find(String user)
    {
        String SQL1 = "select 1 from users where name='"+user+"'";
        try
            {Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            if(rs.next() && rs.getInt("1")==1)
            {return true;}}
        catch(Exception e)
            {e.printStackTrace();}
        return false;
    }

    public static String get_functie(String user) 
    {
        String SQL1 = "select job from users where name='"+user+"'";
        try
            {Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
        if(rs.next())
            {String functie = rs.getString("job");
            return functie;}}
        catch(Exception e)
            {e.printStackTrace();}
        return "";
    }

}
