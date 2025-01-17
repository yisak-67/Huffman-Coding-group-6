<<<<<<< HEAD
"# Huffman-Coding-group-6" 


Huffman Coding | Greedy Algorizm 


Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is the prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.
See this for applications of Huffman Coding. 
There are mainly two major parts in Huffman Coding

Build a Huffman Tree from input characters.
Traverse the Huffman Tree and assign codes to characters.
Algorithm:
The method which is used to construct optimal prefix code is called Huffman coding.

 This algorithm builds a tree in bottom up manner. We can denote this tree by T

Let, |c| be number of leaves

|c| -1 are number of operations required to merge the nodes. Q be the priority queue which can be used while constructing binary heap

Algorithm Huffman (c)
{
   n= |c| 

   Q = c 
   for i<-1 to n-1

   do
   {

       temp <- get node ()

      left (temp] Get_min (Q) right [temp] Get Min (Q)

      a = left [templ b = right [temp]

      F [temp]<- f[a] + [b]

      insert (Q, temp)

    }

return Get_min (0)
}
=======
Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. 
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 
>>>>>>> efc8e2203b4af3aef43c64fb49aaac31a2fa7278
