#include<stdio.h>
#include<stdlib.h>

int main(){
    int queue[100], n, head, i, j, seek = 0, diff;
    float avg;

    printf("\t\t********FCFS DISK SCHEDULING********\n\n");

    printf("ENTER THE NO. OF REQUESTS: ");
    scanf("%d", &n);

    printf("ENTER THE REQUEST SEQUENCE: ");
    for(i = 1; i <= n; i++){
        scanf("%d", &queue[i]);
    }

    printf("ENTER THE INITIAL HEAD POSITION: ");
    scanf("%d", &head);

    for(j = 0; j < n; j++){
        diff = abs(queue[j+1] - queue[j]);
        seek += diff;
        printf("MOVE FROM %d TO %d WITH SEEK %d \n", queue[j], queue[j+1], diff);
    }

    printf("\nTOTAL SEEK TIME = %d \n", seek);
    avg = (float)seek / n;
    printf("AVERAGE SEEK TIME IS %.2f \n", avg);

    return 0;
}