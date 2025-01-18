# Huffman Coding Project

## Overview
This project implements Huffman Coding, a lossless data compression algorithm. It compresses text by assigning shorter codes to frequent characters and longer codes to less frequent ones.

## Features

### Implementation Details

The core implementation of Huffman Coding includes the following key components:
    struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq)
        : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
    Node(char ch, int freq, Node* left, Node* right)
        : ch(ch), freq(freq), left(left), right(right) {}
};

### Priority Queue Comparison Object
  struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

### Huffman Tree Construction and Encoding

A priority queue is used to construct the Huffman Tree efficiently.

Recursive traversal of the tree generates binary codes for each character.

Encoding and Decoding

The program encodes the input text into a binary string using the generated codes.

Decoding reverses the process by traversing the Huffman Tree.

### Example Code

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);
}
### Interactive User Input

The program prompts users to input a text string for compression and displays:

The Huffman codes for each character.

The encoded binary string.

The decoded string, which matches the original input.
# How to Run

1,Compile the program using:
g++ -std=c++17 -o HuffmanCoding HuffmanCoding.cpp
2, Run the program:
./HuffmanCoding
3, Enter the text to compress when prompted.

## Problem Description: Huffman Coding for Data Compression

This program implements Huffman Coding for compressing text data. Key implementation details include:

### Data Structures:

#### Priority Queue: Used to efficiently construct the Huffman Tree by always extracting the two nodes with the lowest frequencies.

#### Hash Maps: Used for storing the frequency of characters and their corresponding Huffman codes.

Tree Structure: The Huffman Tree is built dynamically using nodes to represent characters and their frequencies.

Efficiency:

The compression technique minimizes the average length of the encoding based on character frequencies. It effectively reduces the file size for text with high redundancy.

The priority queue ensures that the construction of the Huffman Tree is efficient, with a time complexity of O(n log n), where n is the number of unique characters.

#### Additional Features

#### Interactive Menu: 
The program includes an interactive menu to guide users through encoding and decoding operations.

#### Frequency Table Display: 
The program displays a detailed frequency table of characters before building the Huffman Tree, helping users understand the compression process.

#### Memory Management: 
Proper cleanup of dynamically allocated memory ensures there are no memory leaks.

#### Future Enhancements

✅ Add support for compressing binary files in addition to text files.

✅ Implement multithreading for faster processing of large files.

✅ Integrate a graphical user interface (GUI) for better usability.

### Acknowledgments

This implementation is based on the principles of Huffman Coding, originally introduced by David A. Huffman in 1952.
