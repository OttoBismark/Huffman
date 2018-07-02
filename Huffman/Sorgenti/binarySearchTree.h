#include <iostream>
#include "node.h"
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

using namespace std;

/*
Classe binarySearchTree (BST)
*/
class binarySearchTree
{
private:
  node *root;
  node *cercaMinimo(node *);
  node *ricercaBinaria(node *, char );
  node *successore(node *);
  node *predecessore(node *);
  void ricerca(char );
  void setRadice(node *);
  void insertIntoBST(node * );

public:
  binarySearchTree();
  virtual ~binarySearchTree();
  node *minimo();
  void cancellazione(node *);
  node *getRadice();
  void stampa(node *);
  void inserisci(node * );
  int sizeTree(node *);
};

#endif
