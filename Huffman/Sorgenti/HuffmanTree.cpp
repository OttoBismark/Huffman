#include <iostream>
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "node.h"

using namespace std;

HuffmanTree::HuffmanTree(PriorityQueue *queue)
{
  root = nullptr;

  node *x, *y;

  int n = queue->getSize();

  cout << "Size della queue--->" << n << endl;

  cout << "Algoritmo di Huffman"<< endl;

  for(int i = 0; i < n-1; i++)
  {
    x = queue->estraiMinimo();
    y = queue->estraiMinimo();

    node *z = new node(x,y);

    x->setParent(z);
    y->setParent(z);

    int freq = x->getFrequency() + y->getFrequency();

    z->setFrequency(freq);

    z->setValue('$');

    queue->inserisciNodo(z);
  }

  root = queue->estraiMinimo();
  // stampaAlberoHuffman();

  // visitaAlberoHuffman(root);

}

void HuffmanTree::stampaAlberoHuffman()
{
  cout << "Visita dell'albero di Huffman" << endl;
  visitaAlberoHuffman(root);
}

void HuffmanTree::visitaAlberoHuffman(node *root)
{
  if(root != nullptr)
  {
    cout << "Elemento ->" << root->getValue() << " - >";
    cout << "Frequenza ->" << root->getFrequency() << endl;
    visitaAlberoHuffman(root->getLeftHuff());
    visitaAlberoHuffman(root->getRightHuff());
  }
}

node *HuffmanTree::getRoot()
{
  return root;
}

HuffmanTree::~HuffmanTree()
{
  delete root;
}
