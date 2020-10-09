package gui;

import java.nio.file.Path;
import java.nio.file.Paths;

public final class Data
{
    public static String username = new String("");
    public static String functie = new String("");
    public static String url = "jdbc:derby:C:\\Users\\peria\\Desktop\\D;";

    public static void set_path()
    {
        System.out.println(url);
        String x = "\\";
        String y = "\\\\";
        Path currentRelativePath = Paths.get("");
        String s = currentRelativePath.toAbsolutePath().toString().replace(x,y) + "\\DB";

        System.out.println("Current relative path is: " + s);

        url = "jdbc:derby:" + s +";create=true;user=metalica;password=themetalicarules666";
    }
}