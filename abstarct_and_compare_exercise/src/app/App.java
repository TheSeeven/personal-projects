package app;
import java.util.Arrays;
import java.util.Comparator;

public class App 
{
    static Comparator<Persoana> sortare = new Comparator<Persoana>() {

        public int compare(Persoana o1, Persoana o2) {
            if (o1.getvarsta() > o2.getvarsta()) {
                return 1;
            } else {
                return -1;
            }
        }

    };

    public static void main(String[] args) throws Exception {
        Persoana[] sir = new Persoana[3];
        sir[0] = new Persoana("Ion", "Popescu", 23, 145);
        sir[1] = new Persoana("Gerorge", "Vasilescu", 45, 184);
        sir[2] = new Persoana("hsdjas", "asdlescu", 666, 7765);

        System.out.println(sir[0]);

        Arrays.sort(sir, sortare);
        

    }
}