package app;

public class Statistica
{
    public int numar_litere;
    public int frecventa;

    Statistica()
    {
        this.frecventa=1;
    }

    Statistica(int numar_litere)
    {
        this.numar_litere=numar_litere;
        this.frecventa=1;
    }

    public void print()
    {
        System.out.println("Numar_litere: " + this.numar_litere + " Frecventa: " + this.frecventa);
    }
}