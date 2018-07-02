#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanTree.h"
#include "PriorityQueue.h"
#include "node.h"
#ifndef HUFFMAN_H
#define HUFFMAN_H

using namespace std;

class Huffman
{
private:
  PriorityQueue *queue;
  HuffmanTree *HuffmanT;

  unsigned int sizeFile;
  char *buffer;
  int offset;
  long int bufferDimension;
  void encodeHuffman(string );
  void buildHuffmanBits(node *, unsigned char , string *, string );
  void decodeHuffman(string , string);

public:
  Huffman(string fileName);
  ~Huffman();
  void encode(string );
  void decode(string , string );
};

#endif
