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

TEST_CASE("Rotate") {
    Node *n1 = new Node("6");
    Node *n2 = new Node("-30");
    Node *n3 = new Node("0");
    Node *n4 = new Node("55");
    Node *n5 = new Node("22");
    Node *n6 = new Node("17");
    Node *n7 = new Node("12");
    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(n4);
    n4->setNext(n5);
    n5->setNext(n6);
    n6->setNext(n7);

    Node *result = rotate(n1, 4);
    CHECK(result->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getData() == n4->getData());
    //new end is node at position
    //new head is node after position
    CHECK(result->getData() == n5->getData());
}
