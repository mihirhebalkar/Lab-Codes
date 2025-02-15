#include <bits/stdc++.h>
using namespace std;
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

vector<vector<int>> inverseMatrix(vector<vector<int>> keyMatrix) {
    int det = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]) % 26;
    if (det < 0) det += 26;

    int detInverse = modInverse(det, 26);
    if (detInverse == -1) {
        cout << "Key matrix is not invertible under mod 26" << endl;
        exit(1);
    }

    vector<vector<int>> invMatrix(2, vector<int>(2));
    invMatrix[0][0] = keyMatrix[1][1] * detInverse % 26;
    invMatrix[0][1] = -keyMatrix[0][1] * detInverse % 26;
    invMatrix[1][0] = -keyMatrix[1][0] * detInverse % 26;
    invMatrix[1][1] = keyMatrix[0][0] * detInverse % 26;

    for (auto &row : invMatrix) {
        for (auto &elem : row) {
            if (elem < 0) elem += 26;
        }
    }

    return invMatrix;
}

vector<int> multiplyMatrix(vector<vector<int>> keyMatrix, vector<int> textVector) {
    vector<int> result(2, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i] += keyMatrix[i][j] * textVector[j];
        }
        result[i] %= 26;
    }
    return result;
}

string hillCipherEncrypt(string plaintext, vector<vector<int>> keyMatrix) {
    vector<int> textVector(2);
    for (int i = 0; i < 2; i++) {
        textVector[i] = plaintext[i] - 'A';
    }

    vector<int> cipherVector = multiplyMatrix(keyMatrix, textVector);

    string ciphertext = "";
    for (int i = 0; i < 2; i++) {
        ciphertext += (cipherVector[i] + 'A');
    }

    return ciphertext;
}

string hillCipherDecrypt(string cipher, vector<vector<int>> keyMatrix) {
    vector<vector<int>> invMatrix = inverseMatrix(keyMatrix);
    vector<int> cipherVector(2);
    for (int i = 0; i < 2; i++) {
        cipherVector[i] = cipher[i] - 'A';
    }

    vector<int> plainVector = multiplyMatrix(invMatrix, cipherVector);

    string plaintext = "";
    for (int i = 0; i < 2; i++) {
        plaintext += (plainVector[i] + 'A');
    }

    return plaintext;
}

int main() {
    vector<vector<int>> keyMatrix = {{3, 3}, {2, 5}};
    string ciphertext = "DF";
    cout<<"Ciphertext : "<<ciphertext<<endl;
    string ans = hillCipherDecrypt(ciphertext, keyMatrix);
    
    cout<<"Plaintext : "<<ans;
    
    return 0;
}
