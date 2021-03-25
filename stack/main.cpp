#include <iostream>
#include <vector>
#include "stack.h"

int main()
{
    Stack test;
    std::cout<<"is it empty?: "<<test.isempty()<<std::endl;
    test.push(3);
    test.push(2);
    test.push(1);
    std::cout<<"is it empty?: "<<test.isempty()<<std::endl;
    std::cout<<"what is on top?: "<<test.top()<<std::endl;
    test.pop();
    std::cout<<"what is on top?: "<<test.top()<<std::endl;

    return 0;
}
