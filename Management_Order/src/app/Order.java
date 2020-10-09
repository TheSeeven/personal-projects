package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import gui.Data;

public class Order {
    private static String[] quantity_types = { "palets", "packs", "kg", "t" };

    private String code;
    private String name;
    private Adress destination;
    private Adress provenience;

    private String username;

    private String quantity_type;
    private int quantity;

    private boolean fragile;
    private boolean alcohol;
    private boolean electronic;
    private boolean consumption;

    public Order(){}

    public Order(String username, String name, Adress destination, Adress provenience, int quantity_type, int quantity,
            boolean fragile, boolean alcohol, boolean electronic, boolean consumption)
    {
        this.username=username;
        this.code=Functions.generate_unique_code(); 

        this.name=name;
        this.destination=destination;
        this.provenience=provenience;


        this.quantity_type=quantity_types[quantity_type];

        this.consumption=consumption;
        this.fragile=fragile;           
        this.alcohol=alcohol;
        this.electronic=electronic;
        
        this.quantity=quantity;
    }

    public Order(String username,String code,String name,Adress destination,Adress provenience,int quantity_type,int quantity,boolean fragile,boolean alcohol,boolean electronic,boolean consumption)
    {
        this.username=username;
        this.code=code; 

        this.name=name;
        this.destination=destination;
        this.provenience=provenience;


        this.quantity_type=quantity_types[quantity_type];

        this.consumption=consumption;
        this.fragile=fragile;           
        this.alcohol=alcohol;
        this.electronic=electronic;
        
        this.quantity=quantity;
    }

    public Order(String username,String code,String name,Adress destination,Adress provenience,String quantity_type,int quantity,boolean fragile,boolean alcohol,boolean electronic,boolean consumption)
    {
        this.username=username;
        this.code=code; 

        this.name=name;
        this.destination=destination;
        this.provenience=provenience;


        this.quantity_type=quantity_type;

        this.consumption=consumption;
        this.fragile=fragile;           
        this.alcohol=alcohol;
        this.electronic=electronic;
        
        this.quantity=quantity;
    }
    

    public Order(String username,String code,String name,int quantity_type,int quantity,boolean fragile,boolean alcohol,boolean electronic,boolean consumption)
    {
        this.username=username;
        this.code=code; 

        this.name=name;

        this.quantity_type=quantity_types[quantity_type];

        this.consumption=consumption;
        this.fragile=fragile;           
        this.alcohol=alcohol;
        this.electronic=electronic;
        
        this.quantity=quantity;
    }
    public Order(String username,String code,String name,String quantity_type,int quantity,boolean fragile,boolean alcohol,boolean electronic,boolean consumption)
    {
        this.username=username;
        this.code=code; 

        this.name=name;

        this.quantity_type=quantity_type;

        this.consumption=consumption;
        this.fragile=fragile;           
        this.alcohol=alcohol;
        this.electronic=electronic;
        
        this.quantity=quantity;
    }

    public String getUsername() {return username;}
    public String getName() {return name;}
    public String getCode() {return code;}   

    public Adress getDestination() {return destination;}
    public Adress getProvenience() {return provenience;}

    public String getname() {return name;}                                                                                                
    public String getQuantity_type() {return quantity_type;}

    public boolean getConsumption() {return consumption;}
    public boolean getFragile() {return fragile;}
    public boolean getAlcohol() {return alcohol;}
    public boolean getElectronic() {return electronic;}  

    public int getQuantity() {return quantity;}  


    public void setQuantity_type(String quantity_type) {this.quantity_type = quantity_type;} 
    public void setname(String name) {this.name = name;}                                            
    public void setProvenience(Adress provenience) {this.provenience = provenience;}                                                                                  
    public void setDestination(Adress destination) {this.destination = destination;}  
    public void setCode(String code) {this.code = code;}   

    public void setElectronic(boolean electronic) {this.electronic = electronic;}                   
    public void setFragile(boolean fragile) {this.fragile = fragile;}  
    public void SetConsumption(boolean consumption) {this.consumption=consumption;} 
    public void setAlcohol(boolean alcohol) {this.alcohol = alcohol;} 
  
