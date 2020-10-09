package app;
import java.util.Random;

final class Data
{
    String[] CARTI;

    Data(String n)
    {
        String[] c = {"UNU","DOI","TREI","PATRU","CINCI","SASE","SAPTE","OPT","NOUA","ZERO",n};
        this.CARTI = c;
    }
}

class Card
{
    String carte;

    void print_card()
    {
        System.out.print(this.carte + " ");
    }

    Card(String n)
    {
        Data data = new Data(n);
        Random rand = new Random();
        this.carte = data.CARTI[rand.nextInt(11)];
    }
    
}