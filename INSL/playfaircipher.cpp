#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void precompute(vector<int> &hash, string s) {
    for (int i = 0; i < s.size(); i++) {
        char c = s[i] - 'A';
        if (c == 8) hash[9]++;
        if (c == 9) hash[8]++;
        hash[c]++;
    }
}

void createMatrix(char (&cipher)[5][5], vector<int> hash, string s) {
    int c = 0;
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (c < s.size()) {
                if ((char)s[c] == 'J') {
                    cipher[i][j] = 'I';
                } else {
                    cipher[i][j] = (char)s[c];
                }
                c++;
            } else {
                while (hash[k] != 0) {
                    k++;
                }
                if (k == 9 && hash[k] == 0) {
                    k++;
                    cipher[i][j] = 'A' + k;
                }
                cipher[i][j] = 'A' + k;
                k++;
            }
        }
    }
}

void displayMatrix(char cipher[5][5]) {
    cout << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << cipher[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int, int>> search(vector<pair<int, int>> &ind, char first, char second, char cipher[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cipher[i][j] == first) {
                ind[0].first = i;
                ind[0].second = j;
            } else if (cipher[i][j] == second) {
                ind[1].first = i;
                ind[1].second = j;
            }
        }
    }
    return ind;
}

void display(string ans) {
    cout << endl;
    for (int i = 0; i < ans.size() - 1; i += 2) {
        cout << ans[i] << ans[i + 1] << " ";
    }
}

void preprocess(string &msg) {
    for (int i = 0; i < msg.size() - 1; i = i + 2) {
        char first = msg[i];
        char second = msg[i + 1];

        if (first == second) {
            msg.insert(i + 1, "X");
        }
    }

    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    if (msg.size() % 2 != 0) msg.append("X");
}

void encrypt(char cipher[5][5], string &ans, string msg) {
    vector<pair<int, int>> ind(2);
    for (int i = 0; i < msg.size() - 1; i = i + 2) {
        char first = msg[i];
        char second = msg[i + 1];

        search(ind, first, second, cipher);
        if (ind[0].first == ind[1].first) { // same row
            ans += (cipher[ind[0].first][(ind[0].second + 1) % 5]);
            ans += (cipher[ind[1].first][(ind[1].second + 1) % 5]);
        } else if (ind[0].second == ind[1].second) { // same col
            ans += (cipher[(ind[0].first + 1) % 5][ind[0].second]);
            ans += (cipher[(ind[1].first + 1) % 5][ind[1].second]);
        } else { 
            // top right
            ans += (cipher[ind[0].first][ind[1].second]);

            // bottom left
            ans += (cipher[ind[1].first][ind[0].second]);
        }
    }
    cout << endl << "Encrypted Text: ";
    display(ans);
}

void decrypt(char cipher[5][5], string &ans, string msg) {
    vector<pair<int, int>> ind(2);
    for (int i = 0; i < msg.size() - 1; i = i + 2) {
        char first = msg[i];
        char second = msg[i + 1];

        search(ind, first, second, cipher);
        if (ind[0].first == ind[1].first) { // same row
            ans += (cipher[ind[1].first][(ind[1].second - 1) % 5]);
            ans += (cipher[ind[0].first][(ind[0].second - 1) % 5]);
        } else if (ind[0].second == ind[1].second) { // same col
            ans += (cipher[(ind[1].first - 1) % 5][ind[1].second]);
            ans += (cipher[(ind[0].first - 1) % 5][ind[0].second]);
        } else { 
            ans += (cipher[ind[0].first][ind[1].second]);
            ans += (cipher[ind[1].first][ind[0].second]);
        }
    }
    cout << endl << "Decrypted Text: ";
    display(ans);
}

int main() {
    string s, msg, ans;
    cout << "Enter key : ";
    cin >> s;

    cout << "Enter message : ";
    cin >> msg;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    preprocess(msg);
    vector<int> hash(26, 0);

    precompute(hash, s);

    char cipher[5][5];

    createMatrix(cipher, hash, s);

    displayMatrix(cipher);

    encrypt(cipher, ans, msg);
    // decrypt(cipher, ans, msg);

    return 0;
}
