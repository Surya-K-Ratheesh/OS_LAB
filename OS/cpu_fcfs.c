#include<stdio.h>
#include<stdlib.h>

int main(){
    int bt[20], wt[20], tat[20], i, n;
    float avgwt = 0, avgtat = 0;

    printf("\t\t********FCFS CPU SCHEDULING********\n\n");

    printf("ENTER THE NO. OF PROCESSES: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("ENTER THE BURST TIME FOR PROCESS %d: ",i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    for(i = 0; i < n; i++){
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\n");

    printf("AVERAGE WAITING TIME = %.2f\n", avgwt);
    printf("AVERAGE TURNAROUND TIME = %.2f\n", avgtat);

    return 0;
}