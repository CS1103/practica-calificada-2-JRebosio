#include <iostream>
#include "LoadAndInsert.h"
#include "heap.h"
using namespace std;






int main()
{
    LinkedList<int> h;
    load_from("data.txt", h);
    cout << "heap" << endl;
    cout << h;
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.insert(10);
    cout << "heap" << endl; //1
    cout << h;//2
    cout << "heap" << endl;
    cout << h;//3
    cin >> h;
    cout << "heap" << endl;
    cout << h;//4
    insert(h, 100, 200);
    cout << "heap" << endl;
    cout << h; //5
    load_from("data.txt", h);
    cout << h; //6
    return 0;
}