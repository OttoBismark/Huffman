#include <iostream>
#include <string>
#include "PriorityQueue.h"
#include "node.h"
#include "binarySearchTree.h"

using namespace std;

PriorityQueue::PriorityQueue()
{
  t = new binarySearchTree();
}

int PriorityQueue::getSize()
{
  int size = sizeQueue();
  return size;
}

int PriorityQueue::sizeQueue()
{
  int sum = 0;
  sum = t->sizeTree(t->getRadice());
  return sum;
}

node *PriorityQueue::estraiMinimo()
{
  return minimo();
}

node *PriorityQueue::minimo()
{
  return t->minimo();
}

void PriorityQueue::inserisciNodo(node *z)
{
  t->inserisci(z);
}

void PriorityQueue::stampa()
{
  stampaCoda();
}

void PriorityQueue::stampaCoda()
{
  t->stampa(t->getRadice());
}

PriorityQueue::~PriorityQueue()
{
  delete t;
}
