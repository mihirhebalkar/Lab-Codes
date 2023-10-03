#include <stdio.h>

void Quick(int a[], int low, int high);
int main()
{
    int i, a[50], n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter array elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int s = 0, e = n - 1;
    Quick(a, s, e);
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void Quick(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low]; // Choose the pivot element
        int i = low;   
        int j = high;

        while (i <= j)
        {
            while (a[i]<=pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Place pivot in its correct position
        int temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        // Recursively sort the two sub-arrays
        Quick(a, low, j - 1);
        Quick(a, j + 1, high);
    }
}
