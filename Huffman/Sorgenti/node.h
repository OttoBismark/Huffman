#include <iostream>
#ifndef NODE_H
#define NODE_H

using namespace std;

class node
{
private:
  node *right;
  node *left;
  node *rightHuffman;
  node *leftHuffman;
  node *parent;
  unsigned char value;
  int frequency;

public:
  node();
  node(unsigned char v, int f);
  node(node *l, node *r);
  node(const node &);
  ~node();
  void setRightHuff(node *rightH);
  void setLeftHuff(node *leftH);
  void setParent(node *p);
  void setFrequency(int f);
  void setLeft(node *l);
  void setRight(node *r);
  void setValue(unsigned char v);
  node *getRight();
  node *getRightHuff();
  node *getLeftHuff();
  node *getParent();
  node *getLeft();
  int getFrequency();
  unsigned char getValue();
};

#endif
