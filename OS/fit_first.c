#include<stdio.h>
#include<stdlib.h>
#define max 25

int main(){
    int frag[max], b[max], f[max], i, j, temp, nb, nf, highest = 0;
    static int bf[max], ff[max];

    printf("MEMORY MANAGEMENT SCHEME - FIRST FIT \n");
    printf("ENTER NO OF BLOCKS: ");
    scanf("%d",&nb);

    printf("ENTER NO OF FILES: ");
    scanf("%d",&nf);

    printf("ENTER SIZE OF BLOCKS: ");
    for(i = 1; i <= nb; i++){
        printf("BLOCK %d: ", i);
        scanf("%d",&b[i]);
        bf[i] = 0;
    } 

    printf("ENTER SIZE OF FILES: ");
    for(i = 1; i <= nf; i++){
        printf("FILE %d: ",i);
        scanf("%d",&f[i]);
    }

    for(i = 1; i <= nf; i++){
        for(j = 1; j<= nb; j++){
            if (bf[j] != 1){
                temp = b[j] - f[i];
                if(temp >= 0)
                    if(highest < temp){
                        ff[i] = j;
                        highest = temp;
                    } 
                    
   
                }
            }
            frag[i] = highest;
            bf[ff[i]] = 1;
            highest = 0;
        
        // printf("FILE %d ",i);
        // scanf("%d",&f[i]);
    }

    // for(i = 1; i <= nf; i++){
    //     for(j = 1; j <= nb; j++){
    //         if(bf[j] != 1){
    //             temp = b[j] - f[i];
    //             if(temp >= 0){
    //                 if(highest < temp){
    //                     ff[i] = j;
    //                     highest = temp;
    //                 }
    //             } 
    //         }
    //     }
    //     frag[i] = highest;
    //     bf[ff[i]] = 1;
    //     highest = 0;
    // }

    printf("FILE NO: \t FILE SIZE: \t BLOCK NO: \tBLOCK SIZE: \tFRAGMENT");
    for(i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i, f[i], ff[i], b[ff[i]], frag[i]);
    

    return 0;
}