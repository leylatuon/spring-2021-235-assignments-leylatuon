#include <iostream>
#include <vector>
#include "queue.h"

using std::cout;
using std::endl;

int main(){

    Queue test;
    cout<<"isempty?: "<<test.isEmpty()<<endl;
    test.dequeue();
    cout<<"front: "<<test.front()<<endl;
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    cout<<"front: "<<test.front()<<endl;
    test.dequeue();
    cout<<"front: "<<test.front()<<endl;
    cout<<"isempty?: "<<test.isEmpty()<<endl;
    return 0;
}
