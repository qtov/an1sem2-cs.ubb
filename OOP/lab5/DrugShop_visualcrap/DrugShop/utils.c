#include <stdlib.h>
#include "utils.h"
#include "DrugList.h"
/**
	* Sorts in place a drug list
	* param : list - drug list to sort
	          cmpf - the relation after which the sort is made
			  reverse - value which represents ascending/descending order for sort
	precondition : reverse must be 0 for ascending order sort
				   reverse must be 1 for descending order sort
			  
*/
void sort(DrugList* list, CompareFunction cmpF, int reverse) {
	if (reverse == 0){
		for (int i = 0; i < getSize(list); i++) {
			for (int j = i + 1; j < getSize(list); j++) {
				if (cmpF(getElement(list, i), getElement(list, j)) > 0) {
					//swap

					void* aux = getElement(list, i);
					setElement(list, i, getElement(list, j));
					setElement(list, j, aux);
				}
			}
		}
	}
	if (reverse == 1) {
		for (int i = 0; i < getSize(list); i++) {
			for (int j = i + 1; j < getSize(list); j++) {
				if (cmpF(getElement(list, i), getElement(list, j)) < 0) {
					//swap
					void* aux = getElement(list, i);
					setElement(list, i, getElement(list, j));
					setElement(list, j, aux);
				}
			}
		}
	}
}