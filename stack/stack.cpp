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
    s.erase(s.begin());
    size--;
}
int Stack::top(){
    return s[0];
}
bool Stack::isempty(){
    return (size<=0);
}

