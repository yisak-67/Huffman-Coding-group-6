# Project Report: Huffman Coding for Data Compression

## Introduction
Huffman Coding is a greedy algorithm used for lossless data compression. This project implements Huffman Coding in C++ and demonstrates its efficiency.

## Data Structures
- **Priority Queue**: Efficiently selects the two nodes with the smallest frequencies.
- **Huffman Node**: Represents tree nodes, including character, frequency, left child, and right child.

## Algorithm
1. Build a frequency table from the input text.
2. Use a priority queue to construct the Huffman Tree.
3. Traverse the tree to generate Huffman codes.
4. Encode the text using the generated codes.
5. Decode the encoded text using the Huffman Tree.

## Results
- Compression achieved depends on input text's character frequency distribution.
- Encoded text size: `<size>` bytes.
- Original text size: `<size>` bytes.
- Compression Ratio: `<ratio>`.

## Conclusion
Huffman Coding is efficient for compressing text with skewed frequency distributions. This project demonstrates a working implementation with clear documentation.

## References
- [Huffman Coding on Wikipedia](https://en.wikipedia.org/wiki/Huffman_coding)
