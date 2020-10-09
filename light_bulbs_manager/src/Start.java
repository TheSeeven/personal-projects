package bec_comenzi;

import java.io.IOException;

public class Start {
    public static void main(String[] args)
            throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException {
        Bec buffer[] = new Bec[50];
        Meniu.menu(buffer);
    }
}
