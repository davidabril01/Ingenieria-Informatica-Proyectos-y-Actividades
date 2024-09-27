#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareHuffmanNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

void buildHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root)
        return;

    if (root->data != '\0') {
        huffmanCodes[root->data] = code;
    }

    buildHuffmanCodes(root->left, code + "0", huffmanCodes);
    buildHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void buildHuffmanTree(string text, unordered_map<char, string>& huffmanCodes) {
    unordered_map<char, int> frequency;
    for (char c : text) {
        frequency[c]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareHuffmanNodes> minHeap;
    for (auto pair : frequency) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    HuffmanNode* root = minHeap.top();

    string code = "";
    buildHuffmanCodes(root, code, huffmanCodes);

    delete root;
}



string compressWithHuffman(string text, unordered_map<char, string>& huffmanCodes) {
    string compressedText = "";
    for (char c : text) {
        compressedText += huffmanCodes[c];
    }
    return compressedText;
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";
    unordered_map<char, string> huffmanCodes;

    buildHuffmanTree(text, huffmanCodes);

    unordered_map<string, char> huffmanDecoding;
    for (auto pair : huffmanCodes) {
        huffmanDecoding[pair.second] = pair.first;
    }

    // Imprime el mapa huffmanDecoding
    for (auto pair : huffmanDecoding) {
        cout << pair.first << "|" << pair.second << "|" << endl;
    }

    cout<<endl;
    string compressedText = compressWithHuffman(text, huffmanCodes);

    // Imprime el texto comprimido
    cout << compressedText << endl;

    return 0;
}