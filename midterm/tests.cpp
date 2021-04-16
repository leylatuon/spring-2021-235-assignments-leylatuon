#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "node.h"
#include "funcs.h"

TEST_CASE("msort") { //uses length and middle
	Node *n1 = new Node("99");
	Node *walker = n1;
	walker->setNext(new Node("77"));
	walker = walker->getNext();
	walker->setNext(new Node("55"));
	walker = walker->getNext();
	walker->setNext(new Node ("66"));
	walker = walker->getNext();
	walker->setNext(new Node("-11"));
	walker = walker->getNext();
	walker->setNext(new Node("33"));
    walker = walker->getNext();
    walker->setNext(new Node("44"));
	walker = walker->getNext();
	walker->setNext(new Node("88"));
	walker = walker->getNext();
	walker->setNext(new Node("-22"));
	walker = walker->getNext();
	walker->setNext(new Node("-11"));  
    
    Node *result=msort(n1);

    while (result->getNext() != nullptr) {
    CHECK(stoi(result->getData()) <= stoi(result->getNext()->getData()));
    result = result->getNext();
    }
}
/*
TEST_CASE("testing rotate") {
  Node *s1 = new Node("6");
  Node *s2 = new Node("-30");
  Node *s3 = new Node("0");
  Node *s4 = new Node("55");
  Node *s5 = new Node("22");
  Node *s6 = new Node("17");
  s1->setNext(s2);
  s2->setNext(s3);
  s3->setNext(s4);
  s4->setNext(s5);

  Node *temp = s1->rotate(s1, 5);
  CHECK(temp->getNext()->getNext()->getNext()->getNext()->getData() == s5->getData());
}*/
