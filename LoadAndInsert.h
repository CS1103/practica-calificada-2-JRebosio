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
    hp.erase();
    ifstream file(file_name);
    if(!file.is_open()) {
        cout<<"No hay archivo";
        return;
    }
    string num;
    int numero;
    while(getline(file,num,'\n')){
        numero=stoi(num);
        hp.insert(numero);
    }
}

template<typename T>
void insert (LinkedList<T>& ll, T first){
    ll.insert(first);
}

template<typename T, typename... Args >
void insert (LinkedList<T>& ll, T first, Args... items){
    ll.insert(first);
    insert(ll,items...);
}

#endif //CS1103_PC2_201902_LOADANDINSERT_H
