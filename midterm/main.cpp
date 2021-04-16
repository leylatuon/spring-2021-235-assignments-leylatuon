#include <iostream>
#include "node.h"
#include "funcs.h"

using std::cout;
using std::endl;

int main(){
	Node *n1 = new Node("75");
	Node *walker = n1;
	walker->setNext(new Node("23"));
	walker = walker->getNext();
	walker->setNext(new Node("0"));
	walker = walker->getNext();
	walker->setNext(new Node ("98"));
	walker = walker->getNext();
	walker->setNext(new Node("-11"));
	walker = walker->getNext();
	walker->setNext(new Node("3"));
    walker = walker->getNext();
    walker->setNext(new Node("232"));
	walker = walker->getNext();
	walker->setNext(new Node("87"));
	walker = walker->getNext();
	walker->setNext(new Node("34"));
	walker = walker->getNext();
	walker->setNext(new Node("-65"));
    cout << "Unsorted: "<< toString(n1) << endl;
    n1=msort(n1);
	cout << "Sorted: " << toString(n1) << endl;
	cout << "Length: " << length(n1) << endl;
	cout << "Mid: " << middle(n1)->getData() << endl;

  	return 0;
}
