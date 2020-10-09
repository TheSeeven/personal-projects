package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Random;

import gui.Data;

public interface Functions {
    public static String generate_unique_code() {
        String ALPHA_NUMERIC = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890";
        StringBuilder cod = new StringBuilder();
        Random random = new Random();
        while (cod.length() < 10) {
            int random_integer = random.nextInt(36);
            cod.append(ALPHA_NUMERIC.charAt(random_integer));
        }
        String cod_return = cod.toString();

        if (!check_unique_code(cod_return)) {
            generate_unique_code();
        }
        return cod_return;
    }

    static private boolean check_unique_code(String x) 
    {
        String SQL1 = "select 1 from order_buffer where code='"+x+"'";
        String SQL2 = "select 1 from order_history where code='"+x+"'";
        try
            {Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            Statement stmt2 = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            ResultSet rs2 = stmt2.executeQuery(SQL2);
            
            if(!rs.next() && !rs2.next())
            {return true;}
        }
            
        catch(Exception e)
            {e.printStackTrace();}
        return false;
    }

    public static int find_user_credentials(String username, String password)
    {   
        boolean in_database;
        boolean manager;
        String SQL1 = "select name,password,job from users where name='" + username +"' and password='"+password+"'";
        try
            {Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            if(rs.next())
                {User x = new User(rs.getString("name"),rs.getString("job"),rs.getString("password"));
                in_database=true;
                if(x.getJob().toUpperCase().equals("MANAGER"))
                {manager=true;}
                else
                {Data.functie=x.getJob().toUpperCase();
                manager=false;}}
            else
            {in_database=false;
            manager=false;}}
        catch(Exception e)
            {e.printStackTrace();return 0;}
            if(in_database && manager)
            {return 2;}
            else if(in_database && !manager)
            {return 1;}
            return 0;  
    }

    public static String get_String(char[] x)
    {
        StringBuffer y = new StringBuffer();
        for(char i:x)
        {
            y.append(i);
        }
        String rez = new String(y);
        return rez;
    }

    public static boolean good_password(char[] pass)
    {
        String password = new String(pass);
        boolean upercase = false;
        boolean numbers = false;
        boolean special = false;
        boolean space = false;
        for(int i=0;i<password.length();i++)
        {
            if((Character.isUpperCase(password.charAt(i))))
            {
                upercase = true;
                continue;
            }
            else if((Character.isDigit(password.charAt(i))))
            {
                numbers = true;
                continue;
            }
            else if(String.valueOf(password.charAt(i)).matches("[^a-zA-Z0-9\\s]"))
            {
                special = true;
                continue;
            }
            else if(password.charAt(i) == ' ')
            {
                space = true;
                break;
            }
        }
        if(password.length() < 8)
        {
            return false;
        }

        else if(upercase && numbers && special && !space)
        {
            return true;
        }

        return false;
    }

    public static void create_tables()
    {
        try{
        String sql1 = "create table adress(company varchar(30),country varchar(30),city varchar(64),street varchar(256),zipcode varchar(20),code varchar(10))";
        String sql2 = "create table adressprov(company varchar(30),country varchar(30),city varchar(64),street varchar(256),zipcode varchar(20),code varchar(10))";
        String sql3 = "create table order_buffer(name varchar(30),code varchar(10),oname varchar(30),qtype varchar(10),quantity int,fragile boolean,alcohol boolean,electronic boolean,consumption boolean,date date)";
        String sql4 = "create table order_history(name varchar(30),code varchar(10),oname varchar(30),qtype varchar(10),quantity int,fragile boolean,alcohol boolean,electronic boolean,consumption boolean,date date)";
        String sql5 = "create table users(name varchar(30),password varchar(64),job varchar(20))";
        String sql6 = "insert into users values('root','root','MANAGER')";

        Connection con = DriverManager.getConnection(Data.url);
        Statement stmt1 = con.createStatement();
        Statement stmt2 = con.createStatement();
        Statement stmt3 = con.createStatement();
        Statement stmt4 = con.createStatement();
        Statement stmt5 = con.createStatement();
        Statement stmt6 = con.createStatement();

        stmt1.execute(sql1);
        stmt2.execute(sql2);
        stmt3.execute(sql3);
        stmt4.execute(sql4);
        stmt5.execute(sql5);
        stmt6.execute(sql6);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

}