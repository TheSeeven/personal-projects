package app;

public class App {
    public static void main(String[] args) throws Exception {
      
    Employee[] arr_e1 = new Employee[5];
    Employee[] arr_e2 = new Employee[5];
    arr_e1[0] = new Employee("marcel",true);
    arr_e1[1] = new Employee("gigel",false);
    arr_e1[2] = new Employee("anabalana",false);
    arr_e1[3] = new Employee("racho",false);
    arr_e1[4] = new Employee("nu am idei",false);
    arr_e2[0] = new Employee("marcelica",true);
    arr_e2[1] = new Employee("alex nume da",false);
    arr_e2[2] = new Employee("nume",false);
    arr_e2[3] = new Employee("crstiiiii",false);
    arr_e2[4] = new Employee("plictiseala",false);

    Office[] arr_o1 = new Office[4];
    Office[] arr_o2 = new Office[3];
    arr_o1[0] = new Office(654,true); 
    arr_o1[1] = new Office(657,false); 
    arr_o1[2] = new Office(312,false); 
    arr_o1[3] = new Office(4132,false);
    arr_o2[0] = new Office(545,true); 
    arr_o2[1] = new Office(666,false); 
    arr_o2[2] = new Office(77,false);  
    
    Departament[] arr_d = new Departament[2];
    arr_d[0] = new Departament("Nu am ideeii ",arr_o1,arr_e1);
    arr_d[1] = new Departament("portocaleeeee",arr_o2,arr_e2);

    Company c1 = new Company("gtx1080ti","mypc",arr_d);

    System.out.println(c1.toString());

    }
}