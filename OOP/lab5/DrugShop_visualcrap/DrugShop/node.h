#pragma once
#include "DrugList.h"
#include <stdlib.h>

typedef struct node_s {
	DrugList		data;
	struct node_s*	next;
}					Node;