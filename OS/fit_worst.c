#include<stdio.h>
#include<stdlib.h>
#define max 25

int main(){
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    printf("\t\t********WORST FIT********\n\n");

    printf("ENTER NO. OF BLOCKS: ");
    scanf("%d", &nb);

    printf("ENTER THE NO. OF FILES: ");
    scanf("%d", &nf);

    printf("ENTER THE SIZE OF BLOCKS: \n");
    for(i = 1; i <= nb; i++){
        printf("Block %d: ", i);
        scanf("%d",&b[i]);
    }

    printf("ENTER THE SIZE OF FILES: \n");
    for(i = 1; i <= nf; i++){
        printf("FILE: %d: ", i);
        scanf("%d",&f[i]);
    }

    for(i = 1; i <= nf; i++){
        for(j = 1; j <= nb; j++){
            if(bf[j] != 1){
                temp = b[j] - f[i];

                if(temp >= 0){
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    printf("\nFILE_NO\tFILE_SIZE\tBLOCK_NO\tBLOCK_SIZE\tFRAGMENT");
    for(i = 1; i <= nf; i++){
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d \n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }

    return 0;
}