#include <stdio.h>

#define MAX_PROCESSES 10

void findTimes(int processes[], int n, int bt[],
               int wt[], int tat[], int ct[], int rt[]) {

    int remaining_bt[MAX_PROCESSES];
    int started[MAX_PROCESSES] = {0};

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
        wt[i] = 0;
        rt[i] = -1;   // response time not set yet
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int min_bt = 9999;
        int shortest = -1;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }

        // First time CPU allocation → response time
        if (!started[shortest]) {
            rt[shortest] = current_time;
            started[shortest] = 1;
        }

        remaining_bt[shortest]--;
        current_time++;

        // Process completed
        if (remaining_bt[shortest] == 0) {
            completed++;
            ct[shortest] = current_time;
            tat[shortest] = ct[shortest];          // arrival time = 0
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }
}

void calculateAverageTimes(int processes[], int n, int bt[]) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int ct[MAX_PROCESSES], rt[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;

    findTimes(processes, n, bt, wt, tat, ct, rt);

    printf("Process\tBT\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i], bt[i], wt[i], tat[i], ct[i], rt[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {6, 8, 7, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n, burst_time);
    return 0;
}

