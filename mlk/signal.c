#include "syscall.h"
void main()
{
    int p;

    p = spawn("./wait.so");
    while (1)
    {
        mlk_sleep(1);// on attends 5 seconde avant d'envoyer le message
        mlk_send("Coucouccccc",17,p);
        //mlk_sleep(1);
        //mlk_sleep(1);
    }
}