// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Series{
  int n;
  
  public:
    Series(int num)
    {
        int z,i,sum=0;
        for(i=0;i<num;i++)
        {
            z=z*10 + 9;
            sum+=z;
            cout<<z<<endl;
        }
        cout<<"Sum is "<<sum;
    }
};


int main() {
    
    Series s(4);

    
}
