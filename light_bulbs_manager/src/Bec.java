package bec_comenzi;

public final class Bec {
    final int pret;
    final int nr_bucati;
    final int lumeni;
    final String cod_unic;
    final String brand;
    final String model;
    final String destinatie;
    final String provenienta;

    Bec(int pret, int nr_bucati, int lumeni,String cod_unic, String brand, String model, String destinatie, String provenienta) {
        this.pret=pret;
        this.nr_bucati=nr_bucati;
        this.lumeni=lumeni;
        this.cod_unic=cod_unic;
        this.brand=brand;
        this.model=model;
        this.destinatie=destinatie;
        this.provenienta=provenienta;
    }

    final static void add_buffer2(Bec buffer[])
    {
        System.out.println("Introduceti pretul: ");
        int pret= Input.integer();
        System.out.println("Introduceti numarul de bucati: ");
        int nr_bucati = Input.integer();
        System.out.println("Introduceti numarul de lumeni: ");
        int lumeni = Input.integer();
        String cod_unic=Code_Generator.unique_code_generator();
        System.out.println("Introduceti brandul: ");
        String brand = Input.string();
        System.out.println("Introduceti modelul: ");
        String model = Input.string();
        System.out.println("Introduceti provenienta: ");
        String provenienta = Input.string();
        System.out.println("Introduceti destinatie:");
        String destinatie = Input.string();
        Bec x = new Bec(pret,nr_bucati,lumeni,cod_unic,brand,model,destinatie,provenienta);
        Print.print_bec(x);
        x.add_buffer(buffer);
            
    }

    final void add_buffer(Bec buffer[]) {
        int index = 0;
        for (int i = 0; i < buffer.length; i++) {
            if (buffer[i] == null) {
                index = i;
                buffer[index] = this;
                break;
            } else {
                index = 60;
            }
        }

        if (index == 60) {
            System.out.println("Eliminati din comenzi pentru a adauga alte comenzi.");
        } else {
           // System.out.println("Comanda a fost adaugata in lista de comenzi.\n");
           // this.print_bec();

        }
    }

    final void remove_buffer(Bec buffer[])
    {
        for(int i=0;i<buffer.length;i++)
        {
            if(buffer[i] == null)
            {
                continue;
            }
            else if(buffer[i].cod_unic == this.cod_unic)
            {
                CLS.clrscr();
                System.out.println("Comanda a fost eliminata din lista de comenzi.\n");
                Print.print_bec(this);
                buffer[i]=null;

            }
        }
    }

    final static Bec find(Bec buffer[],String codu) 
    {
        Bec x = new Bec(0,0,0,"none","none","none","none","none");
        
        for(int i=0;i<buffer.length;i++)
        {
            if((buffer[i].cod_unic).equals(codu))
            {
                return buffer[i];
            }
        }  
        return x; 
    }

}
