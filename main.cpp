#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq)
        : ch(ch)
        , freq(freq)
        , left(nullptr)
        , right(nullptr)
    {}
    Node(char ch, int freq, Node* left, Node* right)
        : ch(ch)
        , freq(freq)
        , left(left)
        , right(right)
    {}
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

// Function to print the Huffman Codes
void printCodes(Node* root, string str,
                unordered_map<char, string>& huffmanCode)
{
    
    if (root == nullptr)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate Huffman Codes
void buildHuffmanTree(string text)
{
    // Count frequency of appearance of each character and store it in a map
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Do till there is more than one node in the queue
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency) from the queue
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        // and with frequency equal to the sum of the two nodes' frequencies
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    // Root stores pointer to the root of the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes in a map
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << "\n";
    }

    // Print original string
    cout << "\nOriginal string:\n" << text << "\n";

    // Print encoded string
    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded string:\n" << str << "\n";

    // Function to decode a given Huffman encoded string
    auto decode = [&](string str) {
        cout << "\nDecoded string:\n";
        Node* curr = root;
        for (char bit : str) {
            if (bit == '0') {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }

            // Reached a leaf node
            if (!curr->left && !curr->right) {
                cout << curr->ch;
                curr = root;
            }
        }
        cout << "\n";
    };

    decode(str);
}

int main()
{
    string text;
    cout << "Enter the text to compress using Huffman Coding: ";
    getline(cin, text); // Allows input of strings with spaces

    buildHuffmanTree(text);
    return 0;
}
