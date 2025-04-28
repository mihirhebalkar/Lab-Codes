#include <bits/stdc++.h>

using namespace std;

void prepareKeyMatrix(string key, char matrix[5][5]){
    vector<bool> used(26, false);
    string temp = ""; //stores occ in order
    used['J'-'A'] = true;
    
    for(char c : key){
        if(!used[c-'A']){
            temp+=c;
            used[c-'A'] = true;
        }
    }
    
    for(char c = 'A'; c<='Z';c++){
        if(!used[c-'A']){
            temp+=c;
            used[c-'A'] = true;
        }
    }
    
    
    for(int i=0; i<25;i++){
        matrix[i/5][i%5] = temp[i];
        cout<<matrix[i/5][i%5];
    }
}

void findPosition(char matrix[5][5], char c, int &row, int &col) {
    if (c == 'j') c = 'i';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
}

string encrypt(string plaintext, char matrix[5][5]){
    string output="";
    string prepared = "";
    
    for(char c:plaintext){
        if(c=='J') c='I';
        prepared+=c;
    }
    
    for(int i=0; i<prepared.length();i+=2){
        char a = prepared[i];
        
        char b = (i+1 < prepared.length())? prepared[i+1] : 'X';
        
        if(a==b){
            b='X';
            i--;
        }
        
        
        int row1,row2,col1,col2;
        
        findPosition(matrix, a,row1,col1);
        findPosition(matrix, b,row2,col2);
        
        if (row1 == row2) {
            output += matrix[row1][(col1 + 1) % 5];
            output += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            output += matrix[(row1 + 1) % 5][col1];
            output += matrix[(row2 + 1) % 5][col2];
        } else {
            output += matrix[row1][col2];
            output += matrix[row2][col1];
        }
    }
    
    return output;
    
}

string decrypt(string ciphertext,  char matrix[5][5]){
    string output="";

    for(int i=0; i<ciphertext.length();i+=2){
        char a = (ciphertext[i]);
        char b = (ciphertext[i + 1]);
        int row1,row2,col1,col2;
        
        findPosition(matrix, a,row1,col1);
        findPosition(matrix, b,row2,col2);
        
        if (row1 == row2) {
            output += matrix[row1][(col1 - 1) % 5];
            output += matrix[row2][(col2 - 1) % 5];
        } else if (col1 == col2) {
            output += matrix[(row1 - 1) % 5][col1];
            output += matrix[(row2 - 1) % 5][col2];
        } else {
            output += matrix[row1][col2];
            output += matrix[row2][col1];
        }
    }
    
    return output;
}

void displayMatrix(char matrix[5][5]) {
    cout << "\n\nKey Matrix:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string key, plaintext;
    char matrix[5][5];

    cout << "Enter key: ";
    getline(cin, key);

    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    
    transform(key.begin(), key.end(), key.begin(),::toupper);
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(),::toupper);

    prepareKeyMatrix(key, matrix);
    displayMatrix(matrix);

    string ciphertext = decrypt(plaintext, matrix);
    cout << "\nEncrypted Text: " << ciphertext << endl;
}