package app;

public class App 
{
    public static void main(String[] args) // args[0] = 5 , args[1] = 20
    {
        Player[] player = new Player[Integer.parseInt(args[0])];

        for(int i=0;i<player.length;i++)
        {
            player[i] = new Player((Integer.parseInt(args[1])/player.length)+1);
        }

        Pachet pachet = new Pachet(Integer.parseInt(args[1]),args[2]);

        int contor_carti = 0;
        int contor_player = 0;
        while(contor_carti != Integer.parseInt(args[1]))
        {
            for(int q=0;q<player.length;q++) // itereaza peste playeri
            {
                if(contor_player<Integer.parseInt(args[1])/player.length+1)
                {
                   if(contor_carti < Integer.parseInt(args[1]))
                   {
                        player[q].carti[contor_player]=pachet.pachet[contor_carti];
                        contor_carti++;
                        player[q].numar_carti++;
                   }
                }
            }
            
            contor_player++;
        }

        System.out.println("Pachetul de carti: ");
        
        pachet.print_pachet();

        System.out.println("\n\n");

        for(int i=0;i<player.length;i++)
        {
            player[i].print_player(i);
        }

        System.out.println("\n");

        for(int i=0;i<player.length;i++)
        {
            if(player[i].winner(i,args[2])){
            break;}
        }
        
        System.out.println("\n");

    }
}