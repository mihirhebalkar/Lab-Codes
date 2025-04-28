#include <iostream>
#include <cmath>
using namespace std;


long long powerMod(long long base, long long power, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (power > 0) {
        if (power % 2 == 1)
            result = (result * base) % mod;
        
        power = power >> 1;
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    long long p, g; 
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter primitive root g: ";
    cin >> g;

    long long a, b; 
    cout << "Enter private key for User A: ";
    cin >> a;
    cout << "Enter private key for User B: ";
    cin >> b;

   
    long long A = powerMod(g, a, p); 
    long long B = powerMod(g, b, p); 

    cout << "\nPublic key of User A: " << A << endl;
    cout << "Public key of User B: " << B << endl;


    long long keyA = powerMod(B, a, p); 
    long long keyB = powerMod(A, b, p); 

    cout << "\nShared Secret Key computed by User A: " << keyA << endl;
    cout << "Shared Secret Key computed by User B: " << keyB << endl;

    if (keyA == keyB) {
        cout << "\nKey Exchange Successful! Shared Secret Key = " << keyA << endl;
    } else {
        cout << "\nKey Exchange Failed!" << endl;
    }

    return 0;
}
