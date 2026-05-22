#include <stdio.h>

int main() {
    int n = 5, m = 3;
    int i, j, k;

    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,3},
        {2,1,1},
        {0,0,2}
    };

    int request[5][3] = {
        {0,0,0},
        {2,0,2},
        {0,0,0},
        {1,0,0},
        {0,0,2}
    };

    int avail[3] = {0,0,0};

    int finish[5] = {0};

    // Mark processes with no allocation as finished
    for(i = 0; i < n; i++) {
        int sum = 0;

        for(j = 0; j < m; j++)
            sum += alloc[i][j];

        if(sum == 0)
            finish[i] = 1;
    }

    // Deadlock Detection
    for(k = 0; k < n; k++) {

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int flag = 1;

                for(j = 0; j < m; j++) {

                    if(request[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {

                    for(j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = 1;
                }
            }
        }
    }

    // Check deadlock
    int deadlock = 0;

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {
            deadlock = 1;
            printf("Process P%d is in Deadlock\n", i);
        }
    }

    if(deadlock == 0)
        printf("No Deadlock Detected\n");

    return 0;
}
