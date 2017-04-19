#include <stdlib.h>
#include "DrugList.h"

//Drug list data structure

/**
	*Creates a new drug list and returns it.
*/
DrugList * createDrugList()
{
	DrugList* newList = malloc(sizeof(DrugList));
	newList->capacity = 5;
	newList->data = malloc(sizeof(Element) * newList->capacity);
	newList->size = 0;
	return newList;
}

/**
	*Reallocates the space for drug list and doubles the capacity of drug list given.
	*param: drugList - drug list to modify capacity (DrugList pointer dynamic vector)
		    newCapacity - new capacity to set for the drug list (integer)
*/
void ensureCapacity(DrugList* drugList,int newCapacity) {
	//alocate new space
	Element* newElements = malloc(sizeof(Element) * newCapacity);
	//copy old elements in new space
	for (int i = 0; i < drugList->capacity; ++i) {
		newElements[i] = drugList->data[i];
	}
	//dealloc old space
	free(drugList->data);
	//assign new space to drugList data
	drugList->data = newElements;
	drugList->capacity = newCapacity;
}

/**
	*Destroys a drug list type structure (deallocate memory).
	*param: drugList - drug list to destroy (DrugList pointer dynamic vector)
*/
void destroyDrugList(DrugList* drugList) {
	for (int i = 0; i < drugList->size; ++i) {
		destroyDrug(drugList->data[i]);
	}
	free(drugList->data);
	free(drugList);
}


//Drug list functionalities

/**
	*Add an element in drug list given.
	*param: drugList - drug list to add element (DrugList pointer dynamic vector)
		    elem - element we want to add to list (Element = Drug pointer)
*/
void addElement(DrugList* drugList, Element elem) {
	if (drugList->size == drugList->capacity) {
		ensureCapacity(drugList, drugList->capacity * 2);
	}
	drugList->data[drugList->size] = elem;
	drugList->size += 1;
}

/**
	*Returns the size of the drug list.
	*param: drugList - drug list to get size (DrugList pointer dynamic vector)
*/
int getSize(DrugList* drugList) {
	return drugList->size;
}

/**
	*Returns an Element = Drug type element from the given index in drug list.
	*param: drugList - drug list to get element (DrugList pointer dynamic vector)
		    index - index of element we want to get in list (integer)
*/
Element getElement(DrugList* drugList, int index) {
	return drugList->data[index];
}

/**
	*Set an Element = Drug type element on a given index
	*param: drugList - drug list to set element (DrugList pointer dynamic vector)
	        index - index of location we want to set the drug in list (integer)
*/
void setElement(DrugList* drugList, int index, Element element) {
	drugList->data[index] = element;
}