    public void setQuantity(int quantity) {this.quantity = quantity;} 
    
    
    public static boolean completed(String cod)
    {
        String SQL1 = "insert into order_history select * from order_buffer where code='"+cod+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            stmt.execute(SQL1);
            remove_buffer(cod);
            return true;
            
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return false;
    }

    public void add_buffer()
    {
        String SQL1 = "insert into order_buffer values('"+this.username+"','"+this.code+"','"+this.name+"','"+this.quantity_type+"',"+this.quantity+","+this.fragile+","+this.alcohol+","+this.electronic+","+this.consumption+",current_date)";
        String SQL2 = "insert into adress values('"+this.destination.getCompany()+"','"+this.destination.getCountry()+"','"+this.destination.getCity()+"','"+this.destination.getStreet()+"','"+this.destination.getZip_code()+"','"+this.code+"')";
        String SQL3 = "insert into adressprov values('"+this.provenience.getCompany()+"','"+this.provenience.getCountry()+"','"+this.provenience.getCity()+"','"+this.provenience.getStreet()+"','"+this.provenience.getZip_code()+"','"+this.code+"')";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            stmt1.execute(SQL1);
            stmt2.execute(SQL2);
            stmt3.execute(SQL3);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
    public static void remove_buffer(String cod)
    {
        String SQL1 = "delete from order_buffer where code='"+cod+"'";
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
    
    public static ArrayList<Order> view_buffer_user(String user)
    {
        ArrayList<Order> x = new ArrayList<Order>();
        if(User.get_functie(user).toUpperCase().equals("MANAGER")){
            String SQL1 = "select * from order_buffer";
            try
            {
                Connection con = DriverManager.getConnection(Data.url);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery(SQL1);
                while(rs.next())
                {
                    Order ord = new Order(rs.getString("name"),rs.getString("code"),rs.getString("oname"),rs.getString("qtype"),rs.getInt("quantity"),rs.getBoolean("fragile"),rs.getBoolean("alcohol"),rs.getBoolean("electronic"),rs.getBoolean("consumption"));
                    x.add(ord);

                }
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
        else
        {
            String SQL1 = "select * from order_buffer where name='"+user+"'";
            try
            {
                Connection con = DriverManager.getConnection(Data.url);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery(SQL1);
                while(rs.next())
                {
                   // x.add(rs.getNString("User:" + rs.getNString("name")+" Code:" + rs.getNString("code")+" Order:" + rs.getNString("oname")+" Quantity:"+rs.getNString("quantity")+rs.getNString("qtype")));
                   Order ord = new Order(rs.getString("name"),rs.getString("code"),rs.getString("oname"),rs.getString("qtype"),rs.getInt("quantity"),rs.getBoolean("fragile"),rs.getBoolean("alcohol"),rs.getBoolean("electronic"),rs.getBoolean("consumption"));
                   x.add(ord);

                }
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }

        return x;
    }

    public static ArrayList<Order> view_history_user(String user)
    {
        ArrayList<Order> x = new ArrayList<Order>();
        if(User.get_functie(user).toUpperCase().equals("MANAGER")){
            String SQL1 = "select * from order_history";
            try
            {
                Connection con = DriverManager.getConnection(Data.url);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery(SQL1);
                while(rs.next())
                {
                    Order ord = new Order(rs.getString("name"),rs.getString("code"),rs.getString("oname"),rs.getString("qtype"),rs.getInt("quantity"),rs.getBoolean("fragile"),rs.getBoolean("alcohol"),rs.getBoolean("electronic"),rs.getBoolean("consumption"));
                    x.add(ord);

                }
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
        else
        {
            String SQL1 = "select * from order_history where name='"+user+"'";
            try
            {
                Connection con = DriverManager.getConnection(Data.url);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery(SQL1);
                while(rs.next())
                {
                   Order ord = new Order(rs.getString("name"),rs.getString("code"),rs.getString("oname"),rs.getString("qtype"),rs.getInt("quantity"),rs.getBoolean("fragile"),rs.getBoolean("alcohol"),rs.getBoolean("electronic"),rs.getBoolean("consumption"));
                   x.add(ord);

                }
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }

        return x;
    }

    public ArrayList<String> view_buffer_manager()
    {
        ArrayList<String> x = new ArrayList<String>();
        String SQL1 = "select * from order_buffer";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            while(rs.next())
            {
                x.add(rs.getNString("User:" + rs.getNString("name")+" Code:" + rs.getNString("code")+" Order:" + rs.getNString("oname")+" Quantity:"+rs.getNString("quantity")+rs.getNString("qtype")));
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return x;
    }

    public static boolean find_buffer_user(String username,String cod)
    {
        String SQL1 = "select 1 from order_buffer where code='"+cod+"' and name='"+username+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            rs.next();
            if(rs.getInt("1")==1)
            {
                return true;
            }
            return false;
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return false;
    }

    public static boolean find_buffer_manager(String cod)
    {
        String SQL1 = "select 1 from order_buffer where code='"+cod+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            rs.next();
            if(rs.getInt("1")==1)
            {
                return true;
            }
            return false;
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return false;
    }

    public static void remove_database(String cod)
    {
        String SQL1 = "delete from order_history where code='"+cod+"'";
        String SQL2 = "delete from adress where code='"+cod+"'";
        String SQL3 = "delete from adressprov where code='"+cod+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            stmt1.execute(SQL1);
            stmt2.execute(SQL2);
            stmt3.execute(SQL3);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void remove_buffer_database(String cod)
    {
        String SQL1 = "delete from order_buffer where code='"+cod+"'";
        String SQL2 = "delete from adress where code='"+cod+"'";
        String SQL3 = "delete from adressprov where code='"+cod+"'";
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            stmt1.execute(SQL1);
            stmt2.execute(SQL2);
            stmt3.execute(SQL3);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static ArrayList<String> view_history(String user)
    {
        String SQL1 = "select * from order_history where name='"+user+"'";
        String SQL2 = "select * from adress where name='"+user+"'";
        String SQL3 = "select * from adressprov where name='"+user+"'";
        ArrayList<String> valori = new ArrayList<String>();
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            ResultSet rs1 = stmt1.executeQuery(SQL1);
            ResultSet rs2 = stmt2.executeQuery(SQL2);
            ResultSet rs3 = stmt3.executeQuery(SQL3);
            while(rs1.next() && rs2.next() && rs3.next())
            {   
                Order ord = new Order(rs1.getString("name"),rs1.getString("code"),rs1.getString("oname"),rs1.getString("qtype"),rs1.getInt("quantity"),rs1.getBoolean("fragile"),rs1.getBoolean("alcohol"),rs1.getBoolean("electronic"),rs1.getBoolean("consumption"));

               String rez = ord.JFieldString() + "\n" + rs1.getString("date");
               valori.add(rez);
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return valori;
    }

    public static String view_order(String code)
    {
        String SQL1 = "select * from order_buffer where code='"+code+"'";
        String SQL2 = "select * from adress where code='"+code+"'";
        String SQL3 = "select * from adressprov where code='"+code+"'";
        String rez = "";
       
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            ResultSet rs1 = stmt1.executeQuery(SQL1);
            ResultSet rs2 = stmt2.executeQuery(SQL2);
            ResultSet rs3 = stmt3.executeQuery(SQL3);
            while(rs1.next() && rs2.next() && rs3.next())
            {   
                Order ord = new Order(rs1.getString("name"),rs1.getString("code"),rs1.getString("oname"),rs1.getString("qtype"),rs1.getInt("quantity"),rs1.getBoolean("fragile"),rs1.getBoolean("alcohol"),rs1.getBoolean("electronic"),rs1.getBoolean("consumption"));
                
                GroupAdress gr = new GroupAdress(GroupAdress.view_adress(ord.code).provenienta,GroupAdress.view_adress(ord.code).destinatie);

                Adress dest = gr.destinatie;
                Adress prov = gr.provenienta;

                Order ord2 = new Order(rs1.getString("name"),rs1.getString("code"),rs1.getString("oname"),dest,prov,rs1.getString("qtype"),rs1.getInt("quantity"),rs1.getBoolean("fragile"),rs1.getBoolean("alcohol"),rs1.getBoolean("electronic"),rs1.getBoolean("consumption"));

                rez = ord2.JFieldString() + "\n" + rs1.getString("date");
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return rez;
    }

    public static String view_order_history(String code)
    {
        String SQL1 = "select * from order_history where code='"+code+"'";
        String SQL2 = "select * from adress where code='"+code+"'";
        String SQL3 = "select * from adressprov where code='"+code+"'";
        String rez = "";
       
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt1 = con.createStatement();
            Statement stmt2 = con.createStatement();
            Statement stmt3 = con.createStatement();
            ResultSet rs1 = stmt1.executeQuery(SQL1);
            ResultSet rs2 = stmt2.executeQuery(SQL2);
            ResultSet rs3 = stmt3.executeQuery(SQL3);
            while(rs1.next() && rs2.next() && rs3.next())
            {   
                Order ord = new Order(rs1.getString("name"),rs1.getString("code"),rs1.getString("oname"),rs1.getString("qtype"),rs1.getInt("quantity"),rs1.getBoolean("fragile"),rs1.getBoolean("alcohol"),rs1.getBoolean("electronic"),rs1.getBoolean("consumption"));
                
                GroupAdress gr = new GroupAdress(GroupAdress.view_adress(ord.code).provenienta,GroupAdress.view_adress(ord.code).destinatie);

                Adress dest = gr.destinatie;
                Adress prov = gr.provenienta;

                Order ord2 = new Order(rs1.getString("name"),rs1.getString("code"),rs1.getString("oname"),dest,prov,rs1.getString("qtype"),rs1.getInt("quantity"),rs1.getBoolean("fragile"),rs1.getBoolean("alcohol"),rs1.getBoolean("electronic"),rs1.getBoolean("consumption"));

                rez = ord2.JFieldString() + "\n" + rs1.getString("date");
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return rez;
    }


    public static ArrayList<String>  view_database_manager()
    {
        String SQL1 = "select name,code,oname,qtype,quantity from order_history";
        ArrayList<String> valori = new ArrayList<String>();
        try
        {
            Connection con = DriverManager.getConnection(Data.url);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(SQL1);
            while(rs.next())
            {   
                valori.add("User:" + rs.getNString("name")+" Code:" + rs.getNString("code")+" Order:" + rs.getNString("oname")+" Quantity:"+rs.getNString("quantity")+rs.getNString("qtype"));
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        return valori;
    }

   

    public String toString()
    {
        //return "ANGAJAT: " + this.getUsername() + "\nCOD: " + this.getCode() + " PRODUS:" + this.getName() + " CANTITATE" + "("+ this.getQuantity_type()+"):" + this.getQuantity() + "\nFRAGIL:" + this.getFragile() + " ALCOOL:" + this.getAlcohol() + " ELECTRONIC:" + this.getElectronic() + " CONSUM:" + this.getConsumption() + "\n\nDESTINATIE\n" + this.getDestination().toString() + "\n\nPROVENIENTA\n" + this.getProvenience().toString(); 
        return "ANGAJAT: " + this.username + " COD: " + this.code + "   NUME: "+this.name+ " CANTITATE: " + this.quantity  + " " + this.quantity_type;

    }

    public String JLiString()
    {   
        //return "ANGAJAT: " + this.getUsername() + "\nCOD: " + this.getCode() + " PRODUS:" + this.getName() + " CANTITATE" + "("+ this.getQuantity_type()+"):" + this.getQuantity() + "\nFRAGIL:" + this.getFragile() + " ALCOOL:" + this.getAlcohol() + " ELECTRONIC:" + this.getElectronic() + " CONSUM:" + this.getConsumption() + "\n\nDESTINATIE\n" + this.getDestination().toString() + "\n\nPROVENIENTA\n" + this.getProvenience().toString();
        return "ANGAJAT: " + this.username + " COD: " + this.code + "   NUME: "+this.name+ " CANTITATE: " + this.quantity  + " " + this.quantity_type;
    }
                                               
    public String JFieldString()
    {
        return "ANGAJAT: " + this.username + "\nCOD: " + this.code + "\nPRODUS: " + this.name + "\nCANTITATE" + "("+ this.quantity_type+"): " + this.quantity + "\nFRAGIL:" + this.fragile + "\nALCOOL:" + this.alcohol + "\nELECTRONIC:" + this.electronic + "\nCONSUM:" + this.consumption + "\n\nDESTINATIE\n" + this.destination.toString() + "\n\nPROVENIENTA\n" + this.provenience.toString() ;
        
    }
    
 

}