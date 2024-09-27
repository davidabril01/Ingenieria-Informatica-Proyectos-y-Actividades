#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

string decompressWithHuffman(string compressedText, unordered_map<string, char>& huffmanCodes) {
    string result = "";
    string currentCode = "";

    for (char c : compressedText) {
        currentCode += c;
        if (huffmanCodes.find(currentCode) != huffmanCodes.end()) {
            result += huffmanCodes[currentCode];
            currentCode = "";
        }
    }

    return result;
}

int main() {

    unordered_map<string, char> huffmanDecoding;
    string line;
    string code;
    string character;
    
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        getline(iss, code, '|');
        getline(iss, character, '|');
        huffmanDecoding[code] = character[0];
    }

    string compressedText;
    getline(cin, compressedText);

    string decompressedText = decompressWithHuffman(compressedText, huffmanDecoding);

    cout << "Decompressed Text: " << decompressedText << endl;

    return 0;
}
