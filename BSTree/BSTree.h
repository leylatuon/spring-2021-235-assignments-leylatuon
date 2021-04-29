#pragma once
#include <stdio.h>

class BSTree{
private:
    Node *root;
public:
    BSTree();
    std::string get_debug_string();
    std::string traverse(Node *n);
    void setup();
    int search(int value);
    int searchR(int value);
    int searchR(int value, Node *n);

    void insert(int value);
    int treesum(Node *root);
    int treesum();

    void deleter(int val);
    void deleter(Node *curr, Node *prev, int val);

    int countNodes();
    int countNodes(Node *curr);

    int countLeaves();
    int countLeaves(Node *curr);

    int height();
    int height(Node *curr);

    int levelSum(int level);
    int levelSum(Node *curr, int level, int currlevel);
   };
