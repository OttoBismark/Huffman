#include <iostream>
#include "node.h"
#include "binarySearchTree.h"
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

using namespace std;

class PriorityQueue
{
private:
  binarySearchTree *t;
  int sizeQueue();
  void stampaCoda();
  void incrementa(char );
  node *minimo();
public:
  PriorityQueue();
  ~PriorityQueue();
  void inserisciNodo(node *);
  node *estraiMinimo();
  void stampa();
  int getSize();

};

#endif
