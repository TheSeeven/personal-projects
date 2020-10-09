package bec_comenzi;

import java.io.IOException;
import java.lang.reflect.Field;

class Print
{
    final static void print_buffer(Bec buffer[]){
        for (int i = 0; i < buffer.length; i++) {
            if (buffer[i] == null) {
                continue;
            } else {
                Print.print_bec(buffer[i]);
                System.out.println();  
            }
        }
    }

    final static void print_bec(Bec bulb) {
        System.out.println("Pret: " + bulb.pret + "\n" + "Numar: " + bulb.nr_bucati + "\n" + "Lumeni: " + bulb.lumeni + "\n" + "Cod Unic: " + bulb.cod_unic +
                "\n" + "Brand: " + bulb.brand + "\n" + "Model: " + bulb.model + "\n" + "Destinatie: "
                + bulb.destinatie + "\n" + "Provenienta: " + bulb.provenienta);
    }

    final static void print_buffer_criteria(Bec buffer[], String criteriu, String valoare)
            throws NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException
             {
        for (int i = 0; i < buffer.length; i++) {
            if (buffer[i] == null) {
                continue;
            } else {
                Object o = buffer[i];
                Class<?> c = buffer[i].getClass();

                Field f = c.getDeclaredField(criteriu);

                Object object = f.get(o);
                String Valoare = (String) (object).toString();
                if (Valoare.equals(valoare)) {
                    Print.print_bec(buffer[i]);
                    Meniu.menu(buffer);
                }
            }
        }
    }
}