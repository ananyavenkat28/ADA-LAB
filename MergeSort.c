#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i=l, j=m+1, k=l;
    int temp[10000];

    while(i<=m && j<=r)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m)
        temp[k++] = arr[i++];

    while(j<=r)
        temp[k++] = arr[j++];

    for(i=l;i<=r;i++)
        arr[i] = temp[i];
}

void mergesort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main()
{
    int n,i,arr[10000];
    clock_t start,end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    /* generate random numbers */
    for(i=0;i<n;i++)
        arr[i] = rand()%1000;

    printf("Generated random numbers:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    start = clock();

    mergesort(arr,0,n-1);

    end = clock();

    time_taken = ((double)(end-start)*1000.0)/CLOCKS_PER_SEC;

    printf("\n\nSorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n\nExecution Time = %f seconds\n",time_taken);

    return 0;
}
