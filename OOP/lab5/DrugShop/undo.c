#include "repository.h"
#include "DrugList.h"
// #include "undo.h"

UndoList* createUndoList() {
	UndoList* newRepo = (UndoList*)malloc(sizeof(UndoList));
	newRepo->drugList = createDrugList();
	return newRepo;
}

void destroyRepo(UndoList* repo) {
	destroyDrugList(repo->drugList);
	free(repo);
}