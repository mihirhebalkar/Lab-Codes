#include <iostream>
#include <vector>
using namespace std;


// Function to compute modular inverse of a under modulo m
long long modInverse(long long a, long long m) {
    a = a % m;
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to solve a system of congruences using CRT
long long chineseRemainder(vector<int> num, vector<int> rem) {
    long long prod = 1;
    int n = num.size();
    
    for (int i = 0; i < n; i++)
        prod *= num[i];
    
    long long result = 0;

    for (int i = 0; i < n; i++) {
        long long pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    
    return result % prod;
}

int main() {
    int n;
    cout << "Enter the number of congruences: ";
    cin >> n;
    int prod = 1;

    vector<int> num(n), rem(n);
    cout << "Enter the divisors (mod values):\n";
    for (int i = 0; i < n; i++) {
        cout << "m " << i + 1 << ": ";
        cin >> num[i];
        prod*=num[i];
    }
    
    cout<<"\nM = "<<prod<<endl;

    cout << "Enter the corresponding remainders:\n";
    for (int i = 0; i < n; i++) {
        cout << "a " << i + 1 << ": ";
        cin >> rem[i];
    }

    cout << "\nSolving the system..." << endl;

    long long solution = chineseRemainder(num, rem);
    
    cout << "\nThe solution x is: " << solution << endl;

    return 0;
}
