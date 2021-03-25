#include <iostream>
#include <vector>
#include "stack.h"

Stack::Stack(){
    size=0;
}

void Stack::push(int val){
    s.insert(s.begin(),val);
    size++;
}
void Stack::pop(){
    if(size>0)
    {
        s.erase(s.begin());
        size--;
    }
    else{
        std::cout<<"Empty stack."<<std::endl;
    }
}
int Stack::top(){
    if(size>0){
        return s[0];
    }
        std::cout<<"Empty stack"<<std::endl;
        return -1;
}
bool Stack::isEmpty(){
    return (size<=0);
}

