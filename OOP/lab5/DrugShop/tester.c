#include <assert.h>
#include <string.h>
#include "tester.h"
#include "Drug.h"
#include "DrugList.h"
#include "repository.h"
#include "controller.h"

//Drug entity tests
void createDrugTest(){
	Drug* newDrug = createDrug(1, "Algocalmin", "15%", 100);
	assert(newDrug->id == 1);
	assert(strcmp(newDrug->name,"Algocalmin") == 0);
	assert(strcmp(newDrug->concentration,"15%") == 0);
	assert(newDrug->quantity == 100);
	destroyDrug(newDrug);

	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	assert(newDrug2->id == 2);
	assert(strcmp(newDrug2->name, "Borenar") == 0);
	assert(strcmp(newDrug2->concentration, "20%") == 0);
	assert(newDrug2->quantity == 200);
	destroyDrug(newDrug2);
}


//Drug list tests
void createDrugListTest() {
	DrugList* newList = createDrugList();
	assert(newList->size == 0);
	assert(newList->capacity == 5);
	destroyDrugList(newList);
}

void addDrugListTest() {
	DrugList* newList = createDrugList();
	Drug* newDrug1 = createDrug(1, "Algocalmin", "15%", 100);
	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	Drug* newDrug3 = createDrug(3, "Paracetamol", "10%", 150);
	Drug* newDrug4 = createDrug(4, "Strepsils", "60%", 300);
	addElement(newList, newDrug1);
	addElement(newList, newDrug2);
	addElement(newList, newDrug3);
	addElement(newList, newDrug4);
	assert(getSize(newList) == 4);
	assert(newList->capacity == 5);
	Drug* newDrug5 = createDrug(5, "Tusin", "80%", 50);
	Drug* newDrug6 = createDrug(6, "Ibubrofen", "40%", 25);
	addElement(newList, newDrug5);
	addElement(newList, newDrug6);
	assert(getSize(newList) == 6);
	assert(newList->capacity == 10);
	destroyDrugList(newList);
}

void getDrugListTest() {
	DrugList* newList = createDrugList();
	Drug* newDrug1 = createDrug(1, "Algocalmin", "15%", 100);
	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	Drug* newDrug3 = createDrug(3, "Paracetamol", "10%", 150);
	Drug* newDrug4 = createDrug(4, "Strepsils", "60%", 300);
	addElement(newList, newDrug1);
	addElement(newList, newDrug2);
	addElement(newList, newDrug3);
	addElement(newList, newDrug4);
	Drug* drug1 = getElement(newList, 0);
	Drug* drug2 = getElement(newList, 1);
	Drug* drug3 = getElement(newList, 2);
	Drug* drug4 = getElement(newList, 3);
	assert(getId(drug1) == 1);
	assert(getId(drug2) == 2);
	assert(getId(drug3) == 3);
	assert(getId(drug4) == 4);
	assert(strcmp(drug1->name, "Algocalmin") == 0);
	assert(strcmp(drug2->name, "Borenar") == 0);
	assert(strcmp(drug3->name, "Paracetamol") == 0);
	assert(strcmp(drug4->name, "Strepsils") == 0);
	assert(strcmp(drug1->concentration, "15%") == 0);
	assert(drug1->quantity == 100);
	destroyDrugList(newList);
}

//Repository tests
void createRepositoryTest() {
	DrugRepo* newRepo = createRepo();
	assert(getSize(newRepo->drugList) == 0);
	assert(newRepo->drugList->capacity == 5);
	destroyRepo(newRepo);
}

void storeDrugTest() {
	DrugRepo* newRepo = createRepo();
	Drug* newDrug1 = createDrug(1, "Algocalmin", "15%", 100);
	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	Drug* newDrug3 = createDrug(3, "Paracetamol", "10%", 150);
	Drug* newDrug4 = createDrug(4, "Strepsils", "60%", 300);
	store(newRepo, newDrug1);
	store(newRepo, newDrug2);
	store(newRepo, newDrug3);
	store(newRepo, newDrug4);
	assert(getSize(newRepo->drugList) == 4);
	Drug* drug1 = getElement(newRepo->drugList, 0);
	assert(getId(drug1) == 1);
	assert(strcmp(drug1->name, "Algocalmin") == 0);
	assert(strcmp(drug1->concentration, "15%") == 0);
	assert(drug1->quantity == 100);
	destroyRepo(newRepo);
}

void getSizeAndListTest() {
	DrugRepo* newRepo = createRepo();
	Drug* newDrug1 = createDrug(1, "Algocalmin", "15%", 100);
	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	Drug* newDrug3 = createDrug(3, "Paracetamol", "10%", 150);
	Drug* newDrug4 = createDrug(4, "Strepsils", "60%", 300);
	store(newRepo, newDrug1);
	store(newRepo, newDrug2);
	store(newRepo, newDrug3);
	store(newRepo, newDrug4);
	assert(getSize(newRepo->drugList) == 4);
	DrugList* allDrugs = getAll(newRepo);
	assert(getSize(allDrugs) == 4);
	destroyRepo(newRepo);
}


//Controller tests
void createControllerTest() {
	DrugRepo* newRepo = createRepo();
	Drug* newDrug1 = createDrug(1, "Algocalmin", "15%", 100);
	Drug* newDrug2 = createDrug(2, "Borenar", "20%", 200);
	Drug* newDrug3 = createDrug(3, "Paracetamol", "10%", 150);
	Drug* newDrug4 = createDrug(4, "Strepsils", "60%", 300);
	store(newRepo, newDrug1);
	store(newRepo, newDrug2);
	store(newRepo, newDrug3);
	store(newRepo, newDrug4);
	DrugController* newController = createController(newRepo);
	assert(getRepoSize(newController->repo) == 4);
	destroyController(newController);
}

void addDrugTest() {
	DrugRepo* newRepo = createRepo();
	DrugController* newController = createController(newRepo);
	addDrug(newController,1,"Algocalmin","15%",100);
	assert(getRepoSize(newController->repo) == 1);
	DrugList* drugs = getAll(newController->repo);
	Drug* drug1 = getElement(drugs, 0);
	assert(getId(drug1) == 1);
	assert(strcmp(drug1->name, "Algocalmin") == 0);
	assert(strcmp(drug1->concentration, "15%") == 0);
	assert(drug1->quantity == 100);
	destroyController(newController);
}

void updateDrugTest() {
	DrugRepo* newRepo = createRepo();
	DrugController* newController = createController(newRepo);
	

	destroyController(newController);
}

//Run all tests
void runAllTests() {
	createDrugTest();
	createDrugListTest();
	addDrugListTest();
	getDrugListTest();
	createRepositoryTest();
	storeDrugTest();
	getSizeAndListTest();
	createControllerTest();
	addDrugTest();
}