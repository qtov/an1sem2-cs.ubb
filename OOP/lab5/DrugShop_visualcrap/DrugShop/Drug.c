#include "Drug.h"
#include <string.h>
#include <stdlib.h>


//Create Drug

/**
	*Creates a new drug and returns it.
	*param: id - id for drug (integer)
		    name - drug name (char pointer)
		    concentration - drug concentration (char pointer)
		    quantity - drug quantity (integer)
	*returns the new drug entity
*/
Drug * createDrug(int id, char *name, char *concentration, int quantity)
{
	Drug* newDrug = (Drug*)malloc(sizeof(Drug));

	newDrug->id = id;
	newDrug->quantity = quantity;

	newDrug->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newDrug->name, name);

	newDrug->concentration = (char*)malloc(sizeof(char) *(strlen(concentration) + 1));
	strcpy(newDrug->concentration, concentration);

	return newDrug;
}


//Drug get functions

/**
	*Returns the given drug's id
	*param: drug - drug entity (Drug pointer)
*/
int getId(Drug* drug) {
	return drug->id;
}

/**
	*Returns the given drug's name
	*param: drug - drug entity (Drug pointer)
*/
char* getName(Drug* drug) {
	return drug->name;
}

/**
	*Returns the given drug's concentration
	*param: drug - drug entity (Drug pointer)
*/
char* getConcentration(Drug* drug) {
	return drug->concentration;
}

/**
	*Returns the given drug's quantity
	*param: drug - drug entity (Drug pointer)
*/
int getQuantity(Drug* drug) {
	return drug->quantity;
}

//Drug set functions

/**
	*Sets the given drug's id to the new id given
	*param: drug - drug entity (Drug pointer)
		    newId - new id to assign for drug (integer)
*/
void setId(Drug* drug, int newId) {
	drug->id = newId;
}

/**
	*Sets the given drug's name to the new name given
	*param: drug - drug entity (Drug pointer)
		    newName - new name to assign for drug (char pointer)
*/
void setName(Drug* drug, char* newName) {
	free(drug->name);
	drug->name = (char*)malloc(sizeof(char) * (strlen(newName) + 1));
	strcpy(drug->name, newName);
}

/**
	*Sets the given drug's concentration to the new concentration given
	*param: drug - drug entity (Drug pointer)
		    newConcentration - new concentration to assign for drug (char pointer)
*/
void setConcentration(Drug* drug, char* newConcentration) {
	free(drug->concentration);
	drug->concentration = (char*)malloc(sizeof(char) * (strlen(newConcentration) + 1));
	strcpy(drug->concentration, newConcentration);
}

/**
	*Sets the given drug's quantity to the new quantity given
	*param: drug - drug entity (Drug pointer)
		    newId - new quantity to assign for drug (integer)
*/
void setQuantity(Drug* drug, int newQuantity) {
	drug->quantity = newQuantity;
}

/**
	*Compare function.
	*Compare two drugs after name.
	*param : drug1 - First drug entity
			 drug2 - Second drug entity
	*returns : 0 - if drug1's name is qual to drug2's name
			   1 - if drug1's name is 'bigger' than drug2's name
			   -1 - if drug1's name is 'lower' than drug2's name
*/
int compareByName(Drug* drug1, Drug* drug2) {
	return strcmp(getName(drug1), getName(drug2));
}

/*
	*Compare function.
	*Compare two drugs after quantity.
	*param : drug1 - First drug entity
			 drug2 - Second drug entity
	*returns : 0 - if drug1's quantity is qual to drug2's quantity
			   1 - if drug1's quantity is greater than drug2's quantity
			   -1 - if drug1's quantity is less than drug2's quantity
*/
int compareByQuantity(Drug* drug1, Drug* drug2) {
	int pr1 = getQuantity(drug1);
	int pr2 = getQuantity(drug2);
	if (pr1 == pr2) {
		return 0;
	}
	if (pr1 > pr2) {
		return 1;
	}
	return -1;
}

int compareById(Drug* drug1, Drug* drug2) {
	int pr1 = getId(drug1);
	int pr2 = getId(drug2);
	if (pr1 == pr2) {
		return 0;
	}
	if (pr1 > pr2) {
		return 1;
	}
	return -1;
}

//Destroy Drug

/**
	*Free the memory allocated for a drug entity
	*param: drug - drug entity (Drug pointer)
*/
void destroyDrug(Drug* drug) {
	free(drug->name);
	free(drug->concentration);
	free(drug);
}