#include <stdio.h>

int main() {
    int count, n, time = 0, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10];

    printf("ENTER TOTAL NO OF PROCESS: ");
    scanf("%d", &n);
    remain = n;

    for (count = 0; count < n; count++) {
        printf("ENTER ARRIVAL TIME AND BURST TIME OF PROCESS[%d]: ", count + 1);
        scanf("%d%d", &at[count], &bt[count]);
        rt[count] = bt[count];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nPROCESS\t|TURNAROUND TIME |WAITING TIME\n");

    for (time = 0, count = 0; remain != 0;) {
        if (rt[count] <= time_quantum && rt[count] > 0) {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        } 

        else if (rt[count] > 0) {
            rt[count] -= time_quantum;
            time += time_quantum;
        }

        if (rt[count] == 0 && flag == 1) {
            remain--;
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            printf("P(%d)\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            flag = 0;
        }

        if (count == n - 1) {
            count = 0;
        } 

        else if (at[count + 1] <= time) {
            count++;
        } 
        
        else {
            count = 0;
        }
    }

    printf("\nAVG WAITING TIME= %.2f\n", (float)wait_time / n);
    printf("AVG TURNAROUND TIME= %.2f\n", (float)turnaround_time / n);

    return 0;
}