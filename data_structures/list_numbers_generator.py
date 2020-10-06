import random

def random_number_500_1000():
    x=random.randint(500,1000)
    return x

def random_number_3_6():
    y=random.randint(3,7)
    return y

def random_number_1_100000():
    numere_nesortate=random.randint(1,100000)
    return numere_nesortate

with open("C:\\Users\\peria\\Desktop\\lista_aproape_sortata.txt","a") as fisier:
    
    contor_randuri=0
    contor_random=0
    contor_serie=0
    
    limita_random=random_number_500_1000()

    for i in range(1,100000):
        fisier.write(str(i))
        contor_random+=1
        fisier.write(",")
        
        if contor_random==limita_random:  
            serie_numere=random.randint(3,7)
            contor_random=0
            contor_serie=0
            limita_random=random.randint(500,1000)

            while contor_serie<serie_numere:
                contor_serie+=1
                fisier.write(str(random.randint(1,100000)))
                fisier.write(",")
                contor_randuri+=1
                
        
        contor_randuri+=1
        if contor_randuri>=30:
            contor_randuri=0
            fisier.write("\n")
print("gata")


