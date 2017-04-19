#ifndef NODE_H
#define NODE_H

#include "Activity.h"

template <typename T>
struct Node {
	T val;
	Node* urm;
};

#endif