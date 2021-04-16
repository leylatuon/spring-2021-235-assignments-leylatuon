#include <iostream>
#include <string>
#include "node.h"
#include "funcs.h"

using std::cout;
using std::string;
using std::stoi;

int length(Node *l){
	int ind = 0;
	while(l != nullptr){
		l = l->getNext();
        ind++;
	}
	return ind;
}

Node *middle(Node *head){
    int ind = 0;
	int mid = length(head)/2;
	Node *walker = head;
	while(ind != mid){
		walker = walker->getNext();
		ind++;
	}
	return walker;
}

Node *merge(Node *a, Node *b){
	Node *result = new Node();
	Node *initial = result;//first node is empty
	if(a == nullptr && b == nullptr){
		return nullptr;
	}

	while(a != nullptr && b != nullptr){
		result->setNext(new Node());
		result = result->getNext();
	    //need to convert to integers to compare
		if(stoi(a->getData()) < stoi(b->getData())){
			result->setData(a->getData());
			a = a->getNext();
		}
		else
		{
			result->setData(b->getData());
			b = b->getNext();
		}
	}

    //append rest
	while(a != nullptr)
	{
		result->setNext(new Node());
		result = result->getNext();
		result->setData(a->getData());
		a = a->getNext();
	}
	while(b != nullptr)
	{
		result->setNext(new Node());
		result = result->getNext();
		result->setData(b->getData());
		b = b->getNext();
	}

    return initial->getNext();
}


Node *msort(Node *head){
    //no need to sort if list empty/has 1 element
	if(length(head) <= 1){
		return head;
	}

	Node *left = head;
	Node *right = middle(head);
	Node *walker = head; 
	Node *mid = middle(head);

	while(walker->getNext() != mid){
		walker = walker->getNext();
	}
    //split list
	walker->setNext(nullptr);
    //recursively call sort
	left = msort(left);
	right = msort(right);
	return merge(left, right);
}

std::string toString(Node *head)
{
	std::string s = "";
	while(head != nullptr)
	{
		s +=head->getData() + "-->";
		head = head->getNext();
	}
	s+="nullptr";
	return s;
}

/*
Node *rotate(Node *head, int position){
}


*/
