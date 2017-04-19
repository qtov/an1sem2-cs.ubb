#include "undo.h"
#include "repository.h"
#include <stdio.h>
#include "controller.h"

/*
Creates the undo list
*/
Node			*createUndoList()
{
	return NULL;
}

/*
Creates a new node
*/
Node			*newNode(DrugList* list)
{
	Node	*p;

	p = malloc(sizeof(Node));

	p->data = list;
	p->next = NULL;
	return (p);
}

/*
Adds a node in front of the list
*/
void			unshiftNode(Node** undoList, DrugList* list)
{
	Node	*p;

	if (*undoList == NULL)
		*undoList = newNode(list);
	else
	{
		p = newNode(list);
		p->next = *undoList;
		*undoList = p;
	}
}

/* Debug
void			showNode(Node *start)
{
	Node	*p;

	p = start;
	while (p != NULL)
	{
		for (int i = 0; i<getSize(p->data); ++i) {
			Element o;
			o = getElement(p->data, i);
		}
		p = p->next;
	}
}
*/

/*
Adds a drug list to the undo list
*/
void			addListToUndo(Node** undoList, DrugList* drugList)
{
	DrugList* newDrugList = createDrugList();
	int i = 0;

	for ( ; i < getSize(drugList); ++i)
	{
		Element p;
		Element p_new;
		p = getElement(drugList, i);
		p_new = createDrug(getId(p), getName(p), getConcentration(p), getQuantity(p));
		addElement(newDrugList, p_new);
	}
	unshiftNode(undoList, newDrugList);
}

/*
Does the undo job
*/
Node*			doUndo(Node** list)
{
	Node *p;

	p = *list;
	if (p != NULL)
		*list = p->next;
	return (p);
}

/*
Destroys the undo list and everything in the world.
*/
void			destroyUndo(Node** list) {
	Node* p;

	p = *list;
	while (p != NULL)
	{
		Node *o;
		o = p;
		destroyDrugList(p->data);
		p = p->next;
		free(o);
	}
}