#include <stdio.h>
int main() {
    int at[10], bt[10], rt[10], ct[10], wt[10], tat[10];
    int n, i, time = 0, remain, min, shortest;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    for(int i=0;i<n;i++){
        printf("Arrival time for P%d :",(i+1));
        scanf("%d",&at[i]);
        printf("Burst time for P%d :",(i+1));
        scanf("%d",&bt[i]);
    }
    while(remain != 0) {
        min = 9999;
        shortest = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }
        if(shortest == -1) {
            time++;
            continue;
        }
        rt[shortest]--;
        if(rt[shortest] == 0) {
            remain--;
            ct[shortest] = time + 1;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
        time++;
    }
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}
