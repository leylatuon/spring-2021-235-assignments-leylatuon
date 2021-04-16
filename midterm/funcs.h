#pragma once
#include <string>
#include "node.h"

int length(Node *l);
std::string toString(Node *head);
Node *middle(Node *head);
Node *msort(Node *head);
Node *merge(Node *a, Node *b);
Node *rotate(Node *head, int position);

