package app;

public class Propozitie
{
    int numar_propozitie;
    int numar_cuvinte_unice;

    Propozitie(int numar_propozitie,int numar_cuvinte_unice)
    {
        this.numar_propozitie=numar_propozitie+1;
        this.numar_cuvinte_unice=numar_cuvinte_unice;
    }

    public void print()
    {
        System.out.println("Propozitia: " + this.numar_propozitie + " are: " + this.numar_cuvinte_unice);
    }


}