#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    printf("\t\t********FIFO PAGE REPLACEMENT********\n\n");

    printf("ENTER NO. OF PAGE REFERENCES: ");
    scanf("%d", &n);

    printf("ENTER THE PAGE REFERENCES: ");
    for(i = 0; i < n; i++){
        scanf("%d", &rs[i]);
    }

    printf("ENTER THE NO. OF FRAMES: ");
    scanf("%d", &f);

    // Iniitialize frames to -1.
    for(i = 0; i < f; i++){
        m[i] = -1;
    }

    for(i = 0; i < n; i++){
        for(k = 0; k < f; k++){
            if(m[k] == rs[i]){
                break;
            }
        }

        if (k == f){
            m[count++] = rs[i];
            pf++;
        }

        for(j = 0; j < f; j++){
            if(m[j] != -1){
                printf("\t%d", m[j]);
            }
            else{
                printf("\t-");
            }
        }

        if(k == f){
            printf("\tPF no. %d", pf);
        }

        printf("\n");

        if (count == f){
            count = 0;
        }
    }

    printf("\nTOTAL NO OF PAGE FAULT USING FIFO = %d \n",pf);

    return 0;
}