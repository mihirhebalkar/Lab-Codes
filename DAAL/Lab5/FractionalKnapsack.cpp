#include<bits/stdc++.h>

using namespace std;

struct Item{
    int value;
    int weight;
};

class S {
    
    public:
        bool static comp(Item a, Item b){
            double r1 = (double) a.value/ (double) a.weight;
            double r2 = (double) b.value/(double) b.weight;
            
            return r1>r2;
        }
        
        
        double fk(int W, Item arr[], int n){
            sort(arr, arr+n, comp);
            
            int curWeight = 0;
            double final = 0.0;
            
            for(int i=0; i<n; i++){
                if(curWeight + arr[i].weight<=W){
                    curWeight += arr[i].weight;
                    final += arr[i].value;
                }
                else{
                    int remain = W - curWeight;
                    final += (double) arr[i].value * (double) remain/ (double) arr[i].weight;
                    break;
                }
            }
            return final;
        }
    
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   S obj;
   double ans = obj.fk(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
