#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int counter;

void sig_handler (int signo)
{
    if (signo == SIGUSR1)
    {
        printf("Die Konfiguration wurde neu geladen.\n");
    }
    if (signo == SIGINT) 
    {
        counter += 1;
        printf("Anzahl geklickte Strg+C: %d\n", counter);
    }
}

int main (void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR || signal(SIGINT, sig_handler) == SIG_ERR)
    {
        printf("Ich kann kein Signal empfangen\n");
    }

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}