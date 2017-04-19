#ifndef NODE_H
#define NODE_H

#include "car.h"

typedef struct node_s{
	Car				data;
	struct node_s*	next;
}					Node;

#endif