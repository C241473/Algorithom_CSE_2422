#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node 
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) 
{
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left,  code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() 
{
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    unordered_map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) 
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nCharacter | Frequency | Huffman Code | Calculation\n";
    cout << "-------------------------------------------------------\n";

    int total_bits = 0;

    for (auto pair : freq) {
        char c = pair.first;
        int f = pair.second;
        string code = huffmanCode[c];

        int bitsUsed = f * code.length();
        total_bits += bitsUsed;

        cout << "   " << c
             << "      |     " << f
             << "     |    " << code
             << "        | " << f << " X " << code.length()
             << " = " << bitsUsed << " bits\n";
    }

    cout << "\nTotal compressed size: " << total_bits << " bits\n";

    return 0;
}
