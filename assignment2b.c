// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <string.h>
// void merge(int arr[], int p, int q, int r)
// {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     int L[n1], M[n2];
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[p + i];
//     for (int j = 0; j < n2; j++)
//         M[j] = arr[q + 1 + j];
//     int i, j, k;
//     i = 0;
//     j = 0;
//     k = p;
//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= M[j])
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = M[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1)
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         arr[k] = M[j];
//         j++;
//         k++;
//     }
// }
// void mergeSort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int m = l + (r - l) / 2;
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }
// }
// void sort_array(int argc, char *arr[], int *integer_array)
// {
//     for (int i = 0; i < argc; i++)
//     {
//         *(integer_array + i) = atoi(arr[i]);
//     }
//     mergeSort(integer_array, 0, argc - 1);
// }
// int main(int argc, char *argv[])
// {
//     int *a;
//     char **arr;
//     if (argc <= 1)
//     {
//         printf("\nPROVIDE ELEMENTS OF ARRAY AS ARGUMENTS...!!\n\n");
//     }
//     else
//     {
//         a = (int *)malloc(argc * sizeof(int));
//         arr = malloc(argc * sizeof(char *));
//         for (int i = 0; i < argc; i++)
//         {
//             arr[i] = malloc(10 * sizeof(char));
//         }
//         printf("SORTING IN PROGRESS...!!\n");
//         sort_array(argc, argv, a);
//         for (int i = 0; i < argc; i++)
//         {
//             sprintf(*(arr + i), "%d", *(a + i));
//         }
//         printf("\nPASSING SORTED ARRAY TO CHILD PROCESS\n\n");
//         execve("./child", arr, NULL);
//     }
// }

// Child
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
int binary_search(int argument_count, char *argument_array[],
                  int *integer_array, int key)
{
    for (int i = 0; i < argument_count; i++)
    {
        *(integer_array + i) = atoi(argument_array[i]);
    }
    return binarySearch(integer_array, 0, argument_count, key);
}
int main(int argc, char *argv[], char *envp[])
{
    int count = 0, i = 0;
    int ele;
    int *integer_array = (int *)malloc(argc * sizeof(int));
    printf("\nCHILD PROCESS START\n");

    printf("SORTED ARRAY: ");
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "0") == 0 && count < 1)
        {
            count++;
            continue;
        }
        else
            printf("%s ", argv[i]);
    }
    printf("\nENTER ELEMENT TO FIND: ");
    scanf("%d", &ele);
    printf("\n\nAPPLYING BINARY SEARCH FOR ELEMENT %d..!!\n\n",
           ele);
    int result = binary_search(argc, argv, integer_array, ele);
    if (result != -1)
    {
        printf("ELEMENT FOUND AT %d INDEX\n", result);
    }
    else
        printf("ELEMENT NOT FOUND...!!\n");

    printf("\nCHILD PROCESS EXITED..!!\n");
}