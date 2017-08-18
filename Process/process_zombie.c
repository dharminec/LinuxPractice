#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
int n;
char *message;

void print_child()
{
    for(; n > 0; n--) {
        printf("the child message is: %s\n",message);
        sleep(1);
    }

}

void print_parent()
{
    for(; n > 0; n--) {
        printf("the parent message is: %s\n",message);
        sleep(1);
    }
    

}

int main()
{
    pid_t pid;
    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        n = 5;
        message = "This is the child";
        print_child();
        break;
    default:
        n = 3;
        message = "This is the parent";
        print_parent();
        while(1);
        break;
    }
printf("i am %s is exiting\n",pid==0?"child":"parent");
exit(0);
}
