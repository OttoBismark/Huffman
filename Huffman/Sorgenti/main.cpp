#include <iostream>
#include <string>
#include <fstream>
#include "Huffman.h"
#include "concreteTemplate.h"

using namespace std;

int main(int argc, char **argv)
{
  abstractTemplate *templateMethod = new concreteTemplate();
  templateMethod->executeTemplate();
  delete templateMethod;
}
