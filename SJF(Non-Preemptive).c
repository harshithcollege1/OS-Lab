#include <stdio.h>
int main() {
    int n, i, j, pos;
    int at[10], bt[10], ct[10], tat[10],dum[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Arrival time for P%d :",(i+1));
        scanf("%d",&at[i]);
        printf("Burst time for P%d :",(i+1));
        scanf("%d",&bt[i]);
        dum[i] = bt[i];
    }
    int time = 0, completed = 0, min;
    while(completed < n) {
        min = 9999;
        pos = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && bt[i] < min && bt[i] > 0) {
                min = bt[i];
                pos = i;
            }
        }
        if(pos == -1) {
            time++;
        } else {
            ct[pos] = time + bt[pos];
            tat[pos] = ct[pos] - at[pos];
            time += bt[pos];
            bt[pos] = 0;
            completed++;
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i],dum[i],ct[i] ,tat[i]);
    }
    return 0;
}
