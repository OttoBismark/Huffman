#include <iostream>
#ifndef ASTRACTTEMPLATE_H
#define ASTRACTTEMPLATE_H

/*
Classe astratta per applicare il design pattern
"Template Method".
Questa classe astratta ci permette di incapsulare
all'interno del metodo executeTemplate() altri due metodi che
ci permettono di richiamare altri due metodi virtuali, la quale
la loro esecuzione viene implementata all'interno di un'altra classe
concreta.
*/
using namespace std;

/*
Classe "abstractTemplate"
*/
class abstractTemplate
{
public:
  /*Entry point per l'esecuzione di altri due metodi virtuali*/
  void executeTemplate()
  {
    intro();
    menuApplication();
  }
protected:
  /*
  Metodi virtuali puri che verranno poi eseguiti ed
  implementati all'interno di una classe concreta
  */
  virtual void intro() = 0;
  virtual void menuApplication() = 0;
};

#endif
