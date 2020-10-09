package app;

public class Nava
{
    class Locatie
    {
        int grade_lat;
        int minute_lat;
        int secunde_lat;

        int grade_long;
        int minute_long;
        int secunde_long;

       public Locatie(double latitudine,double longitudinea)
        {
            this.grade_lat=(int)latitudine;
            this.grade_long=(int)longitudinea;

            double temp_min;
            double temp_sec;

            temp_min=(latitudine-(int)latitudine)*60;
            temp_sec=(temp_min-(int)temp_min)*60;

            this.minute_lat=(int)temp_min;
            this.secunde_lat=(int)temp_sec;

            temp_min=(longitudinea-(int)longitudinea)*60;
            temp_sec=(temp_min-(int)temp_min)*60;

            this.minute_long=(int)temp_min;
            this.secunde_long=(int)temp_sec;
        }

        public Locatie(){}

        public String toString()
        {
            return "Latitudine: " + this.grade_lat + " " + this.minute_lat + "' " + this.secunde_lat + "'' " + " Longitudine: " + this.grade_long + " " + this.minute_long + "' " + this.secunde_long + "''";          
        }
    }

    


    private double latitudinea;
    private double longitudinea;

    private String nume;
    private String proprietar;
    private Locatie locatie;

    public Nava(){}
    
    public Nava(double latitudinea,double longitudinea,String nume, String proprietar)
    {
        this.latitudinea=latitudinea;
        this.longitudinea=longitudinea;
        this.nume=nume;
        this.proprietar=proprietar;
        this.locatie = new Locatie(latitudinea,longitudinea);
    }

    public String toString()
    {
        return "Nume: " + this.nume + " Proprietar: " + this.proprietar + " Latitudinea: " + this.latitudinea + " Longitudinea: " + this.longitudinea + " DMS " + locatie.toString(); 
    }

    public String get_proprietar()
    {
        return this.proprietar;
    }   

    public boolean proximitate(Nava n,double raza)
    {
        double distanta;

        distanta = java.lang.Math.sqrt((this.latitudinea - n.latitudinea)*(this.latitudinea - n.latitudinea) + (this.longitudinea - n.longitudinea)*(this.longitudinea - n.longitudinea));
        
        if(distanta <= raza)
        {
            return true;
        }
        return false;
    }

}