//
//  main.cpp
//  Template estructura de datos
//
//  Created by Ricardo Martínez Arquieta on 24/01/17.
//  Copyright © 2017 Tec de Monterrey. All rights reserved.
//  A01281611

#include <iostream>
#include "node.h"
#include "secondnode.h"
using namespace std;

int main()
{
    Linkedlist<string> *miLista= new Linkedlist<string>();
    
    miLista->addLast("HOLA");
    miLista->addLast("CRAYOLA");
    miLista->addFirst("COMO");
    miLista->addLast("TE VA?");
    miLista->print();
    return 0;
}
