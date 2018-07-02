#include <iostream>
#include <fstream>
#include <vector>
#include "Huffman.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "node.h"
#define MAXVALUE 256

using namespace std;

Huffman::Huffman(string fileName)
{
  queue = new PriorityQueue();
  unsigned char ch;
  fstream file;
  int start, end, size, queueSize;
  unsigned long int *frequency = new unsigned long int[MAXVALUE];
  string outFile, inFile;

  outFile = fileName;
  outFile.erase(outFile.end()-4, outFile.end());

  file.open(fileName, ios::in | ios::binary);

  if(!file.is_open())
  {
    cerr << "File inesistente" << endl;
    exit(-1);
  }
  else
  {
    cout << "\n" << "File esistente / aperto " << endl;
  }

  for(int i = 0; i < MAXVALUE; i++)
  {
    frequency[i] = 0;
  }

  cout << "\n";

  file.seekg(0, file.beg);
  start = file.tellg();
  file.seekg(0, file.end);
  end = file.tellg();
  file.seekg(0, file.beg);
  size = end - start;

  sizeFile = size;
  cout << "Size del file = " << size << endl;

  buffer = new char [size];

  //
  // char *buffer = new char[size];
  // char *bufferSize = buffer;

  file.read(buffer, size);

  int i = 0;

  while(i < size)
  {
    ch = buffer[i];
    frequency[ch]++;
    i++;
  }

  node *temp;

  for(int i = 0; i < MAXVALUE; i++)
  {
    if(frequency[i]>0)
    {
      temp = new node();
      temp->setFrequency(frequency[i]);
      temp->setValue((char)i);
      queue->inserisciNodo(temp);
    }
  }


  HuffmanT = new HuffmanTree(queue);
  delete []frequency;
  cout << "FINE HUFFMAN.CPP" << endl;

}

void Huffman::encodeHuffman(string name)
{
  cout << "Sto dentro il metodo PRIVATO di Huffman" << endl;
  fstream outFile;
  string outFileName, extentionOut;
  string encodeName;
  string bits = "";
  vector<unsigned char> buff;
  unsigned char ch = 0;
  unsigned char word = 0;
  int j = 0;
  float compression = 0;
  long int i = 0;

  extentionOut = ".dat";
  outFileName = name;
  outFileName.erase(outFileName.end()-4, outFileName.end());
  outFileName.append("Encode");
  outFileName.append(extentionOut);


  cout << "Nome file encode ---->" << outFileName << endl;

  outFile.open(outFileName, ios::out | ios::binary);

  if(!outFile.is_open())
  {
    cerr << "FILE DI ENCODE NON CREATO " << endl;
    exit(-1);
  }
  else
  {
    cout << "FILE CREATO CON SUCCESSO" << endl;
  }

  while(i < sizeFile)
  {
    word = buffer[i];
    buildHuffmanBits(HuffmanT->getRoot(), word, &bits, "");
    i++;
  }

  j = 0;

  while(!bits.empty())
  {
    string subHuffman = "";
    subHuffman=bits.substr(0,8);

    if(subHuffman.size() != 8)
    {
      offset = 8 -subHuffman.size()%8;
      for(int i = 0; i < offset; i++)
      {
        bits+='0';
        subHuffman = bits.substr(0,8);
      }
    }
    bits.erase(0,8);

    while(subHuffman[j] != 0)
    {
      unsigned char temp = 1;

      if(subHuffman[j] == '1')
      {
        temp<<=(7-j);
        ch|=temp;
      }
      j++;

    }
    buff.push_back(ch);
    j = 0;
    ch = 0;
  }

  bufferDimension=(buff.size()*8-(offset+1));

  int sizeBuffer = buff.size();

  for(long int i = 0; i < sizeBuffer; i++)
  {
    outFile.put(buff[i]);
  }

  outFile.close();

  compression = (float) bufferDimension/(sizeFile*8);

  cout << "\n" << endl;
  cout << "\t\tTasso di compressione file = " <<
  ((1 - compression)*100) << "%"<< endl;
}

void Huffman::buildHuffmanBits(node *root, unsigned char w,
  string *bits, string bit)
{
  if(root != nullptr)
  {
    if(root->getValue() == w && !root->getRightHuff() && !root->getLeftHuff())
    {
      *bits+=bit;
    }
    else
    {
      buildHuffmanBits(root->getLeftHuff(), w, bits, bit+'0');
      buildHuffmanBits(root->getRightHuff(), w, bits, bit+'1');
    }
  }
}

void Huffman::encode(string name)
{
  cout << "Ho chiamato encode " << endl;
  encodeHuffman(name);
}

void Huffman::decode(string name, string dat)
{
  cout << "Ho chiamato decode"<< endl;
  decodeHuffman(name, dat);
}

void Huffman::decodeHuffman(string name, string dat)
{
  fstream decodeFile, fileEncode;
  string decodeFileName;
  string extention;
  unsigned char ch = 0;
  unsigned char w = 0;
  vector <unsigned char> bits;
  long int h = 0;
  int start, end, size;

  fileEncode.open(dat, ios::in | ios::binary);

  if(!fileEncode.is_open())
  {
    cerr << "File inesistente " << endl;
    exit(-1);
  }
  else
  {
    cout << "FILE .DAT ESISTENTE " << endl;
  }

  decodeFileName = name;
  decodeFileName.erase(decodeFileName.end()-4, decodeFileName.end());
  decodeFileName+="Decode";

  fileEncode.seekg(0, fileEncode.beg);
  start = fileEncode.tellg();
  fileEncode.seekg(0, fileEncode.end);
  end = fileEncode.tellg();
  fileEncode.seekg(0, fileEncode.beg);
  size = end - start;

  sizeFile = size;

  char *buff = new char[sizeFile];

  fileEncode.read(buff, sizeFile);

  fileEncode.close();

  int dimension = name.size();

  if(name.compare(dimension-3, 3, "txt") == 0)
  {
    extention = ".txt";
  }
  if(name.compare(dimension-3, 3, "bmp") == 0)
  {
    extention = ".bmp";
  }
  if(name.compare(dimension-3, 3, "wav") == 0)
  {
    extention = ".wav";
  }
  if(name.compare(dimension-3, 3, "png") == 0)
  {
    extention = ".png";
  }

  decodeFileName.append(extention);

  decodeFile.open(decodeFileName, ios::out | ios::binary);

  cout << "Nome file decodificato ---> " << decodeFileName << endl;


  if(!decodeFile.is_open())
  {
    cerr << "File di decode non aperto... " << endl;
    exit(-1);
  }

  node *temp = HuffmanT->getRoot();

  for(long int i = 0; i < sizeFile; i++)
  {
    w = buff[i];

    for(int j = 7; j >= 0; j--)
    {
      if(h <= bufferDimension)
      {
        ch = (w >> j) & 1;
        if(ch)
        {
          temp = temp->getRightHuff();
        }
        else
        {
          temp = temp->getLeftHuff();
        }

        if(!temp->getLeftHuff() && !temp->getRightHuff())
        {
          bits.push_back(temp->getValue());
          temp = HuffmanT->getRoot();
        }
        h++;
      }
      else
      {
        continue;
      }
    }
  }

  int sizeBits = bits.size();

  for(int i = 0; i < sizeBits; i++)
  {
    decodeFile.put(bits[i]);
  }

  cout << "FILE DECODE CREATO " << decodeFileName << endl;
  decodeFile.close();
}


Huffman::~Huffman()
{
  delete queue, HuffmanT;
  delete []buffer;
}
