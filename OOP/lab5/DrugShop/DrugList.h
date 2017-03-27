#pragma once
#include "Drug.h"
typedef Drug* Element;

typedef struct {
	int size;
	int capacity;
	Element* data;
}DrugList;

//Drug list data structure
DrugList* createDrugList();
void ensureCapacity(DrugList*, int);
void destroyDrugList(DrugList*);

//Drug list functionalities
void addElement(DrugList*,Element);
int getSize(DrugList*);
Element getElement(DrugList*,int);
void setElement(DrugList*, int, Element);

