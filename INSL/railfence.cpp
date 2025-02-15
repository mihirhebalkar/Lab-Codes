#include <iostream>
#include <vector>

using namespace std;

string encrypt(string text, int key) {
    vector<vector<char>> rail(key, vector<char>(text.length(), '\n'));

    int row = 0, direction = 1;
    for (int i = 0; i < text.length(); i++) {
        rail[row][i] = text[i];
        if (row == 0) direction = 1;
        else if (row == key - 1) direction = -1;
        row += direction;
    }

    string ciphertext = "";
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < text.length(); j++) {
            
            if (rail[i][j] != '\n') {
                cout<<rail[i][j];
                ciphertext += rail[i][j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return ciphertext;
}

string decrypt(string cipher, int key) {
    int n = cipher.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    int row = 0, direction = 1;
    for (int i = 0; i < n; i++) {
        rail[row][i] = '*';
        if (row == 0) direction = 1;
        else if (row == key - 1) direction = -1;
        row += direction;
    }
    
    for(int i=0; i<key;i++){
        for(int j=0; j<n;j++){
            if(rail[i][j]!='\n'){
                cout<<rail[i][j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] == '*' && index < n) {
                rail[i][j] = cipher[index++];
               
            }
            
        }
    }
    
    for(int i=0; i<key;i++){
        for(int j=0; j<n;j++){
            if(rail[i][j]!='\n'){
                cout<<rail[i][j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    string plaintext = "";
    row = 0, direction = 1;
    for (int i = 0; i < n; i++) {
        plaintext += rail[row][i];
        if (row == 0) direction = 1;
        else if (row == key - 1) direction = -1;
        row += direction;
    }

    return plaintext;
}

int main() {
    int key=3;
    string ciphertext = "BKILCCANOH";
    cout<<"Ciphertext : "<<ciphertext<<endl;
    string ans = decrypt(ciphertext, key);
    cout<<"Decrypted Text : "<<ans;
}
