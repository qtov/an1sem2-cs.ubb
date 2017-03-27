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
			printf("Id:%d Name:%s Concentration:%s Quantity:%d\n", getId(o), getName(o), getConcentration(o), getQuantity(o));
		}
		printf(" -> \n");
		p = p->next;
	}
	printf("\n------------------------------\n");
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
		//printf("Id:%d Name:%s Concentration:%s Quantity:%d\n", getId(p_new), getName(p_new), getConcentration(p_new), getQuantity(p_new));
	}
	unshiftNode(undoList, newDrugList);
	Node* p = *undoList;
	showNode(p);
	//i = 0;
	/*while (p != NULL)
	{
		Element o;
		o = getElement(p->data, i);
		printf("%d, %s -> ", getSize(p->data), getName(o));
		p = p->next;
		++i;
	}*/
	//printf("\n");
	//showNode(*undoList);
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