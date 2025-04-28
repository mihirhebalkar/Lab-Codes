#include <bits/stdc++.h>

using namespace std;

string encrypt(string plaintext, int key){
    string result="";
    
    for(int i=0; i<plaintext.size();i++){
        char ch = plaintext[i];
        
        ch = 'A' + (ch - 'A' + key) % 26;
        result+=ch;
    }
    return result;
    
}

string decrypt(string ciphertext, int key){
    string result="";
    
    for(int i=0; i<ciphertext.size();i++){
        char ch = ciphertext[i];
        
        ch = 'A' + (ch - 'A' - key+ 26)  % 26;
        result+=ch;
    }
    return result;
}

int main() {
    string text = "EXXEGOEXSRGI";
    transform(text.begin(), text.end(), text.begin(),::toupper);
    int s = 4;
    cout << "Text : " << text;
    cout << "\nCipher: " << decrypt(text, s);
    return 0;
}