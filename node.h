//
//  node.h
//  Template estructura de datos
//
//  Created by Ricardo Martínez Arquieta on 24/01/17.
//  Copyright © 2017 Tec de Monterrey. All rights reserved.
//  A01281611

#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    node(T data);
    node(T data, node<T> *next);
    T getData();
    node<T> *getNext();
    void setData(T data);
    void setNext(node<T> *next);
    
private:
    T data;
    node<T> *next;
};

template <typename T>
node<T>::node(T data)
{
    this->data = data;
    this->next = NULL;
}

template <typename T>
node<T>::node(T data, node<T> *next)
{
    this->data = data;
    this->next = next;
}

template <typename T>
T node<T>::getData()
{
    return this->data;
}

template <typename T>
node<T>*node<T>::getNext()
{
    return this->next;
}

template <typename T>
void node<T>::setNext(node<T> *next)
{
    this->next=next;
}

#endif /* node_h */
