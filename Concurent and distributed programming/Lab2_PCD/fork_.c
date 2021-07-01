/*****************************************************************************
 * FISIER: fork_.c
 *****************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// MACRO tipvar() de determinare tip variabila
// Cuvantul cheie _Generic in C este utilizat pentru a defini un MACRO pentru diferitele tipuri de data.
// Aceast nou cuvant cheie a fost adaugat in limbajul de programare C o data cu lansarea standardului C11.
#define tipvar(X) _Generic((X), int                    \
                           : "int", long               \
                           : "long", short             \
                           : "short",                  \
                             long long                 \
                           : "long long", unsigned int \
                           : "unsigned int", default   \
                           : "necunoscut")
int main(int argc, char **argv)
{
    /**
 pid_t este o data tip integer definita in sys/types.h
 uid_t este o data tip integer definita in sys/types.h
 gid_t este o data tip integer definita in sys/types.h
**/
    pid_t pidt;
    uid_t uidt;
    gid_t gidt;
    pid_t childpid;
    printf("\nTipurile de data pid_t, uid_t si gid_t sunt definite in sys/types.h\n");
    // printf("%d\n", _Generic( 1.0L, float:1, double:2,
    // long double: 3, default:0)); // exemplu utilizare _Generic()
    printf("\tpid_t --- size %d \t type %s\n", sizeof(getpid()), tipvar(pidt));
    printf("\tuid_t --- size %d \t type %s\n", sizeof(getuid()), tipvar(uidt));
    printf("\tgid_t --- size %d \t type %s\n", sizeof(getgid()), tipvar(gidt));
    if ((childpid = fork()) == 0) // creare proces copil
                                  // raspunsul functiei fork()
                                  // =0 proces copil
                                  // >0 proces parinte (PID proces copil creat)
                                  // =-1 fork() esuat
    {
        /* COD PROCES COPIL RULAT IN SPATIUL DE ADRESE COPIL */
        // \n = enter
        // \t = tab
        // \ = continuare instr. pe linia urmatoare
        printf("\nSunt copilul, \
 \n\tam ProcessID (PID) = %d, parintele meu are ParentPID (PPID) =%d, \
 \n\tCopilul meu are ChildPID = %d, \
 \n\tProprietarul meu (UID) este=%u, \
 \n\tUtilizator efectiv (EUID) este: %u, \
 \n\tGrupul din care fac parte (GID) este: %u, \
 \n\tGrup efectiv (EGID)= %u\n",

               (int)getpid(), (int)getppid(), (int)childpid,
               (unsigned int)getuid(), (unsigned int)geteuid(),
               (unsigned int)getgid(), (unsigned int)getegid()); // a se urmari tipul de data comparativ la parinte
    }
    else if (childpid > 0)
    {
        /* COD PROCES PARINTE RULAT IN SPATIUL DE ADRESE PARINTE */
        printf("\nSunt parintele, \
 \n\tam ProcessID (PID) = %d, parintele meu are ParentPID (PPID) = %d, \
 \n\tCopilul meu are ChildPID=%d, \
 \n\tProprietarul meu (UID) este=%u, \
 \n\tUtilizator efectiv (EUID) este: %u, \
 \n\tGrupul din care fac parte (GID) este: %u, \
 \n\tGrup efectiv (EGID)= %u \n",
               (pid_t)getpid(), (pid_t)getppid(), childpid,
               (uid_t)getuid(), (uid_t)geteuid(),
               (gid_t)getgid(), (gid_t)getegid()); // a se urmari tipul de data comparativ la copil
    }
    /* cod comun proces parinte/copil*/
    /* rulat insa in spatii de memorie diferite: spatiul de adrese parinte respectiv copil */
    printf("\n\tCod rulat in parinte/copil. PID= %d , PPID= %d --- terminat\n",
           (pid_t)getpid(), (pid_t)getppid());
    return 0; // term proces parinte/copil
}