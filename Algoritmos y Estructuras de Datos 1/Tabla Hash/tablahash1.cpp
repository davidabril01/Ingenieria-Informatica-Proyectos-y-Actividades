#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

class Node {
public:
    int key;
    Node* next;

    Node(int key) {
        this->key = key;
        this->next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* currentNode = table[index];
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* currentNode = table[index];

        while (currentNode != nullptr) {
            if (currentNode->key == key) {
                return true;
            }
            currentNode = currentNode->next;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* currentNode = table[index];
        Node* prevNode = nullptr;

        while (currentNode != nullptr) {
            if (currentNode->key == key) {
                if (prevNode == nullptr) {
                    table[index] = currentNode->next;
                } else {
                    prevNode->next = currentNode->next;
                }
                delete currentNode;
                return;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert elements into the hash table
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(7);

    // Search for an element
    int key = 15;
    if (hashTable.search(key)) {
        cout << "Element " << key << " found in the hash table." << endl;
    } else {
        cout << "Element " << key << " not found in the hash table." << endl;
    }

    // Remove an element
    key = 5;
    hashTable.remove(key);

    // Search for the removed element
    if (hashTable.search(key)) {
        cout << "Element " << key << " found in the hash table." << endl;
    } else {
        cout << "Element " << key << " not found in the hash table." << endl;
    }

    return 0;
}
