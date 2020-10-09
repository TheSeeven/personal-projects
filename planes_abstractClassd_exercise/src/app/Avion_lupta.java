package app;

public class Avion_lupta extends Avion
{
    public Avion_lupta(){}
}

class Mig extends Avion_lupta
{
    public Mig(int putere,String indicator_avion)
    {
        super();
        this.set_putere(putere);
        this.set_indicator_avion(indicator_avion);
    }

    public String toString()
    {
        return "Indicator avion: " + this.get_indicator_avion() + " Putere: " + this.get_putere();
    }
}

class Tomcat extends Avion_lupta
{
    public Tomcat(int putere,String indicator_avion)
    {
        super();
        this.set_putere(putere);
        this.set_indicator_avion(indicator_avion);
    }

    public String toString()
    {
        return "Indicator avion: " + this.get_indicator_avion() + " Putere: " + this.get_putere();
    }
}   