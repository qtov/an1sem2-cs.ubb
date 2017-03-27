#pragma once
#include <stdlib.h>
#include "repository.h"
#include "undo.h"

typedef struct {
	DrugRepo* repo;
	Node *undo;
}DrugController;

//Drug controller data structure
DrugController* createController(DrugRepo*, Node*);
void destroyController(DrugController*);

//Controller utils
Drug* findByIdCtr(DrugController*, int);
Drug* findByNameCtr(DrugController*, char*);
void printDrugs(DrugController*);
int getDrugListSize(DrugRepo*);

//Drug controller functionalites
//task 1
int addDrug(DrugController*, int, char*, char*,int);
//task 2
void updateDrug(DrugController*, char* , char* ,int);
//task 3
void deleteDrugStock(DrugController* ctr, char *name);
//task 4
void sortDrugs(DrugController* ctr,int,int);
//task 5
void printFilteredDrugs(DrugController*, int, char*);

void undoC(DrugController*);