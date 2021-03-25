#pragma once

class Stack{
private:
std::vector<int> s;
int size;

public:
Stack();
void push(int val);
void pop();
int top();
bool isempty();
};
