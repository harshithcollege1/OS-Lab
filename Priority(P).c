#include <stdio.h>
int main() {
    int n, i, time = 0, count = 0;
    int bt[10], at[10], pr[10];
    int rt[10], wt[10], tat[10], ct[10];
    int highest, min_pr;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }
    while(count < n) {
        highest = -1;
        min_pr = 9999;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                highest = i;
                }
            }
            if(highest == -1) {
                time++;
            }
            else {
                rt[highest]--;
                time++;

            if(rt[highest] == 0) {
                count++;
                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];
                }
            }
    }
    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }
    return 0;
}
