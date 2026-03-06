#include <stdio.h>
int main(){
    int n;
    printf("Enter no.of p's :");
    scanf("%d",&n);
    int at[n],bt[n],ct[n];
    for(int i=0;i<n;i++){
        printf("Arrival time for P%d :",(i+1));
        scanf("%d",&at[i]);
        printf("Burst time for P%d :",(i+1));
        scanf("%d",&bt[i]);
    }
    ct[0] = at[0]+bt[0];
    for(int i=1;i<n;i++){
        if(at[i-1]>at[i]){
            ct[i] = bt[i]-at[i];
        }
        ct[i] = ct[i-1] + bt[i];
    }
    printf("Process\tAT\tBT\tCT\t\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",(i+1),at[i],bt[i],ct[i]);
    }
    return 0;
}