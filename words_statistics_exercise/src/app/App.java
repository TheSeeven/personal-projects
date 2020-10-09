package app;



public class App 
{
    
    public static void main(String[] args)  
    {
        StringBuffer temp = new StringBuffer();        
        
        StringBuffer[] propozitii = new StringBuffer[Functii.count_phrase(args[0])];
        int contor_propozitii = 0;

        int[] nr_unice_propozitii = new int[propozitii.length];

        System.out.println("Textul dat ca parametru este: \n");
        System.out.println(args[0]);


        System.out.println("\n\n\n");
        System.out.println("Textul in lista: \n");

        for(int i=0;i<args[0].length();i++)
        {
            if(Functii.end_phrase(args[0].charAt(i)))
            {
                if(temp.charAt(0) == ' ')
                {
                    temp.deleteCharAt(0);
                    temp.trimToSize();
                }
                propozitii[contor_propozitii] = temp;
                temp = new StringBuffer();
                contor_propozitii++;
            }

            else if(args[0].charAt(i) != ',')
            {
                temp.append(args[0].charAt(i));
            }
        }

        System.out.println("\n\n\n");
        System.out.println("Cuvinte distincte:\n");
        
        for(int i=0;i<propozitii.length;i++)
        {
            Functii.cuvinte_unice(propozitii[i]);
            System.out.println("");   
        }

        System.out.println("\n\n\n");
        System.out.println("Statistica cuvinte:\n");

        for(int i=0;i<propozitii.length;i++)
        {
            Functii.statistica(propozitii[i]);
            System.out.println("");   
        }

        System.out.println("\n");
        System.out.println("Textul fara re:" + "\n");

        StringBuffer[] text_re = Functii.eliminare_re(args);

        for(StringBuffer i:text_re)
        {
            System.out.print(i + " ");
        }

        System.out.println("\n\n\n");
        System.out.println("Numar cuvinte unice propozitii:\n");

        for(int i=0;i<propozitii.length;i++)
        {
            nr_unice_propozitii[i] = Functii.count_words(propozitii[i]);
        }

        System.out.println("Cuvinte unice / propozitie:");

        Propozitie[] arr = new Propozitie[nr_unice_propozitii.length];

        for(int i=0;i<nr_unice_propozitii.length;i++)
        {
            arr[i] = new Propozitie(i, nr_unice_propozitii[i]);
        }

        for(Propozitie i:arr)
        {
            i.print();
        }

        System.out.println("\nDupa sortare: \n");
        
        Functii.sort(arr);

        for(Propozitie i:arr)
        {
            i.print();
        }

    }
}