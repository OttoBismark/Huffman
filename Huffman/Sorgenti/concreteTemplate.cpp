#include "abstractTemplate.h"
#include "concreteTemplate.h"
#include "Huffman.h"
#include <iostream>

using namespace std;


/*
Implementazione dei metodi della classe concreteTemplate che sono incapsulati
dentro l'executeTemplate della classe astratta.
*/

/* Metodo intro() */
void concreteTemplate::intro()
{
  system("clear");
  cout << "*********************************************" << endl;
  cout << "*   Progetto di Algoritmi e Strutture dati  *" << endl;
  cout << "*   e Lab. di Algoritmi e Strutture Dati    *" << endl;
  cout << "*                                           *" << endl;
  cout << "*    Progetto di Pauciullo Valerio          *" << endl;
  cout << "*        Matricola: 0124001023               *" << endl;
  cout << "*       Anno Accademico 2017-2018           *"<< endl;
  cout << "*********************************************" << endl;

  cout << "Premere un tasto per continuare" << endl;
  cin.get();
}

/* Metodo menuApplication() */
void concreteTemplate::menuApplication()
{
  unsigned char c;
  Huffman *huffman;
  string name, dat;
  cout << endl;
  system("clear");
  cout << "*     Progetto 'Codifica Di Huffman'    *" << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " " << endl;
  cout << " Inserire file " << endl;
  cout << " > ";
  cin >> name;
  huffman = new Huffman(name);

  while(1)
  {
    cout << "\n\n";
    cout << "*\t \tScegliere opzione: *" << endl;
    cout << "[E]ncode " << endl;
    cout << "[D]ecode " << endl;
    cout << "[U]scita" << endl;
    cin >> c;

    if(c == 'E' || c == 'e')
    {
      cout << "\t\t Hai premuto E" << endl;
      huffman->encode(name);
    }
    else if(c == 'D' || c == 'd')
    {
      cout << "\t\t Hai premuto D" << endl;
      cout << "Inserire file di encode (.dat)" << endl;
      cin >> dat;
      huffman->decode(name, dat);
    }
    else if(c == 'U' || c == 'u')
    {
      cout << "\t\t Hai premuto U" << endl;
      cout << "Uscita dal programma!" << endl;
      exit(-1);
      delete huffman;
    }
    else
    {
      cout << "\t\t Comando inesistente" << endl;
      cout <<"\t\t Inserire un comando tra i seguenti" << endl;
      cout << "[E]ncode " << endl;
      cout << "[D]ecode " << endl;
      cout << "[U]scita" << endl;

    }
  }
}

/*Distruttore della classe "concreteTemplate"*/
concreteTemplate::~concreteTemplate()
{
}
