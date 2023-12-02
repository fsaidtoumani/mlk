#include <signal.h>
#include <unistd.h>

struct SCC { // System Call Context
        int number;
        union {
                char * s;
                int i;

        } u;
        int result;
        int p; // processus qui recoit le message
}; // process fill a SCC struct and set pointer before syscall

typedef struct SCC scc_t;

#ifdef MY_LITLE_KERNEL
extern scc_t * system_call_ctx; // process fill a SCC struct and set pointer before syscall
#else
extern scc_t * system_call_ctx; // process fill a SCC struct and set pointer before syscall

scc_t scc;

int spawn(char *c) {
        scc.number=1;
        scc.u.s=c;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_clock() {
        scc.number=2;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_sleep(int s) {
        scc.number=3;
        scc.u.i=s;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_getpid() {
        scc.number=4;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_print(char *c){
        scc.number=5;
        scc.u.s=c;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;        
}

int mlk_wait(){
        scc.number=6;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;        
}

int mlk_signal(int p){
        scc.number=7;
        scc.u.i=p;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;        
}
//Envoie le message mesg de longueur l  au processus p
int mlk_send(void *mesg,int l, int p){
        scc.number=8;
        scc.u.i=l;
        scc.u.s=(char *)mesg;
        scc.p=p;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;        
}

//recupere le message de longueur maximale l dans buff. Retourne le nombre d'octets reçu.
int mlk_recv(void *buff,int l){
        scc.number=9;
        scc.u.i=l;
        scc.u.s=(char *)buff;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;        
}
#endif
