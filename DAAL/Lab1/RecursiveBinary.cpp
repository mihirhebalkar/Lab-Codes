#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recBinary(int arr[], int low, int high, int key){
    
    if(low<=high){
        int mid=(low+high)/2;  //low + (high-low)/2 to avoid overflow
        
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return recBinary(arr,low,mid-1,key);
        }
        else {
            return recBinary(arr, mid+1, high, key);
        }
    }
    return -1; //if statement always returns something so
                //control never reaches here if element is present
}

int main() {
    int arr[5]= {1,24,8,13,25};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    
    int z=recBinary(arr,0,n,8);
    
    if(z==-1){
        cout<<"Element not Present in array";
    }
    else{
        cout<<"index = "<<z;
    }
}
