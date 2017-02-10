//  secondnode.h
//  Template estructura de datos
//  Created by Ricardo Martínez Arquieta on 24/01/17.
//  Copyright © 2017 Tec de Monterrey. All rights reserved.
//  A01281611

#ifndef secondnode_h
#define secondnode_h
#include <iostream>
#include "node.h"
using namespace std;

template <class T>
class Linkedlist {
    
public:
    Linkedlist();
    ~Linkedlist();
    bool empty();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    T deleteFirst();
    T deleteLast();
    T del(int pos);
    int deleteAll();
    T get(int pos);
    T set(T data, int pos);
    bool change(int pos1, int pos2);
    void print();
    T reverse(int pos1, int pos2, int pos);
    int shift(T data, int pos1, int pos2, int pos);
    int spin(int pos);
    void operator == (T data);
    void operator += (T data);
    void operator += (Linkedlist<T> I);
    void LinkedList(Linkedlist I);
    void operator = (T data);
    
    
private:
    node<T> *head;
    int size;
    void borraTodo();
};
template <typename T>
void Linkedlist<T>::borraTodo()
{
    node<T> *aux=head;
    while (head !=NULL)
    {
        head = head->getNext();
        delete aux;
        aux=head;
    }
}

template <typename T>
Linkedlist<T>::Linkedlist()
{
    head= NULL;
    size=0;
}

template <typename T>
Linkedlist<T>::~Linkedlist()
{
    borraTodo();
}

template <typename T>
int Linkedlist<T>::deleteAll()
{
    borraTodo();
    int tam=size;
    size=0;
    return tam;
}

template <typename T>
bool Linkedlist<T>::empty()
{
    return head==NULL;
}

template <typename T>
int Linkedlist<T>::getSize()
{
    return size;
}

template <typename T>
void Linkedlist<T>::addFirst(T data)
{
    head = new node<T>(data, head);
    size++;
}
template <typename T>
void Linkedlist<T>::addLast(T data)
{
    if (empty()) {
        addFirst(data);
    }
    else
    {
        node<T> *aux=head;
        while (aux->getNext() !=NULL) {
            aux= aux->getNext();
        }
        aux->setNext(new node<T>(data));
        size++;
    }
}

template <typename T>
bool Linkedlist<T>::add(T data, int pos)
{
    if (pos < 0 || pos>size) {
        return false;
    }
    if (pos==0) {
        addFirst(data);
    }
    else if (pos==size)
    {
        addLast(data);
    }
    else
    {
        node<T> *aux=head;
        for (int i=1; i<pos; i++)
        {
            aux=aux->getNext();
        }
        aux->setNext(new node<T>(data, aux->getNext()));
        size++;
    }
    return true;
}

template <typename T>
T Linkedlist<T>::deleteFirst()
{
    T dataAux=head->getData();
    node<T> *aux=head;
    head=head->getNext;
    delete aux;
    return dataAux;
}

template <typename T>
T Linkedlist<T>::deleteLast()
{
    if (size==1)
    {
        return deleteFirst();
    }
    else
    {
        node<T> *aux=head;
        while (aux->getNext()->getNext() !=NULL)
        {
            aux=aux->getNext();
        }
        T dataAux= aux->getNext()->getData();
        delete aux->getNext();
        aux->setNext(NULL);
        return dataAux;
    }
}

template <typename T>
T Linkedlist<T>::del(int pos)
{
    if (pos==0)
    {
        return deleteFirst();
    }
    if (pos==size-1)
    {
        return deleteLast();
    }
    node<T> *aux=head;
    for (int i=1; i<pos; i++)
    {
        aux=aux->getNext();
    }
    node<T> *aux2= aux->getNext();
    aux->setNext(aux2->getNext());
    T dataAux = aux2->getData();
    delete *aux2;
    size--;
    return dataAux;
}

template <typename T>
T Linkedlist<T>::get(int pos)
{
    node<T> *aux = head;
    for (int i=1; i<=pos; i++)
    {
        aux=aux->getNext();
    }
    return aux->getData();
}

template <typename T>
T Linkedlist<T>::set(T data, int pos)
{
    node<T> *aux = head;
    for (int i=1; i<=pos; i++)
    {
        aux=aux->getNext();
    }
    T dataAux = aux->getData();
    aux->setData(data);
    return dataAux;
}

template <typename T>
bool Linkedlist<T>:: change(int pos1, int pos2)
{
    if (pos1 < 0 || pos2 < 0 || pos1>=size || pos2>=size)
    {
        return false;
    }
    if (pos1==pos2)
    {
        return true;
    }
    int posmen=(pos1<pos2) ? pos1 : pos2;
    int posmay=(pos1>pos2) ? pos1 : pos2;
    
    node<T> *aux1 = head, *aux2;
    for (int i=1; i<posmen; i++)
    {
        aux1=aux1->getNext();
    }
    aux2=aux1;
    for (int i=posmen+1; i<posmay; i++)
    {
        aux2=aux2->getNext();
    }
    
    T dataAux=aux1->getData();
    aux1->setData(aux2->getData());
    aux2->setData(dataAux);
    
    return true;
}

template <typename T>
void Linkedlist<T>::print()
{
    node<T> *aux=head;
    while (aux !=NULL)
    {
        cout << aux->getData() << " ";
        aux = aux->getNext();
    }
    cout << endl;
}

template <typename T>
T Linkedlist<T>::reverse(int pos1, int pos2, int pos) {
    node<T> *aux=head;
    if (aux==NULL) {
        return;
    }
    
    
}

template <typename T>
int Linkedlist<T>:: shift(T data, int pos1, int pos2, int pos)
{
    node<T> *aux=head;
    
    if (pos==2)
    {
        return addFirst();
    }
    else if(pos1==pos2)
    {
        aux->setNext();
    }
    else
    {
        return addLast();
    }
}

template <typename T>
int Linkedlist<T>:: spin(int pos)
{
    node<T> *aux = head;
    for (int i=0; i<=pos; i++) {
        for (int j=pos-1; j>pos; j--) {
            if (pos%3==0) {
                return addLast();
            }
            else
                if (pos%3==1) {
                    aux->setNext();
                }
            else
                if (pos%3==2) {
                    aux->getNext();
                }
            else
                if (pos%3==pos-1) {
                    return addFirst();
                }
        }
    }
}

template <typename T>
void Linkedlist<T>:: operator == (T data)
{
    int i, i2;
    if (data.i==data.i2) {
        cout << "Es igual" << endl;
    }
    else
        cout << "No es igual" << endl;

}

template <typename T>
void Linkedlist<T>::operator += (T data)
{
    int i, i2;
    node<T> *aux = head,*aux2;
    
    aux2=aux;
    aux=data.i + data.i2;
    aux->setData(aux2->getData());
    
    return aux;
}

template <typename T>
void Linkedlist<T>::operator += (Linkedlist<T> I)
{
    
}

template <typename T>
void Linkedlist<T>:: LinkedList(Linkedlist I)
{
    
}

template <typename T>
void Linkedlist<T>::operator=(T data) {
    
}



#endif /* secondnode_h */
