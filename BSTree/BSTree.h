#pragma once
#include <stdio.h>

class BSTree{
private:
    Node *root;
public:
    BSTree();
    std::string get_debug_string();
    void insert(int d);
    std::string gds_helper(Node *n);
    void setup();

};
