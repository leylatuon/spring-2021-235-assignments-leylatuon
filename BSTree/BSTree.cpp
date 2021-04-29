#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

// traversal visits every node (O(n) runtime)
 /*
     *  pre-order traversal
     
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree
      a = std::to_string(n->getData());
      b =  traverse(n->getLeft());
      c =  traverse(n->getRight());
      * post-order traversal
      1. recurse to left subtree
      2. recurse to right subtree
      3. process the node
      
      a =  traverse(n->getLeft());
      b =  traverse(n->getRight());
      c = std::to_string(n->getData());
    */

    /*  
	in-order traversal
	1. recurse left subtree
	2. process node
	3. recurse right subtree
     */
std::string BSTree::traverse(Node *n){
  if (n==nullptr){
    return "";
  } else {
    std::string right = traverse(n->getRight());
    std::string current = std::to_string(n->getData());
    std::string left = traverse(n->getLeft());

    return left + ", " + current + ", " + right; 
  }
};

std::string BSTree::get_debug_string(){
    return traverse(root);
};

void BSTree::setup(){
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setRight(n);
    n = new Node(30);
    root->setRight(n);
    n = new Node (40);
    root->getRight()->setRight(n);
    n = new Node (8);
    root->setLeft(n);
}

int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    if (t->getData() == value){
      return value;
    } else if (t->getData() > value){
      t = t->getLeft();
    } else {
      t = t->getRight();
    }

  }
  // if we ever get here, t got to nullptr
  // so the value isn't in the tree.
  throw -1;

  return 0;
}

int BSTree::searchR(int value, Node *n){ //search but recursive
    if(n==nullptr){
    throw -1;
    }

    int x = n->getData();
    if (x == value){
        return value;
    } 
    else if(x>value){
        return searchR(value, n->getLeft());
    }
    else{
        return searchR(value, n->getRight());
    }
}

int BSTree::searchR(int value){
    return searchR(value, root);
} 

void BSTree::insert(int value){
  Node *n = new Node(value);

  if (root==nullptr){
    root = n;
    return;
  }

  Node *t = root; // to find the value's position
  Node *t2; // pointer to piggyback (one behind)

  while (t != nullptr){
    t2 = t;

    if (t->getData() < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
  }
  // at this point t points to nullptr but t2 points to the node before.

  if (value < t2->getData()){
    t2->setLeft(n);
  } else {
    t2->setRight(n);
  }
}

int BSTree::treesum(Node *root){
    //similar to transversal
    if (root == nullptr){
        return 0;
    }
    return (root->getData() + treesum(root->getRight()) + treesum(root->getLeft()));
}

int BSTree::treesum(){
    return treesum(root);
}

void BSTree::deleter(int val){
    return deleter(root, root, val);
}

void BSTree::deleter(Node *curr, Node *prev, int val){
/*  Case 1: delete a leaf/node has no children
    Case 2: node has one child -> point parent to child
    Case 3: node has two children -> go right as far as possible
            and take the lowest value and set that to be the new node   
*/
    if(curr == nullptr){
        return;
    }

    if(curr->getData() < val)
    {
        deleter(curr->getRight(), curr, val);
    }
    else if(curr->getData() > val)
    {
        deleter(curr->getLeft(), curr, val);
    }
    else{ //case 1 no children
        if((curr->getLeft() == nullptr) && (curr->getRight() == nullptr))
        {
            if(prev->getLeft() == curr)
            {
                prev->setLeft(nullptr);
            }
            else
            {
                prev->setRight(nullptr);
            }
        delete curr;
        }
        else if((curr->getLeft() == nullptr) && (curr->getRight() != nullptr))
        {
            //case 2 one child on right
            prev->setRight(curr->getRight());
            delete curr;
        }
        else if((curr->getLeft() != nullptr) && (curr->getRight() == nullptr))
        {
            //case 2 one child on left
            prev->setLeft(curr->getLeft());
            delete curr;
        }
        else{
            Node *temp = root->getRight();
            Node *parent = root;
            while(temp->getLeft() != nullptr)
            {
                parent = temp;
                temp = temp->getLeft();
            }
            if(parent!= root)
            {
                parent->setLeft(temp->getRight());
            }
            else
            {
                parent->setRight(temp->getLeft());
            }
            root->setData(temp->getData());
            delete temp;
        }
  }
}


int BSTree::countNodes(){
  return countNodes(root);
}

int BSTree::countNodes(Node *curr){
  if(curr==nullptr)
  {
    return 0;
  }
  return (countNodes(curr->getLeft()) + countNodes(curr->getRight()) + 1);
}

int BSTree::countLeaves(){
  return countLeaves(root);
}

int BSTree::countLeaves(Node *curr){
  if(curr == nullptr)
  {
    return 0;
  }
  else if(curr->getLeft() == nullptr && curr->getRight() == nullptr)
  {
    return 1;
  }
  return (countLeaves(curr->getLeft()) + countLeaves(curr->getRight()));
}

int BSTree::height(){
  return height(root);
}

int BSTree::height(Node *curr){
  if(curr == nullptr)
  {
    return 0;
  }
  if(height(curr->getLeft()) > height(curr->getRight()))
  {
    return (height(curr->getLeft()) + 1);
  }
  else
  {
    return (height(curr->getRight()) + 1);
  }
}

int BSTree::levelSum(int level){
  return levelSum(root, level, 0);
}

int BSTree::levelSum(Node *curr, int level, int currlevel){
  if(curr == nullptr){
    return 0;
  }else if(currlevel < level){
    return levelSum(curr->getLeft(), level, currlevel+1) + 
        levelSum(curr->getRight(), level, currlevel+1);
  }else{
    return curr->getData() + levelSum(curr->getLeft(), level, currlevel + 1) 
        + levelSum(curr->getRight(), level, currlevel + 1);
  }
}
