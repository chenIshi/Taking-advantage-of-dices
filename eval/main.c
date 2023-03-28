#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX(A,B) ((A)>(B)?(A):(B))

#define GROUPLIMITS 20
#define DICEMAXIMUM 20
#define EVAL_ITER 10000

int main() {
    srand(32);

    /* Expectation for maximum in multitple rounds of dice rolling*/
    /* Dice: d20
       Round each time: 10000
       Grouping: 1~20 */
    int expects[GROUPLIMITS] = {0};
    int tmps[GROUPLIMITS]={0};
    int pts[EVAL_ITER][GROUPLIMITS]={0};
    /* 1. Generates GROUPLIMITS * EVAL_ITER times of rand nums.
       2. Each group iterates through EVAL_ITER round of experiments, ignoring redundant nums.
          e.g., Group 2 would only consider the first two nums in each iteration, ignoring 
          the other (GROUPLIMITS-2) nums. 
       3. I take an equivalant impl to opt out unecessary ops: since the num series is identical
          to each group, we can simply overlay previous comparsion to latter ones.
       4. tmps records the max value within each round */
    for (int i=0; i<EVAL_ITER; i++) {
        for (int j=0; j<GROUPLIMITS; j++) {
            int num = rand() % DICEMAXIMUM + 1;
            if (j>0) {
                tmps[j] = MAX(tmps[j-1], num);
            } else {
                tmps[j] = num;
            }
            pts[i][j] = tmps[j];
            expects[j] += tmps[j];
        }
        memset(tmps, 0, sizeof(tmps));
    }
    /*
    for (int j=0; j<GROUPLIMITS; j++) {
        printf("%f\n", (float)expects[j]/EVAL_ITER);
    }
    */

    /* Output results in points */
    FILE *fptr;
    fptr = fopen("./pts.txt","w");

    if(!fptr) {
        printf("Error in creating file handler!");   
        exit(1);
    }
/*
    fprintf(fptr, "1");
    for (int j=1; j<GROUPLIMITS; j++) {
        fprintf(fptr, " %d", j+1);
    }
    
    fprintf(fptr, "\n");
*/
    for (int i=0; i<EVAL_ITER; i++) {
        fprintf(fptr, "%d", pts[i][0]);
        for (int j=1; j<GROUPLIMITS; j++) {
            fprintf(fptr, " %d", pts[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);

    return 0;
}