#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
pthread_mutex_t lock;
int Var = 0;

void *thread_function2(void *arg) {

        while (1) {
             sleep(1);
             pthread_mutex_lock(&lock); // if lock ==1 wait otherwise lock it and make it to 1
	     Var++;
             pthread_mutex_unlock(&lock); // make it to zero
	     printf("I am in Thread2 Var = %d\n", Var);
        }
	pthread_exit("Exit from Thread\n");
}

void *thread_function1(void *arg) {
        while (1) {
             sleep(1);
             pthread_mutex_lock(&lock);
	     Var++;
             pthread_mutex_unlock(&lock);
	     printf("I am in Thread1 Var = %d\n", Var);
        }
	pthread_exit("Exit from Thread\n");
}

int main() {
        int i = 0;
	int res;
	pthread_t a_thread1;
        pthread_t a_thread2;
	void *thread_result;
        pthread_mutex_init(&lock,0);
	res = pthread_create(&a_thread1, NULL, thread_function1, (void *)0);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}


        res = pthread_create(&a_thread2, NULL, thread_function2, (void *)0);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	while(1);
	exit(EXIT_SUCCESS);
}

