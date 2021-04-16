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

    Node *n2 = new Node("6");
	walker = n2;
	walker->setNext(new Node("-30"));
	walker = walker->getNext();
	walker->setNext(new Node("0"));
	walker = walker->getNext();
	walker->setNext(new Node ("55"));
	walker = walker->getNext();
	walker->setNext(new Node("22"));
	walker = walker->getNext();
	walker->setNext(new Node("17"));
    walker = walker->getNext();
	walker->setNext(new Node("12"));
    cout<< "Not Rotated: "<< toString(n2)<<endl;
    n2=rotate(n2,4);
    cout<< "Rotated: " << toString(n2) <<endl;
  	return 0;
}
