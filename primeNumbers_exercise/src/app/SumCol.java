package app;

class SumCol
{
    int suma;
    int coloana;

    SumCol(int suma,int coloana)
    {
        this.suma = suma;
        this.coloana = coloana + 1;
    }

    void print_sumcol()
    {
        System.out.println("Coloana " + this.coloana + " are suma cifrelor " + this.suma);
    }

}