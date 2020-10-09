package app;

public class Cuvant
{
    public String x;

    public Cuvant(StringBuffer x)
    {
        this.x=x.toString();
    }

    public void print()
    {
        System.out.print(x + " ");
    }
}