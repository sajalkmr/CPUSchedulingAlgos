#include <stdio.h>
void main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f\n", tatavg / n);
}

/*output
 *
 Enter the number of processes -- 4

Enter Burst Time for Process 0 -- 5

Enter Burst Time for Process 1 -- 6

Enter Burst Time for Process 2 -- 3

Enter Burst Time for Process 3 -- 4
         PROCESS        BURST TIME       WAITING TIME    TURNAROUND TIME

         P0              5               0               5
         P1              6               5               11
         P2              3               11              14
         P3              4               14              18
Average Waiting Time -- 7.500000
Average Turnaround Time -- 12.000000 */
