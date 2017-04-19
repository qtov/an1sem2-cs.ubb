#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repository.h"
// #include "undo.h"

/**
	*Creates a new repository and returns it.
*/
DrugRepo* createRepo(/*UndoList* undo*/) {
	DrugRepo* newRepo = (DrugRepo*)malloc(sizeof(DrugRepo));
	newRepo->drugList = createDrugList();
	return newRepo;
}

/**
	*Destroys a repository structure (deallocate memory).
	*param: repo - repository to destroy (DrugRepo pointer)
*/
void destroyRepo(DrugRepo* repo) {
	destroyDrugList(repo->drugList);
	free(repo);
}

/**
	*Store a Drug type element in repository database
	*param: repo - repository to store the drug element (DrugRepo pointer)
		   newDrug - drug we want to add to list (Drug pointer)
	*if drug was stored then it returns the database size
	*if there is an existing drug with the id of newDrug then it returns NULL
*/
void store(DrugRepo* repo, Drug* newDrug) {
	//check for double id
	Drug *existingDrug;
	for (int i = 0; i < getRepoSize(repo); ++i) {
		existingDrug = getElement(repo->drugList,i);
		if (getId(newDrug) == getId(existingDrug)) {
			printf("Id already exists in database!\n");
			return;
		}
	}
	addToUndo(repo->drugList);
	addElement(repo->drugList);
}

/**
	*Returns the size of the drug list from repository.
	*param: repo - the repository from where to get the drug list size(DrugRepo pointer)
*/
int getRepoSize(DrugRepo* repo) {
	return getSize(repo->drugList);
}

/**
	*Returns a drug list from a given repository.
	*param: repo - the repository from where to get all elements(DrugRepo pointer)
*/
DrugList* getAll(DrugRepo* repo) {
	return repo->drugList;
}

/**
	*Finds a drug from database by id
	*param : repo - drug repository (database)
			 id - id to search
	*returns the found drug entity or NULL if not found
*/
Drug* findById(DrugRepo* repo,int id) {
	for (int i = 0; i < getRepoSize(repo); ++i) {
		if (id == getId(getElement(repo->drugList, i))) {
			//if we found the drug then return it
			return getElement(repo->drugList, i);
		}
	}
	//if we didn't then return null pointer
	return NULL;
}

/**
	*Finds a drug from database by id
	*param : repo - drug repository (database)
	         name - name to search
	*returns the found drug entity or NULL if not found
*/
Drug* findByName(DrugRepo* repo, char *name) {
	for (int i = 0; i < getRepoSize(repo); ++i) {
		if (strcmp(name,getName(getElement(repo->drugList, i))) == 0) {
			//if we found the drug then return it
			return getElement(repo->drugList, i);
		}
	}

	return NULL;
}