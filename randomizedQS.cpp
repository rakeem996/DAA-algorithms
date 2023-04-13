#include <iostream>
// #include <cstdlib>
#include <time.h>
using namespace std;

int partition(int arr[] , int low , int high)
{
    int pivot = arr[low];
    int i = low , j=high;
    while(i < j)
    {
        while(arr[i] <= pivot && i< high) i++;

        while(arr[j] >= pivot && j>low ) j--;

        if(i < j) swap(arr[i] , arr[j]);
    }

    swap(arr[low] , arr[j]);

    return j;
}

int r_partition(int arr[] , int low , int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[low] , arr[random]);

    return partition(arr , low , high);
}

void quickSort(int arr[] , int low , int high)
{
    if(low<high)
    {
        int pi = r_partition(arr , low , high);

        quickSort(arr, low , pi-1);
        quickSort(arr, pi+1 , high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
     
    return 0;
}