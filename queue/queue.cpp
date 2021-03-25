#include <iostream>
#include <vector>
#include "queue.h"

Queue::Queue(){
    size=0;
}

void Queue::enqueue(int val){
    q.insert(q.end(), val);
    size++;
}

void Queue::dequeue(){
    if(size>0)
    {
        q.erase(q.begin());
        size--;
    }
    else{
        std::cout<<"Empty queue."<<std::endl;
    }
}

bool Queue::isEmpty(){
    return (size<=0);
}

int Queue::front(){
    if(size>0)
    {
        return q[0];
    }
    std::cout<<"Empty queue."<<std::endl;
    return -1;
}
