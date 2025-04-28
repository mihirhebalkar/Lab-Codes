#include <iostream>
#include <cmath>
using namespace std;

// Function to compute (base^exp) % mod
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while(exp>0){
        if(exp%2==1){
            result = (result*base)%mod;
        }
        exp=exp/2;
        base = (base*base)%mod;
    }
    return result;
}

// Function to compute modular inverse
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    int p = 3, q = 11;
    int n = p * q; // n = 33
    int phi = (p - 1) * (q - 1); // phi = 20
    int e = 7; // Public key exponent

    // Find private key (d)
    int d = modInverse(e, phi);

    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;

    int message;
    cout << "\nEnter the message (number) to encrypt (0 < message < " << n << "): ";
    cin >> message;

    // Encryption
    int cipher = powerMod(message, e, n);
    cout << "Encrypted Cipher Text: " << cipher << endl;

    // Decryption
    int decryptedMessage = powerMod(cipher, d, n);
    cout << "Decrypted Plain Text Message: " << decryptedMessage << endl;

    return 0;
}
