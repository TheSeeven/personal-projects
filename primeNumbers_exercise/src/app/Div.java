package app;

class Coordonate
{
    int x;
    int y;

    Coordonate(int x , int y)
    {
        this.x = x+1;
        this.y = y+1;
    }

    void print_coord()
    {
        System.out.println("Linie: " + this.x + " Coloana: " + this.y);
    }
}

class Div
{
    int numar;
    Coordonate coordonate;

    Div(int numar,int x, int y)
    {
        this.numar=numar;
        coordonate = new Coordonate(x,y);
    }

    void print_div()
    {
        System.out.println("Numarul " + this.numar + " se afla la coordonatele " + " x=" + this.get_x() + " y=" + this.get_y());
    }

    int get_x()
    {
        return this.coordonate.x;
    }

    
    int get_y()
    {
        return this.coordonate.y;
    }
}