package app;

public class Avion_calatori extends Avion
{
    private int numar_maxim_pasageri;

    public Avion_calatori(){}

    public Avion_calatori(int numar_maxim_pasageri)
    {
        this.numar_maxim_pasageri=numar_maxim_pasageri;
    }

    public void set_nr_max_pasageri(int x)
    {
        numar_maxim_pasageri=x;
    }

    public int get_nr_max_pasageri()
    {
        return numar_maxim_pasageri;
    }

    

}

class Boeing extends Avion_calatori
{
    public Boeing(int numar_maxim_pasageri,int putere,String indicator_avion)
    {
        super(numar_maxim_pasageri);
        this.set_putere(putere);
        this.set_indicator_avion(indicator_avion);
    }
    
    public String toString()
    {
        return "Indicator avion: " + this.get_indicator_avion() + " Putere: " + this.get_putere() + " Numar de pasageri: " + this.get_nr_max_pasageri();
    } 
}

class Concorde extends Avion_calatori
{
    public Concorde(int numar_maxim_pasageri,int putere,String indicator_avion)
    {
        super(numar_maxim_pasageri);
        this.set_putere(putere);
        this.set_indicator_avion(indicator_avion);
    }

    public String toString()
    {
        return "Indicator avion: " + this.get_indicator_avion() + " Putere: " + this.get_putere() + " Numar de pasageri: " + this.get_nr_max_pasageri();
    }
}



