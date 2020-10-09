package bec_comenzi;

import java.io.IOException;

class Meniu 
{
    final static void menu(Bec buffer[]) throws IOException
    {
        CLS.clrscr();
        System.out.println("1. Vizualizare comenzi in desfasurare");
        System.out.println("2. Vizualizare baze de date (periculos) nu merge momentan");
        System.out.println("3. Adaugare comanda");
        System.out.println("4. Completare comanda");
        System.out.println("5. Stergere comanda in desfasurare");
        System.out.print("Introduceti un numar: ");
        int optiune = Input.integer();

        if(optiune == 1)
        {
            CLS.clrscr();
            Print.print_buffer(buffer);
            System.out.println("Apasati 'enter' pentru a reveni in meniu.");
            Input.wait_enter();
        }

        else if(optiune == 2)
        {
            System.out.println("aici trebe ceva functie");
        }

        else if(optiune == 3)
        {
            CLS.clrscr();
            Bec.add_buffer2(buffer);
            System.out.println("");
            System.out.println("Comanda a fost inregistrata cu succes!");
            System.out.println("Apasati 'enter' pentru a revenii in meniu.");
            Input.wait_enter();
        }  

        else if(optiune == 4)
        {
            if(!Database.csv_exist("C:\\Onedrive\\Desktop\\bec_comenzi.csv"))
            {
                Database.create_csv("C:\\Onedrive\\Desktop\\bec_comenzi.csv");
                System.out.println("\n" + "A fost creata baza de date!" + "\n");
                Input.wait_enter();
                menu(buffer);
            }
        
            else
            {   
                System.out.println("\n" + "Baza de date exista." + "\n");
                System.out.print("Introduceti codul comenzii: ");
                String codu = Input.string();
                Bec x = Bec.find(buffer,codu);

                if(x.nr_bucati == 0)
                {   
                    CLS.clrscr();
                    System.out.println("Comanda nu a fost gasita!");
                    Input.wait_enter();
                    Meniu.menu(buffer);
                }

                Database.add_order(x);
                x.remove_buffer(buffer);
                System.out.print("\n" + "Comanda a fost adaugata in baza de date!");
                Input.wait_enter();
                menu(buffer);
            }
        }

        else if(optiune == 5)
        {
            CLS.clrscr();
            System.out.println("Introduceti codul unic: ");

            String cod = Input.string();

            for(int i=0;i<buffer.length;i++)
            {
                if(buffer[i] == null)
                {
                    continue;
                }

                if((buffer[i].cod_unic).equals(cod))
                {
                    System.out.println("Comanda a fost stearsa!");
                    Print.print_bec(buffer[i]);
                    buffer[i].remove_buffer(buffer);
                    Input.wait_enter();
                    CLS.clrscr();
                    break;
                }   
            }
        }
    menu(buffer);
    }
}
