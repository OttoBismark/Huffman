#include <iostream>
#include "abstractTemplate.h"
#ifndef CONCRETETEMPLATE_H
#define CONCRETETEMPLATE_H

using namespace std;

/*
Classe concreteTemplate, estenzione di abstractTemplate.
Questa classe ci permette di implementare i metodi incapsulati
nel metodo della classe astratta "abstractTemplate".
Questi metodi verranno implementati da queste stessa classe.
*/

class concreteTemplate : public abstractTemplate
{
public:
  /*Metodi della classe concreteTemplate per effettuare poi la sua futura
  implementazione*/
  void intro();
  void menuApplication();
  virtual ~concreteTemplate();
};

#endif
