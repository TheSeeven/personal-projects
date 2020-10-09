package app;


public class Persoana
{
    String nume;
    String prenume;
    int varsta;
    int inaltime;
    public void setvarsta(int varsta)
    {
        this.varsta=varsta;
    }
    public void setinaltime(int inaltime)
    {
        this.inaltime=inaltime;
    }
    public int getvarsta()
    {
        return this.varsta;
    }
    public Integer getinaltime()
    {
        return this.inaltime;
    }
    public Persoana()
    {}

    public Persoana(String n , String p, int v, int i) throws Exception
    {
        nume=n;
        prenume=p;
        if(v>0)
        {
            varsta=v;
        }
        else
        {
            throw new Exception("varsta trebuie > 0");
        }
        inaltime=i;
    }
    public String toString()
    {
        return nume + " " + prenume + " " + varsta + " " + inaltime;
    }
}