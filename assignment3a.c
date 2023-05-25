#include <stdio.h>

int main()
{
    int arr_time[10], burst_time[10], temp[10]; 
    int i, smallest, count = 0, time, n;
    double wait_time = 0, turnaround_time = 0, end;
    float avg_waiting_time, avg_turnaround_time;
    printf("\nEnter the Total Number of Processes: \t");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes \n", n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time: \t");
        scanf("%d", &arr_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (arr_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0)
        {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arr_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arr_time[smallest];
        }
    }
    avg_waiting_time = wait_time / n;
    avg_turnaround_time = turnaround_time / n;
    printf("\nAverage Waiting Time:%lfn", avg_waiting_time);
    printf("Average Turnaround Time:%lfn", avg_turnaround_time);
    return 0;
}
