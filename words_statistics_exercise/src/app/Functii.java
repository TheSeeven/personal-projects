package app;

public class Functii
{
    static void sort(Propozitie[] x)
    {
        Propozitie temp;
        boolean sortat=false;
        while(!sortat)
        {
            sortat = true;
            for(int i=0;i<x.length-1;i++)
            {
                if(x[i].numar_cuvinte_unice>x[i+1].numar_cuvinte_unice)
                {
                    temp = x[i];
                    x[i] = x[i+1];
                    x[i+1] = temp;
                    sortat=false;
                }
            }
        }
    }

    static boolean end_phrase(String s)
    {
        if(s==".")
        {
            return true;
        }
        return false;
    }

    static boolean end_phrase(char s)
    {
        if(s=='.')
        {
            return true;
        }
        return false;
    }


    static boolean is_space(char x)
    { 
        if(x==' ')
        {
            return true;
        }
        return false;      
    }

    static int count_words(StringBuffer x)
    {
        int contor=1;
       
        for(int i=0;i<x.length();i++)
        {
            if(is_space(x.charAt(i)))
            {
                contor++;
            }
        }
        return contor;
    }
    static int count_words(String x)
    {
        int contor=1;
       
        for(int i=0;i<x.length();i++)
        {
            if(is_space(x.charAt(i)))
            {
                contor++;
            }
        }
        return contor;
    }

    static int count_phrase(String x)
    {
        int contor=0;
       
        for(int i=0;i<x.length();i++)
        {
            if(end_phrase(x.charAt(i)))
            {
                contor++;
            }
        }
        return contor;
    }

    static void cuvinte_unice(StringBuffer x)
    {
        StringBuffer temp = new StringBuffer();
                                                                                                    //StringBuffer[] temp = new StringBuffer[count_words(x)];
        Cuvant[] rez = new Cuvant[count_words(x)];

        int contor = 0;

        for(int i=0;i<x.length();i++)
        {
            if(is_space(x.charAt(i)) || i == x.length())
            {
                rez[contor] = new Cuvant(temp);
                contor++;
                temp.delete(0, temp.length());
            }
            else
            {
                temp.append(x.charAt(i));
            }
        }
        rez[contor] = new Cuvant(temp);

        for(int i=0;i<rez.length-1;i++)
        {
            if(rez[i] != null)
            {
                for(int j=i+1;j<rez.length;j++)
                {
                    if(rez[j]!=null)
                    {
                        if(rez[i].x.toString().equalsIgnoreCase(rez[j].x.toString()))
                        {
                            rez[j]=null;
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<rez.length;i++)
        {
            if(rez[i]!=null)
            {
                rez[i].print();
            }
        }
    }

    static boolean in_list(Statistica[] arr,int x)
    {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]!=null)
            {
                if(arr[i].numar_litere == x)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    static StringBuffer[] eliminare_re(String[] x)
    {
        String text = x[0];
        StringBuffer[] lista_cuvinte = new StringBuffer[count_words(text)];
        int contor_lista = 0;

        for(int i=0;i<text.length();i++)
        {
            if(is_space(text.charAt(i)))
            {
                contor_lista++;
            }
            else
            {
                if(lista_cuvinte[contor_lista] == null)
                {
                    lista_cuvinte[contor_lista] = new StringBuffer();
                }
                lista_cuvinte[contor_lista].append(text.charAt(i));
            }
        } 

        for(int i=0;i<lista_cuvinte.length;i++)
        {
            if(lista_cuvinte[i].indexOf("re")>-1)
            {
                lista_cuvinte[i]=null;
            }
        }
        return lista_cuvinte;
        
    }

    static void statistica(StringBuffer rand)
    {
        Statistica[] arr = new Statistica[count_words(rand)];
        int contor_statistica = 0;
            int nr_litere=0;
            for(int j=0;j<rand.length();j++)
            {
                if(is_space(rand.charAt(j)) || j == rand.length()-1)
                {
                    if(j == rand.length()-1)
                    {
                        nr_litere++;
                    }

                    if(!in_list(arr,nr_litere))
                    {
                        arr[contor_statistica] = new Statistica(nr_litere);
                        nr_litere=0;
                        contor_statistica++;
                    }
                    
                    else if(in_list(arr,nr_litere))
                    {
                        for(int i=0;i<arr.length;i++)
                        {
                            if(arr[i].numar_litere == nr_litere)
                            {
                                nr_litere=0;
                                arr[i].frecventa++;
                                break;
                            }
                        }  
                    }      
                }

                else if(!is_space(rand.charAt(j)))
                {
                    nr_litere++;
                }
            }   
        
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]!=null)
            {
                arr[i].print();
            }
        }  
    }
}