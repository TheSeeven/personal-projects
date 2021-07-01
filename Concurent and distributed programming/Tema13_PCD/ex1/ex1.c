#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/select.h>
#include <unistd.h>
#define BUFSIZE 256
int main ()
{
    fd_set readset; 
    struct timespec timeout;
    char buf_cit[BUFSIZE];
    int result;
    int readFile;
    while( 1 )
    {
        fprintf(stderr, "---------CICLU infinit cu select (se iese cu <ctrl>/c)----------\n");
        FD_ZERO(&readset);
        FD_SET(STDIN_FILENO, &readset); 
        timeout.tv_sec = 10;
        timeout.tv_nsec = 0;
        fprintf(stderr, "Urmeza SELECT pentru testarea unui canal ready/ se asteapta: %ld sec.\n",
        timeout.tv_sec);
        result = pselect(1, &readset, NULL, NULL, &timeout,NULL);
        if(result==0)
        {
            fprintf(stderr, "Timeout %ld secunde\n",timeout.tv_sec+10);
        };
        fprintf(stderr, "Valoare returnata de functia select: %d\n", result);
        if (FD_ISSET(STDIN_FILENO, &readset))
        {
            fprintf(stderr, "+++ STANDART INPUT este ready --- \n");
            readFile= read(STDIN_FILENO, buf_cit, BUFSIZE);
            buf_cit[readFile]= '\0';
            fprintf(stderr, "ai tastat: "); fprintf(stderr, "%s", buf_cit);fprintf(stderr, "\n");
        }
    } 
}