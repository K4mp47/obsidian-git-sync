Link ai materiali: https://secgroup.dais.unive.it/teaching/laboratorio-sistemi-operativi/

--- 

## Thread POSIX
- I thread POSIX in c sono all'interno della libreria standard

```c
#include<pthread.h>
```

- la libreria permette di creare e sincronizzare i thread

Funzione di creazione di pthread $\downarrow$ 
```c
pthread_create(pthread_t *thread, 
			   pthread_attr_t *attr, 
			   void *(*start_routine)(void *), 
			   void *arg
			)
```

- `*pthread` ==> analogo a pid_t.
- `*attr` ==> attributi del thread per configurarli(null per default values)
- `start_routine` ==> codice eseguito dal thread
	- input = puntatore a void
	- output = puntatore a void
- `*arg` ==> parametri da passare al thread

```c
pthread_exit(
	void *retval
)
```

$\uparrow$ termina l'esecuzione del thread e ritorna retval

```c
pthread_join(pthread_t th, void **thread_return)
```

$\uparrow$ attende la terminazione del thread th, ritorna 0 e un valore al puntatore(se non si vuole un valore di ritorno, `thread_return = NULL --> o non scrivo niente` )

```c
pthread_detach(pthread_t th)
```

$\uparrow$ pone il thread in stato detach, quando non si vuole aspettare il termine del thread

```c
pthread_t pthread_self()
```

$\uparrow$ ritorna l'**ID** del thread.
- **ATTENZIONE**: questo ID dipende dall’implementazione ed è l’ID della libreria phread e non l’ID di sistema. Per visualizzare l’ID di sistema (quello che si osserva con il comando `ps -L`, dove L sta per Lightweight process, ovvero thread) si può usare una syscall specifica di Linux `syscall(SYS_gettid)`.

Esempio di creazione e attesa di un thread. Nel seguente esempio vengono creati due thread che stampano il proprio id, per poi aspettare con `sleep(1)` e terminare. Il thread principale aspetta la loro terminazione.

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

// codice dei thread. Notare che e' una funzione che prende 
// un puntatore e ritorna un puntatore (a void)
void * codice_thread(void * a) {
    pthread_t tid;
    int ptid;
    
    tid  = pthread_self();      // library tid
    ptid = syscall(SYS_gettid); // tid assegnato dal SO (funziona solo in Linux)

    printf("Sono il thread %lu (%i) del processo %i\n",
		    tid,ptid,getpid()
		    );
    sleep(1);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid[2];
    int i,err;

    for (i=0;i<2;i++) {
        if (err=pthread_create(&tid[i],NULL,codice_thread,NULL)) {
            printf("errore create [%i]\n",err);
            exit(EXIT_FAILURE); }
    }
    
    for (i=0;i<2;i++) {
        if (err=pthread_join(tid[i],NULL)) {
            printf("errore join [%i]\n",err);
            exit(EXIT_FAILURE); }
    }
    printf("I thread hanno terminato l'esecuzione correttamente\n");
}
```

```c
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/syscall.h>

void* thread_function(void *a){
	int *num = (int *)a;

	pthread_t tid = pthread_self();
	int ptid = syscall(SYS_gettid);
	
	*num = *num * *num;
	pthread_exit(NULL);
}

int main(int argc, char* argv[]){
	pthread_t tid[2];
	int numbers[2];
	int err;
	
	if (argc < 3){
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i < 2; i++){
		numbers[i] = atoi(argv[i+1]);
		if(err=pthread_create(&tid[i],NULL,thread_function,(void *)&numbers[i])){ 
	      exit(EXIT_FAILURE); 
	    }
	}
	
	for(int i=0; i < 2; i++){
		if(err=pthread_join(tid[i],NULL)) exit(EXIT_FAILURE);
	}
	
	printf("%d + %d = %d\n",numbers[0],numbers[1],numbers[1]+numbers[0]);
}
```

