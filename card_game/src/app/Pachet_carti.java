package app;

class Pachet
{
    Card[] pachet;

    void print_pachet()
    {
        int contor_randuri = 1;
        for(int i=0;i<this.pachet.length;i++)
        {   
            this.pachet[i].print_card();
            contor_randuri++;
            if(contor_randuri == 10)
            {
                System.out.println("");
                contor_randuri = 0;
            }
        }
    }

    Pachet(int n,String tinta)
    {
        this.pachet = new Card[n];
        boolean carte_tinta = false;
        for(int i=0;i<pachet.length;i++)
            {
                if(carte_tinta == false)
                {
                    pachet[i] = new Card(tinta);
                    if(pachet[i].carte == tinta)
                        {
                            carte_tinta = true;
                        }
                }
                else
                    {
                        pachet[i] = new Card(tinta);
                        while(pachet[i].carte == tinta)
                        {
                            pachet[i] = new Card(tinta);
                        }
                    }
            }
    }
}