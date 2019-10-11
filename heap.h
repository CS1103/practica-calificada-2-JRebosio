//
// Created by rudri on 10/10/2019.
//

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::istringstream;
using std::stoi;
using std::string;
#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

template<typename T>
struct Node {
    T value;
    Node *next;
    Node(const T &value) : value(value), next(nullptr) { }
};


template<typename T, typename... Types>
class LinkedList{
public:
    LinkedList(){
        head= nullptr;
        tail= nullptr;
    }
    ~LinkedList(){
        if (head == nullptr) return;
        Node<T>* temp = head;
        Node<T>* temp2 = nullptr;
        while (temp != nullptr) {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head=nullptr;
    }

    T getmax(){
        Node<T>* temp = head;
        T m=0;
        while(temp!=nullptr){
            if(temp->value > m) m=temp->value;
            temp=temp->next;
        }
        return m;
    }

    void erase(){
        if (head == nullptr) return;
        Node<T>* temp = head;
        Node<T>* temp2 = nullptr;
        while (temp != nullptr) {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head=nullptr;
    }



    void insert(T value){
        Node<T>* temp = new Node<T>(value);
            if (head!=nullptr) {
                tail->next=temp;
                tail=temp;
            }
            else{
                tail=temp;
                head=temp;
            }
    };

/*
    void insert(T first_arg,Types... arg) {
            insert(first_arg);
            insert(arg...);
    }
*/


    template<typename X>
    friend istream& operator>> (istream& in,LinkedList<X> &ll);

    template<typename X>
    friend ostream& operator<< (ostream& out,  const LinkedList<X>& ll);

    Node<T>* head;
    Node<T>* tail;
};
template<typename X>
ostream& operator<< (ostream& out, const LinkedList<X>& ll){
    Node<X>* temp= ll.head;
    while(temp!= nullptr) {
        out <<temp->value ;
        out<< " ";
        temp=temp->next;
    }
    return out;
};


template<typename X>
istream &operator>>(istream &in, LinkedList<X> &ll) {
    X ss;
    in >> ss;
    ll.insert(ss);
    return in;
}


#endif //CS1103_PC2_201902_HEAP_H
