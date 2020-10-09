package app;

public interface Operatiuni
{
    public double getSumaTotala();
    public double getDobanda();
    public void depunere(double suma);
    public void extragere(double suma);
    public void transfer(ContBancar cb,double s);
}


    