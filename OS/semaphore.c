#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

void producer();
void consumer();
int wait(int);
int signal(int);

int main(){
    int n, ch;
    printf("\n1.PRODUCER \n2. CONSUMER \n3.EXIT \n");
    while(1){
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : if((mutex == 1) && (empty != 0))
                producer();
                
                else
                printf("\n BUFFER IS FULL \n");
                break;

            case 2 : if((mutex == 1) && (full != 0))
                consumer();

                else
                printf("\n BUFFER IS EMPTY \n");
                break;
            
            case 3  : exit(0);
                break;        
        }
    }
    return 0;
}

int wait(int s){
    return(--s);
}

int signal(int s){
    return(++s);
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nPRODUCER PRODUCES AN ITEM %d\n",x);
    mutex=signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nCONSUMER CONSUMES AN ITEM %d\n",x);
    x--;
    mutex = signal(mutex);
}
