#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Function to compute (base^exp) % mod
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, x; // p: prime, g: primitive root, x: private key
    cout << "Enter a prime number (p): ";
    cin >> p;
    cout << "Enter a primitive root modulo p (g): ";
    cin >> g;
    cout << "Enter private key (x): ";
    cin >> x;

    // Calculate public key y
    long long y = powerMod(g, x, p);
    cout << "\nPublic key (y): " << y << endl;

    // Encryption
    long long m;
    cout << "\nEnter the message (number < p) to encrypt: ";
    cin >> m;

    long long k;
    cout << "Enter a random number k (1 < k < p-1): ";
    cin >> k;

    long long c1 = powerMod(g, k, p);
    long long c2 = (m * powerMod(y, k, p)) % p;

    cout << "\nCiphertext: (c1, c2) = (" << c1 << ", " << c2 << ")\n";

    // Decryption
    long long s = powerMod(c1, x, p);
    long long s_inv = powerMod(s, p - 2, p); // modular inverse using Fermat's Little Theorem
    long long decrypted = (c2 * s_inv) % p;

    cout << "\nDecrypted Message: " << decrypted << endl;

    return 0;
}
