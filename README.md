# Huffman Coding Project

## Overview
This project implements Huffman Coding, a lossless data compression algorithm. It compresses text by assigning shorter codes to frequent characters and longer codes to less frequent ones.

## Features
- Build a frequency table.
- Construct a Huffman Tree using a priority queue.
- Generate Huffman codes for characters.
- Encode and decode text.

## Files
- HuffmanNode.h: Defines the Huffman Node structure.
- HuffmanCoding.cpp: Contains the main logic for encoding and decoding.
- input.txt: Input file with the text to compress.
- encoded.txt: Encoded text.
- decoded.txt: Decoded text (should match the input).

## How to Run
1. Place text in input.txt.
2. Compile the program:
   ```bash
   g++ -std=c++17 -o HuffmanCoding src/HuffmanCoding.cpp