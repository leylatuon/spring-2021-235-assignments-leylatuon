#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

std::string BSTree::gds_helper(Node *n){
  if (n==nullptr){
    return "";
  } else {
    std::string right = gds_helper(n->getRight());
    std::string current = std::to_string(n->getData());
    std::string left = gds_helper(n->getLeft());

    return left + ", " + current + ", " + right; 
  }
};

std::string BSTree::get_debug_string(){
  return gds_helper(root);
};

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(25);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(7);
  n2->setLeft(n);
  
}
