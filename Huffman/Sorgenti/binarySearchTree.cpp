#include <iostream>
#include "binarySearchTree.h"
#include "node.h"

using namespace std;

/*Costruttore della classe binarySearchTree*/
binarySearchTree::binarySearchTree()
{
  root = nullptr;
}

/*Metodo per inserimento del nodo*/
void binarySearchTree::inserisci(node *z)
{
  insertIntoBST(z);
}

/*Metodo privato per le operazioni per l'inserimento del nodo nell'albero*/
void binarySearchTree::insertIntoBST(node *z)
{
  node *y = nullptr;
  node *x = root;

  while(x != nullptr)
  {
    y = x;

    if(z->getFrequency() <= x->getFrequency())
    {
      x = x->getLeft();
    }
    else
    {
      x = x->getRight();
    }
  }

  z->setParent(y);

  if(y == nullptr)
  {
    root = z;
  }
  else if(z->getFrequency() <= y->getFrequency())
  {
    y->setLeft(z);
  }
  else
  {
    y->setRight(z);
  }
}

/*Metodo di stampa per stampare l'albero binario di ricerca*/
void binarySearchTree::stampa(node *root)
{
  if(root != nullptr)
  {
     stampa(root->getLeft());
     cout << "Frequenza -> " << root->getFrequency();
     cout << "Valore ->" << root->getValue();

     if(root->getParent() == nullptr)
     {
        cout << " : Nodo padre = NULL" << endl;
     }
     else
     {
        cout << " : Nodo padre = " << root->getParent()->getValue() << endl;
     }
     stampa(root->getRight());
   }
}


void binarySearchTree::ricerca(char ch)
{
  node *p, *s;
  node *trovato = ricercaBinaria(root, ch);

  s = successore(trovato);
}


node *binarySearchTree::ricercaBinaria(node *root, char c)
{
  if(root == nullptr)
  {
    return nullptr;
  }

  if(c == root->getValue())
  {
    return root;
  }
  else
  {
    if(c <= root->getValue())
    {
      return ricercaBinaria(root->getLeft(), c);
    }
    else
    {
      return ricercaBinaria(root->getRight(), c);
    }
  }
}

node *binarySearchTree::minimo()
{

  node * min;

  min = cercaMinimo(root);

  if(min == nullptr)
  {
    return nullptr;
  }
  else
  {
    node *current = new node();

    current->setValue(min->getValue());
    current->setFrequency(min->getFrequency());
    current->setParent(min->getParent());
    current->setRight(min->getRight());
    current->setLeft(min->getLeft());
    current->setLeftHuff(min->getLeftHuff());
    current->setRightHuff(min->getRightHuff());
    cancellazione(min);

    return current;
  }
}


node *binarySearchTree::cercaMinimo(node *root)
{
  if(root == nullptr)
  {
    return root;
  }

  node *m = root;

  while(m->getLeft() != nullptr)
  {
    m = m->getLeft();
  }

  return m;
}


node *binarySearchTree::successore(node *z)
{
  node *s;

  if(z->getRight() != nullptr)
  {
    return cercaMinimo(z->getRight());
  }

  s = z->getParent();

  while(s != nullptr && s->getRight() == z)
  {
    z = s;
    s = s->getParent();
  }

  return s;
}

/*Metodo per effettuare la cancellazione di un nodo dell'albero */
void binarySearchTree::cancellazione(node *z)
{
  node *y, *x;

  if(z->getLeft() == nullptr || z->getRight() == nullptr)
  {
    y = z;
  }
  else
  {
    y = successore(z);
  }

  if(y->getLeft() != nullptr)
  {
    x = y->getLeft();
  }
  else
  {
    x = y->getRight();
  }

  if(x != nullptr)
  {
    x->setParent(y->getParent());
  }

  if(y->getParent() == nullptr)
  {
    root = x;
  }
  else if(y == y->getParent()->getLeft())
  {
    y->getParent()->setLeft(x);
  }
  else
  {
    y->getParent()->setRight(x);
  }

  if(y != z)
  {
    z->setValue(y->getValue());
    z->setRight(y->getRight());
    z->setLeft(y->getLeft());
    z->setParent(y->getParent());
    z->setFrequency(y->getFrequency());
  }
  delete y;
}

/*Metodo per settare la radice dell'albero*/
void binarySearchTree::setRadice(node *root)
{
  this->root = root;
}

/*Metodo che ci permette di calcolare l'altezza dell'albero*/
int binarySearchTree::sizeTree(node *r)
{
  if(r == nullptr)
  {
    return 0;
  }
  else
  {
    return (1+(sizeTree(r->getRight()) + sizeTree(r->getLeft())));
  }
}

/*Metodo che ritorna la radice dell'albero*/
node *binarySearchTree::getRadice()
{
  return root;
}

/*Distruttore della classe binarySearchTree*/
binarySearchTree::~binarySearchTree()
{

}
