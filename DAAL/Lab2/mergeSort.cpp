#include <iostream>

using namespace std;


void merge(int A[], int low, int mid, int high){
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    
    int mid= (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    
    merge(arr,low,mid,high);
}



int main() {
    
    int arr[5]={45,50,15,35,64};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr,0,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
