package app;

import gui.Data;

import java.sql.Connection;
import java.sql.DriverManager;

import java.sql.SQLException;


public class App {
    public static void main(String[] args) throws SQLException 
    {
        Data.set_path();
        Connection con =DriverManager.getConnection(Data.url);
        Functions.create_tables();
        
        gui.login window = new gui.login();
        window.frmOrderManagement.setVisible(true);
    }
}