#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1; // -1 indicates empty
    }

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert using Linear Probing
    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
    }

    // Display table
    void display() {
        cout << "\nHash Table (Linear Probing):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            if (table[i] != -1)
                cout << table[i];
            else
                cout << "Empty";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    int n, key;
    cout << "Enter number of keys to insert: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++) {
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}



//chaining


#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    list<int> table[TABLE_SIZE];

public:
    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert using Chaining
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Display table
    void display() {
        cout << "\nHash Table (Chaining):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            for (auto x : table[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;

    int n, key;
    cout << "Enter number of keys to insert: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++) {
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    return 0;
}
