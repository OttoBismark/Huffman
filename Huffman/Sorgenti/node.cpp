#include <iostream>
#include "node.h"

using namespace std;

node::node()
{
  left = nullptr;
  right = nullptr;
  parent = nullptr;
  leftHuffman = nullptr;
  rightHuffman = nullptr;
  frequency = 0;
  value = ' ';
}

node::node(unsigned char v, int f)
{
  left = nullptr;
  right = nullptr;
  parent = nullptr;
  leftHuffman = nullptr;
  rightHuffman = nullptr;
  value = v;
  frequency = f;
}

node::node(const node &a)
{
  left = a.left;
  right = a.right;
  parent = a.parent;
  value = a.value;
  frequency = a.frequency;
}

node::node(node *l, node *r)
{
  left = nullptr;
  right = nullptr;
  leftHuffman = l;
  rightHuffman = r;
}

void node::setRight(node *r)
{
  right = r;
}

void node::setLeft(node *l)
{
  left = l;
}

void node::setRightHuff(node *dxHuffman)
{
  rightHuffman = dxHuffman;
}

void node::setLeftHuff(node *sxHuffman)
{
  leftHuffman = sxHuffman;
}

void node::setParent(node *p)
{
  parent = p;
}

void node::setValue(unsigned char v)
{
  value = v;
}

void node::setFrequency(int f)
{
  frequency = f;
}

node *node::getRight()
{
  return right;
}

node *node::getLeft()
{
  return left;
}

node *node::getRightHuff()
{
  return rightHuffman;
}

node *node::getLeftHuff()
{
  return leftHuffman;
}

node *node::getParent()
{
  return parent;
}

unsigned char node::getValue()
{
  return value;
}

int node::getFrequency()
{
  return frequency;
}

node::~node()
{}
