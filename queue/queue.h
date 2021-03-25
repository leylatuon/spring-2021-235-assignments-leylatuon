#pragma once

class Queue{
private:
    std::vector<int> q;
    int size;

public:
    Queue();
    void enqueue(int val);
    void dequeue();
    bool isEmpty();
    int front();
};
