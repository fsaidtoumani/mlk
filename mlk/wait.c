#include "syscall.h"
void main()
{
    int i = 1;
    while (i)
    {
        char *buf;
        char *str = "Hello World";
        mlk_print("***|J'atteneds un message|***\n");
        mlk_wait(); //On attend qu'un processus nous envoie un message
        mlk_print("J'ai recu un message\n");
        mlk_recv(buf, 12);
        mlk_print(buf);
        mlk_sleep(1);
    }
}