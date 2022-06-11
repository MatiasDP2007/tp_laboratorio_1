/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); // crea la lista en memoria

int ll_len(LinkedList* this); // calcula la longitud de la lista

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement); // agrega un elemento a la lista

void* ll_get(LinkedList* this, int index); // devuelve un pasajero de la lista

int ll_set(LinkedList* this, int index,void* pElement); // reemplaza un elemento de la lista en el indicde indicado

int ll_remove(LinkedList* this,int index); // elimina el elemento de la lista

int ll_clear(LinkedList* this); // borra los elementos de la lista

int ll_deleteLinkedList(LinkedList* this); // borra la lista de memoria

int ll_indexOf(LinkedList* this, void* pElement); // devuelve una posicion de la lista

int ll_isEmpty(LinkedList* this); // se fija si la lista esta vacia

int ll_push(LinkedList* this, int index, void* pElement); // agrega un nuevo elemento entre medio de dos

void* ll_pop(LinkedList* this,int index); // saca un elemento de la lista y lo devuelve

int ll_contains(LinkedList* this, void* pElement); // se fija si un elemento especifico esta contenido e nla lista

int ll_containsAll(LinkedList* this,LinkedList* this2); // se fija que cada elemento de la lista se encuentre en la otra lista

LinkedList* ll_subList(LinkedList* this,int from,int to); // devuelve una lista desde los puntos

LinkedList* ll_clone(LinkedList* this);  // clona una lista

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // ordena la lista
