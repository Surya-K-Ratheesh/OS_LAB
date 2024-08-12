#include<stdio.h>
#include<stdlib.h>

int main(){
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("ENTER THE NO OF PROCESSES: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p[i] = i;
        printf("ENTER BURST TIME OF PROCESS %d: ",i);
        scanf("%d",&bt[i]);
    }

    for(i = 0; i < n; i++){
        for(k = i+1; k < n; k++){
            if(bt[i] > bt[k]){
                temp = bt[i];
                bt[i] = bt[k];
                bt[k]= temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 0; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i]; 
    }

    printf("\tPROCESS \tBURST TIME \tWAITING TIME \tTURN AROUND TIME\n");
    for(i = 0; i < n; i++){
        printf("\n\t P%d \t\t%d \t\t%d \t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n");
    printf("\nAVERAGE WAITING TIME = %f\n",wtavg);
    printf("\nAVERAGE TURN AROUND TIME = %f\n",tatavg);

    return 0;
}