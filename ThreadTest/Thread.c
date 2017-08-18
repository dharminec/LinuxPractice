#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *thread_function(void *arg);
char message[] = "Hello World";
int run = 1;
int main() {
        int i = 0;
	int res;
	pthread_t a_thread1;
        pthread_t a_thread2;
	void *thread_result;
	res = pthread_create(&a_thread1, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}


        res = pthread_create(&a_thread2, NULL, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}


        while (i<10) {
            i++;
            printf("i am in main process\n");
            sleep(1);
        }
        run =0;
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread1, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %s\n", (char *)thread_result);
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	strcpy(message, "Bye!");
        while (run) {
	     printf("thread_function is running. Argument was %s\n", (char *)arg);
             sleep(1);
        }
	pthread_exit("Exit from Thread\n");
}
