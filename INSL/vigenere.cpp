#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> vignere(26, vector<char> (26, 'A'));

string generateKey(string str, string key) {
    int i=0;
    while(key.size() != str.size()) {
        key.push_back(key[i]);
        i++;
    }
    return key;
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
void encrypt(string plaintext, string key){
    string ciphertext="";
    for(int i=0; i<plaintext.size();i++){
        char c=plaintext[i];
        char kc = key[i];

        ciphertext+=(vignere[kc-'A'][c-'A']);
    }
    cout<<endl<<"Cipher text : ";
    cout<<ciphertext;
}

void decrypt(string ciphertext, string key){
    string plaintext="";
    for(int i=0; i<ciphertext.size();i++){
        char c=(ciphertext[i]-key[i]+26)%26;
    
        plaintext+=c+'A';
    }
    cout<<endl<<"Plaintext : ";
    cout<<plaintext;
}


int main() {
    string str="XMTWESINOYVED", key="LEMON";
    makeTable(vignere);
    key = generateKey(str, key);
    decrypt(str,key);
}