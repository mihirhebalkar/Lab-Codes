#include <iostream>
using namespace std;

int recLinear(int arr[], int cur, int n, int key){
    
    if(cur>n){
        return -1;
    }
    else if(arr[cur]==key) {
        return cur;
    }
    return recLinear(arr, cur+1, n, key); 
}

int main() {
    int arr[5]= {1,4,8,3,2};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    int z=recLinear(arr,0,n,0);
    
    if(z==-1){
        cout<<"Element not Present in array";
    }
    else{
        cout<<"index = "<<z;
    }
}
