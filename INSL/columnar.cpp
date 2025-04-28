#include <bits/stdc++.h>

using namespace std;

string encrypt(vector<string> dict, string key) {
    string cipherText = "";
    
    for(int i=0; i<key.length();i++){
        int ind = key[i]-'1';
        cipherText+=dict[ind];
    }
        
    return cipherText;
}


string decrypt(vector<string> dict, string key) {
    string plainText = "";
    int ncol = key.length();
    int nrow = dict[0].length();

    // Create a vector to store reordered columns
    vector<string> newDict(ncol);

    // Rearranging columns to original order
    for (int i = 0; i < ncol; i++) {
        int colPosition = key[i] - '1';
        newDict[colPosition] = dict[i];
    }

    // Reconstruct plaintext row-wise
    for (int r = 0; r < nrow; r++) {
        for (int c = 0; c < ncol; c++) {
            plainText += newDict[c][r];
        }
    }

    return plainText;
}


int main() {
    int ncol = 5;
    string plaintext="WEAREDISCOVEREDFLEE", key="23415";
    
    while(plaintext.size()%ncol!=0){ //padding
        plaintext+='x';
    }
    
    cout<<plaintext;
    
    vector<string> dict(ncol,"");
    
    for(int i=0; i<plaintext.length();i++){ 
        dict[i%ncol]+=plaintext[i];
    }
    
    cout<<endl;
    
    for(auto x:dict){
        cout<<x;
        cout<<endl;
    }
    

    string cipherText = decrypt(dict, key);
    cout << "\nEncrypted Text: " << cipherText << endl;

    return 0;
}
