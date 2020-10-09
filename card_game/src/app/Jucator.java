package app;

class Player
{
    Card[] carti; 
    int numar_carti;  

    Player(int numar_carti)
    {
        this.carti=new Card[numar_carti];
    }

    void print_player(int n)
    {
        System.out.print("Player " + (n+1) + ": ");
        for(int i=0;i<this.numar_carti;i++)
        {
            if(carti[i]!=null)
            {
                System.out.print(carti[i].carte + " ");
            }
        }
        System.out.println(" ");
    }

    boolean winner(int n,String tinta)
    {
        for(int i=0;i<this.carti.length;i++)
        {
            if(this.carti[i] != null)
            {
                if(this.carti[i].carte == tinta)
                {
                    System.out.println("The Player" + (n+1) + " is the winner!");
                    return true;
                }
            }
        }
        return false;
    }
}