#pragma once

typedef struct {
	DrugList* drugList;
} UndoList;

UndoList* createUndoList();
void destroyUndo(UndoList*);

void storeUndo(UndoList*, DrugList*);