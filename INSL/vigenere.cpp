// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> vignere(26, vector<char> (26, 'A'));

void preprocess(string &plaintext){
    for (auto& x : plaintext) {
        x = toupper(x);
    }
}

void makeTable(vector<vector<char>> &vignere){
    for(int i=0; i<26;i++){
        for(int j=0; j<26;j++){
            vignere[i][j]=(i+j)%26 + 'A';
            cout<<vignere[i][j]<<" ";
        }
        cout<<endl;
    }
}

void encrypt(string &plaintext, string key, string &ciphertext){
    int keyP=0;
    for(int i=0; i<plaintext.size();i++){
        char c=plaintext[i];
        char kc = key[keyP];
        keyP=(keyP+1)%(key.size());
        ciphertext+=(vignere[kc-'A'][c-'A']);
    }
    cout<<endl<<"Cipher text : ";
    cout<<ciphertext;
}

void decrypt(string &plaintext, string key, string &ciphertext){
    int keyP=0;
    plaintext="";
    for(int i=0; i<ciphertext.size();i++){
        char c=(ciphertext[i]-key[keyP]+26)%26;
        
        keyP=(keyP+1)%(key.size());
        plaintext+=c+'A';
    }
    cout<<endl<<"Plaintext : ";
    cout<<plaintext;
}

int main() {
    string key, plaintext, ciphertext;
    cout<<"Table : "<<endl;
    makeTable(vignere);
    cout<<"Enter key : ";
    cin>>key;
    cout<<"Enter plaintext : ";
    cin>>plaintext;
    preprocess(key);
    preprocess(plaintext);
    
    encrypt(plaintext, key,ciphertext);
    decrypt(plaintext, key, ciphertext);
    
    return 0;
}
