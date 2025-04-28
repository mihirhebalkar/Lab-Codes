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

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Modular inverse of a under mod m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Determinant of a 3x3 matrix mod 26
int determinant3x3(vector<vector<int>> m) {
    int a = m[0][0], b = m[0][1], c = m[0][2];
    int d = m[1][0], e = m[1][1], f = m[1][2];
    int g = m[2][0], h = m[2][1], i = m[2][2];

    int det = a * (e * i - f * h)
            - b * (d * i - f * g)
            + c * (d * h - e * g);
    det %= 26;
    if (det < 0) det += 26;
    return det;
}

// Inverse of a 3x3 matrix mod 26
vector<vector<int>> inverseMatrix3x3(vector<vector<int>> m) {
    int det = determinant3x3(m);
    int detInv = modInverse(det, 26);
    if (detInv == -1) {
        cout << "Matrix is not invertible under mod 26\n";
        exit(1);
    }

    vector<vector<int>> adj(3, vector<int>(3));

    // Cofactor matrix
    adj[0][0] = (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    adj[0][1] = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    adj[0][2] = (m[1][0]*m[2][1] - m[1][1]*m[2][0]);

    adj[1][0] = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
    adj[1][1] = (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
    adj[1][2] = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);

    adj[2][0] = (m[0][1]*m[1][2] - m[0][2]*m[1][1]);
    adj[2][1] = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);
    adj[2][2] = (m[0][0]*m[1][1] - m[0][1]*m[1][0]);

    // Transpose + multiply by modular inverse of determinant
    vector<vector<int>> inv(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = adj[j][i] * detInv;
            val %= 26;
            if (val < 0) val += 26;
            inv[i][j] = val;
        }
    }

    return inv;
}

// Multiply 3x3 matrix with 3x1 vector mod 26
vector<int> multiplyMatrix(vector<vector<int>> keyMatrix, vector<int> textVector) {
    vector<int> result(3, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += keyMatrix[i][j] * textVector[j];
        }
        result[i] %= 26;
    }
    return result;
}

// Encrypt a string in chunks of 3
string hillCipherEncrypt(string plaintext, vector<vector<int>> keyMatrix) {
    while (plaintext.size() % 3 != 0)
        plaintext += 'X';  // Padding

    string ciphertext = "";

    for (size_t i = 0; i < plaintext.size(); i += 3) {
        vector<int> textVector(3);
        for (int j = 0; j < 3; j++)
            textVector[j] = plaintext[i + j] - 'A';

        vector<int> cipherVector = multiplyMatrix(keyMatrix, textVector);

        for (int val : cipherVector)
            ciphertext += (val + 'A');
    }

    return ciphertext;
}

// Decrypt a string in chunks of 3
string hillCipherDecrypt(string ciphertext, vector<vector<int>> keyMatrix) {
    vector<vector<int>> invMatrix = inverseMatrix3x3(keyMatrix);

    string plaintext = "";

    for (size_t i = 0; i < ciphertext.size(); i += 3) {
        vector<int> cipherVector(3);
        for (int j = 0; j < 3; j++)
            cipherVector[j] = ciphertext[i + j] - 'A';

        vector<int> plainVector = multiplyMatrix(invMatrix, cipherVector);

        for (int val : plainVector)
            plaintext += (val + 'A');
    }

    return plaintext;
}

int main() {
    vector<vector<int>> keyMatrix = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    string plaintext;
    cout << "Enter plaintext (uppercase letters only): ";
    cin >> plaintext;

    string ciphertext = hillCipherEncrypt(plaintext, keyMatrix);
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted = hillCipherDecrypt(ciphertext, keyMatrix);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

