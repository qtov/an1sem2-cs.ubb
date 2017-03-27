#include "undo.h"
#include "repository.h"
#include <stdio.h>
#include "controller.h"

Node * createUndoList()
{
	return NULL;
}

Node			*newNode(DrugList* list)
{
	Node	*p;

	p = malloc(sizeof(Node));

	p->data = list;
	p->next = NULL;
	return (p);
}

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
	Node* p = *undoList;
	showNode(p);
}

Node* doUndo(Node** list)
{
	Node *p;

	p = *list;
	if (p != NULL)
		*list = p->next;
	return (p);
}

void destroyUndo(Node** list) {
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