package bec_comenzi;
import java.util.Random;

class Code_Generator
{
    final static String unique_code_generator()
    {
        String ALPHA_NUMERIC = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890";
        StringBuilder cod = new StringBuilder();


        Random random = new Random();

        while(cod.length()<15)
        {
            int random_integer = random.nextInt(36);
            cod.append(ALPHA_NUMERIC.charAt(random_integer));
        }

        String cod_return = cod.toString();
        return cod_return;
    }
}