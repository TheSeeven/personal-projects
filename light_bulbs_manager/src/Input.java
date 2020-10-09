package bec_comenzi;

import java.util.Scanner;

@SuppressWarnings({ "resource" })




class Input
{
    final static String string()
    {
        Scanner input = new Scanner(System.in);
        String string = input.next();
        return string;
    }

    final static int integer()
    {
        Scanner input = new Scanner(System.in);
        int integer = input.nextInt();
        return integer;
    }

    final static void wait_enter()
    {
        Scanner input = new Scanner(System.in);
        String string = input.nextLine();
    }

}