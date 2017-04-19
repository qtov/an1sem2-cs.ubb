#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "repository.h"
#include "utils.h"
#include "Drug.h"

/**
	*Create and initialise a controller.
	*param : repo - repository for controller
	*returns the controller created
*/
DrugController* createController(DrugRepo *repo) {
	DrugController* ctr = (DrugController*)malloc(sizeof(DrugController));
	ctr->repo = repo;
	return ctr;
}

/**
	*Destroy controller (deallocate memory for controller)
	*param : ctr - controller to destroy
*/
void destroyController(DrugController* ctr) {
	destroyRepo(ctr->repo);
	free(ctr);
}


/**
	*Finds a drug by id from controller's repository
	*this function use the findById function from repository
	*param: ctr - controller
	        id - id for search
	*returns the found drug (result of findById function)
*/
Drug* findByIdCtr(DrugController* ctr, int id) {
	return findById(ctr->repo, id);
}

/**
	*Finds a drug by name from controller's repository
	*this function use the findByName function from repository
	*param: ctr - controller
	        name - name for search
	*returns the found drug (result of findById function)
*/
Drug* findByNameCtr(DrugController* ctr, char* name) {
	return findByName(ctr->repo, name);
}

/**
	*Print all drugs from database
	*param: ctr - Drug controller
*/
void printDrugs(DrugController* ctr) {
	DrugList* allDrugs = getAll(ctr->repo);
	(void)allDrugs;
	for (int i = 0; i<getRepoSize(ctr->repo); ++i) {
		Drug* drug = getElement(ctr->repo->drugList, i);
		int id = getId(drug);
		char* name = getName(drug);
		char* concentration = getConcentration(drug);
		int quantity = getQuantity(drug);
		printf("Id:%d Name:%s Concentration:%s Quantity:%d\n", id, name, concentration, quantity);
	}
}

/**
	*Get drug list size from database
	*param: repo - Drug repository (database)
*/
int getDrugListSize(DrugRepo* repo) {
	return getRepoSize(repo);
}


/**
  *Add a drug tot the store
  *param: id - id of drug (integer)
	      name - name of drug (char pointer)
          concentration - concentration of drug (char pointer)
          quantity - quantity of drug in store (integer)
  *return number of drugs in the store
*/
int addDrug(DrugController* ctr, int id, char* name, char* concentration, int quantity) {
	Drug* newDrug = createDrug(id, name, concentration, quantity);
	store(ctr->repo, newDrug);
	return getRepoSize(ctr->repo);
}

/**
	*Updates a drug's name and concentration
	*param: name - new name (char pointer)
		    concentration - new concentration (char pointer)
	        id - id of drug to update
*/
void updateDrug(DrugController* ctr, char *name, char *concentration, int id) {
	Drug* drug = findById(ctr->repo, id);
	//Only name update
	if (strcmp(concentration, "") == 0) {
		setName(drug, name);
		return;
	}
	//Only concentration update
	if (strcmp(name, "") == 0) {
		setConcentration(drug, concentration);
		return;
	}
	//Both update
	setName(drug, name);
	setConcentration(drug, concentration);
}

/**
	*Deletes the stock(quantity) of a drug with the name given
	*param: ctr - Drug controller
	        name - name of drug to delete stock (char pointer)
	*if drug not found then it prints an error message
*/
void deleteDrugStock(DrugController* ctr, char *name) {
	Drug* drug = findByNameCtr(ctr, name);
	if (drug == NULL) {
		printf("Drug not found in database!\n");
		return;
	}
	setQuantity(drug, 0);
}


/**
	*Sorts the entire drug database after a specified criteria and order
	*param : criteria - integer, value transalte for name or quantity
		     order - integer, value transalte for ascending or descending
	*preconditions : criteria and order must have values of 1 or 2 
*/
void sortDrugs(DrugController* ctr,int criteria,int order) {
	//assuming that criteria and order are corectly transmited from UI
	//if criteria is 1 then the sort is made after drug names

	DrugList* drugList = getAll(ctr->repo);
	if (criteria == 1){
		order -= 1;
		sort(drugList, compareByName, order);
	}
	//if criteria is 2 then the sort is made after drug quantity
	else if (criteria == 2) {
		order -= 1;
		sort(drugList, compareByQuantity, order);
	}
	else if (criteria == 3) {
	//if criteria is 3 then the sort is made after drug id
		order -= 1;
		sort(drugList, compareById, order);
	}
}

/**
	*Prints a drug list with filter
	*param: ctr - Drug controller
			maxQuantity - a value which represents the maximum quantity a drug can have to be printed
			letter - a letter which represents the starting letter a drug must have to be printed
	*preconditions : If we want to filter by quantity then letter should be '\0'
					 If we want to filter by letter then maxQuantity should be 0
*/
void printFilteredDrugs(DrugController* ctr,int maxQuantity,char *letter) {
	DrugList* drugList = getAll(ctr->repo);
	Drug* drug;

	//print filter by maximum quantity
	if (maxQuantity != 0) {
		for (int i = 0; i < getRepoSize(ctr->repo); ++i) {
			drug = getElement(drugList, i);
			if (getQuantity(drug) <= maxQuantity) 
				printf("Id:%d Name:%s Concentration:%s Quantity:%d\n", getId(drug), getName(drug), getConcentration(drug), getQuantity(drug));
		}
	}
	
	//print filter by starting letter of drug
	if (letter[0] != '\0') {
		char* drugName;
		char firstLetter[1];
		for (int i = 0; i < getRepoSize(ctr->repo); ++i) {
			drug = getElement(drugList, i);
			drugName = getName(drug);
			strncpy(firstLetter, drugName, 1);
			if (firstLetter[0]==letter[0])
				printf("Id:%d Name:%s Concentration:%s Quantity:%d\n", getId(drug), getName(drug), getConcentration(drug), getQuantity(drug));
		}
	}
}