package app;

public class ContBancar
{
    String numarCont;
    double suma;

public ContBancar()
{

}
public ContBancar(String x,double y)
{
    numarCont=x;
    suma=y;
}
public String get_numarCont()
{
    return this.numarCont;
}

public double get_suma()
{
    return this.suma;
}

public void set_numarCont(String x)
{
    this.numarCont=x;
}
public void set_suma(double x)
{
    this.suma=x;
}
public String toString(ContBancar x)
{
    return "cont: " + x.numarCont + " suma: " + x.suma;
}



}

public class ContBancar implements Operatiuni
{
    public getDobanda()
    {
        if(numarCont.contains("EURO"))
            {
                return suma + 0.1;
            }
        else
            {
                if(suma<500)
                {
                    return suma*0.3;
                }
                else
                    {
                        return suma*0.8;
                    }
            }
    }

    public getSumaTotala()
    {
        return suma + getDobanda;
    }

    public void depunere(double suma)
    {
        this.suma +=suma;
    }

    public void extragere(double suma)
    {
        this.suma -=suma;
    }

    public void transfer(ContBancar cb ,double suma)
    {
        this.extragere(suma);
        cb.depunere(suma);
    }
}