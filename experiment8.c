#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n];
    int ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++) {
        printf("Enter arrival time of process %d:\n", i+1);
        scanf("%d", &at[i]);

        printf("Enter burst time of process %d:\n", i+1);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
    }

    int time = 0;
    int completed = 0;
    int smallest;

    while(completed < n) {

        smallest = -1;

        // Find process with smallest remaining burst time
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rem_bt[i] > 0) {
                if(smallest == -1 || rem_bt[i] < rem_bt[smallest]) {
                    smallest = i;
                }
            }
        }

        if(smallest == -1) {
            time++;   // No process available
        }
        else {
            rem_bt[smallest]--;   // Execute for 1 unit time
            time++;

            if(rem_bt[smallest] == 0) {
                ct[smallest] = time;
                completed++;
            }
        }
    }

    float total_tat = 0, total_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
