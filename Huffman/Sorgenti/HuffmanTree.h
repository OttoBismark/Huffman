#include <iostream>
#include "node.h"
#include "PriorityQueue.h"
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

using namespace std;

class HuffmanTree
{
private:
  node *root;
  void visitaAlberoHuffman(node *);
public:
  HuffmanTree(PriorityQueue *);
  ~HuffmanTree();
  void stampaAlberoHuffman();
  node *getRoot();
};

#endif
