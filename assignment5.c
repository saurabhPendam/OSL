#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool issafe(int p, int r, int pc, int c, int allocated[p][r], int available[r], int need[p][r], int safeseq[p], int com[p])
{
    while (pc != p)
    {
        for (int i = 0; i < p; i++)
        {
            c += 1;
            if (com[i] != 1)
            {
                int ar = 0;
                for (int j = 0; j < r; j++)
                {
                    if (available[j] < need[i][j])
                    {
                        break;
                    }
                    else

                    {
                        ar += 1;
                    }
                }
                if (ar == r)
                {
                    safeseq[pc] = i + 1;
                    com[i] = 1;
                    pc += 1;
                    for (int j = 0; j < r; j++)
                    {
                        available[j] += allocated[i][j];
                    }
                    c = 0;
                }
            }
        }
        if (c == p)
        {
            break;
        }
    }
    if (pc != p && c == p)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int p, r;
    printf("\n Banker's Algorithm \n");
    printf("\nEnter the number of processes : ");
    scanf("%d", &p);
    printf("\nEnter the number of resources : ");
    scanf("%d", &r);
    int allocated[p][r];
    int max[p][r];
    int need[p][r];
    int available[r];
    int com[p];
    int safeseq[p];
    int pc = 0;
    int c = 0;
    for (int i = 0; i < p; i++)
    {
        com[i] = 0;
    }
    printf("\n\nEnter the allocated matrix for each process : \n");
    for (int i = 0; i < p; i++)
    {
        printf("Enter the allocated matrix for process P%d : ", (i + 1));
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &allocated[i][j]);
        }
    }
    printf("\n\nEnter the max matrix for each process : \n");
    for (int i = 0; i < p; i++)
    {
        printf("Enter the max matrix for process P%d : ", (i + 1));
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    printf("\n\nEnter the availble resources : ");
    for (int i = 0; i < r; i++)

    {
        scanf("%d", &available[i]);
    }
    printf("\n\nProcess\t Allocation\tMax\t Need \tAvailable\n");
    for (int i = 0; i < p; i++)
    {
        printf(" P%d\t ", (i + 1));
        for (int j = 0; j < r; j++)
        {
            printf("%d ", allocated[i][j]);
        }
        printf("");
        for (int j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf(" ");
        for (int j = 0; j < r; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf(" ");
        if (i == 0)
        {
            for (int j = 0; j < r; j++)
            {
                printf("%d ", available[j]);
            }
        }
        printf("\n");
    }
    if (issafe(p, r, pc, c, allocated, available, need, safeseq, com))
    {
        printf("\n\nThe system is safe. The safe sequence is :");
        for (int i = 0; i < p; i++)

        {
            printf(" P%d", safeseq[i]);
            if (i != p - 1)
            {
                printf(" > ");
            }
        }
        printf("\n");
    }
    else
    {
        printf("\n\nThe system is not safe.\n\n");
        printf("\n\nProgram exited successfully.\n\n");
        exit(0);
    }
    int ch;
    printf("\n\nDo you want to make an additional request for resources?(1=Yes|0=No)");
    scanf("%d", &ch);
    if (ch == 0)
    {
        printf("\n\nProgram exited successfully.\n\n");
        exit(0);
    }
    int req[r];
    int pno;
    printf("\nEnter the number of the process that needs more resources: P");
    scanf("%d", &pno);
    printf("\n\nEnter the addititonal request of resources for processP%d : ", pno);
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &req[i]);
    }
    for (int i = 0; i < r; i++)

    {
        if (req[i] > need[pno][i])
        {
            printf("\n\nExceeding the max allocation for process P%d!", pno);
            printf("\nNot a good request.");
            printf("\n\nProgram exited successfully.\n\n");
            exit(0);
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (req[i] > available[i])
        {
            printf("\n\nExceeding the available resources !");
            printf("\nNot a good request.");
            printf("\n\nProgram exited successfully.\n\n");
            exit(0);
        }
    }
    for (int i = 0; i < r; i++)
    {
        available[i] -= req[i];
        allocated[pno][i] += req[i];
        need[pno][i] -= req[i];
    }
    if (issafe(p, r, pc, c, allocated, available, need, safeseq, com))
    {
        printf("\n\nThe requested resources can be allocated to the process.\nThe system is safe. The safe sequence is :");
        for (int i = 0; i < p; i++)
        {
            printf(" P%d", safeseq[i]);
            if (i != p - 1)
            {
                printf(" > ");
            }
        }
    }
    else
    {
        printf("\n\nThe requested resources cannot be allocated to the process.\nThe system is not safe.");
    }
    printf("\n\nProgram exited successfully\n\n");
    return 0;
}