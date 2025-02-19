#include <bits/stdc++.h>
using namespace std;

//calculating e
int gcd(int a, int b){
    if(b==0) return a;
    
    return gcd(b, a % b);
}

int gcde(int totient){ //finding coprime  e not factor of totient
    for(int e=2; e<totient;e++){
        if(gcd(e,totient)==1 && totient%e!=0){
            return e;
        }
    }
    return -1;
}

//calculating d
int modInverse(int e, int totient) {
    for(int d = 2; d < totient; d++) {
        if((e*d) % totient == 1) return d;
    }
    return -1;
}

int power(int m, int e, int n){ //c= (m^e)%n
    
    int c=1;
    for(int i=1;i<=e;i++){
        c=c*m;
    }
    
    return c%n;
}

int encrypt(int m, pair<int, int> pub){
    return power(m, pub.first, pub.second);
}

int decrypt(int m, pair<int, int>pri){
    return power(m, pri.first, pri.second);
}

int main() {
    
    cout << "RSA Implementation"<<endl;
    
    int p=3, q=11;
    
    int n=p*q;
    
    int totient = (p-1)*(q-1);
    
    int e = gcde(totient); //encryption key
    int d = modInverse(e, totient); //decryption key
    // cout<<totient<<" "<<e<<" "<<d<<endl;
    
    pair<int, int> publicK = {e,n};
    pair<int, int> privateK = {d,n};
    
    int m=2;
    cout<<"Plaintext : "<<m<<endl;
    cout<<"Encryption => "<<encrypt(m, publicK)<<endl;
    cout<<"Decryption => "<<decrypt(encrypt(m, publicK), privateK)<<endl;
    return 0;
}

