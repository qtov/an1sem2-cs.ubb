#pragma once
#include "DrugList.h"
#include "repository.h"
#include <stdlib.h>

typedef struct node_s {
	DrugList*		data;
	struct node_s*	next;
}					Node;

Node*	createUndoList();
Node*	newNode(DrugList*);
void	addListToUndo(Node**, DrugList*);
//void	showNode(Node *start); Debug
void	unshiftNode(Node** undoList, DrugList* list);
Node*	doUndo(Node**);