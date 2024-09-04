#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partitionPivotisFirst(int arr[], int low, int high){
    
    int pivot=arr[low];
    int i=low, j=high;
    
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        } //till we find element greater than pivot
        
        while(arr[j]>=pivot && j>low){
            j--;
        } //till we find element smaller than pivot
        
        if(i<j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);  //putting pivot to its pos
    
    return j;
    
}

int partitionPivotisLast(int arr[], int low, int high){
    
    int pivot = arr[high];
    int i=low;
    
    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]); //putting pivot to its position
    
    return i;
}


void quickSort(int arr[], int low, int high){
    if(low<high){
        
        // int pi = partitionPivotisLast(arr, low, high);
        int pi = partitionPivotisFirst(arr, low, high);
        
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }    
}


int main() {
    
    int arr[6]= {10,2,5,3,1,8};
    
    quickSort(arr,0,5);
    
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
