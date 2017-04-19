#pragma once
#include "DrugList.h"
#include "undo.h"
typedef struct {
	DrugList* drugList;
}DrugRepo;

//Drug repository data structure
DrugRepo* createRepo();
void destroyRepo(DrugRepo*);

//Drug repository functionalites
void store(DrugRepo* , Drug* );
int getRepoSize(DrugRepo* );
DrugList* getAll(DrugRepo*);
Drug* findById(DrugRepo*, int);
Drug* findByName(DrugRepo*, char*);

