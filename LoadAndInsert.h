//
// Created by Usuario on 10/10/2019.
//

#ifndef CS1103_PC2_201902_LOADANDINSERT_H
#define CS1103_PC2_201902_LOADANDINSERT_H

#include <fstream>
#include <istream>
#include <string>
#include "heap.h"
using namespace std;
template<typename X>
void load_from (const string& file_name, LinkedList<X>& hp){
    Node <X>* temp = hp.gethead();
    Node <X>* temp2 = nullptr;
    while (temp != nullptr) {
    temp2 = temp;
    temp = temp->next;
    delete temp2;
    }
    ifstream file(file_name);
    if(!file.is_open()) {
        cout<<"No hay archivo";
        return;
    }
    string num;
    int numero;
    while(getline(file,num)){
        numero=stoi(num);
        hp.insert(numero);
    }
}

template<typename X,typename T>
void insert (LinkedList<X>& ll, T first){
    ll.insert(first);
}

template<typename X,typename T, typename... Args >
void insert (LinkedList<X>& ll, T first, Args... items){
    ll.insert(first);
    insert(ll,items...);
}

#endif //CS1103_PC2_201902_LOADANDINSERT_H
