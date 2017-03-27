#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "userinterface.h"
#include "controller.h"


void printDrugsUI(DrugController* ctr) {
	//if there are no drugs in database then show a proper message
	if (getDrugListSize(ctr->repo) == 0) {
		printf("There are no drugs in the database!\n");
		return;
	}

	printf("Drug database :\n");
	printDrugs(ctr);
}

void addDrugUI(DrugController* ctr) {
	int id = 0;
	int quantity = 0;
	char name[256];
	char concentration[256];
	printf("New drug id = ");
	scanf("%d", &id);
	printf("New drug name = ");
	scanf("%s", name);
	printf("New drug concentration = ");
	scanf("%s", concentration);
	printf("New drug quantity = ");
	scanf("%d", &quantity);
	int databaseSize = getDrugListSize(ctr->repo);
	addDrug(ctr, id, name, concentration, quantity);
	if (databaseSize + 1 == getDrugListSize(ctr->repo))
		printf("Drug %s added to database!\n", name);

}

void updateDrugUI(DrugController* ctr) {
	//if there are no drugs in database then show a proper message
	if (getDrugListSize(ctr->repo) == 0) {
		printf("There are no drugs in the database!\n");
		return;
	}

	printDrugsUI(ctr);

	char name[256];
	char concentration[256];
	int runSubMenu = 1;
	while (runSubMenu) {
		int id = 0;
		printf("Insert id of drug you want to update : ");
		scanf("%d", &id);
		if (findByIdCtr(ctr,id) == NULL) {
			printf("The id doesen't exist in database!\n");
			break;
		}

		int cmd = 0;
		printf("What would you like to update?\n'1' - Only name\n'2' - Only concentration\n'3' - Both\n");
		printf("Insert choice : ");
		scanf("%d", &cmd);
		
		switch (cmd) {
		case 1:
			//Only name case
			printf("New name : ");
			scanf("%s", name);
			updateDrug(ctr, name, "", id);
			printf("Drug's name with id %d was successfully updated!\n", id);
			runSubMenu = 0;
			break;
		case 2:
			//Only concentration case
			printf("New concentration : ");
			scanf("%s", concentration);
			updateDrug(ctr, "", concentration, id);
			printf("Drug's concentration with id %d was successfully updated!\n", id);
			runSubMenu = 0;
			break;
		case 3:
			//Both case
			printf("New name : ");
			scanf("%s", name);
			printf("New concentration : ");
			scanf("%s", concentration);
			updateDrug(ctr, name, concentration, id);
			printf("Drug's name and concentration with id %d were successfully updated!\n", id);
			runSubMenu = 0;
			break;
		default:
			printf("Please insert a valid choice!");
			break;
		}
	}

}

void deleteDrugUI(DrugController* ctr) {
	//if there are no drugs in database then show a proper message
	if (getDrugListSize(ctr->repo) == 0) {
		printf("There are no drugs in the database!\n");
		return;
	}

	printDrugsUI(ctr);

	char name[256];
	printf("Insert name for drug you want to delete the stock : ");
	scanf("%s", name);

	deleteDrugStock(ctr, name);
	printf("Stock for %s deleted!\n", name);
}

void sortDrugsUI(DrugController* ctr) {
	//if there are no drugs in database then show a proper message
	if (getDrugListSize(ctr->repo) == 0) {
		printf("There are no drugs in the database!\n");
		return;
	}

	int runSubMenu = 1;
	while (runSubMenu) {
		printf("Sort criteria :\n'1' - Sort by name\n'2' - Sort by quantity\n'3' - Sort by id\n");
		printf("Choose criteria : ");
		int criteria = 0;
		scanf("%d", &criteria);

		if (criteria == 1 || criteria == 2 || criteria == 3) {
			printf("Sort order :\n'1' - Ascending sort\n'2' - Descending sort\n");
			printf("Choosen order : ");
			int order = 0;
			scanf("%d", &order);
			if (order == 1 || order == 2) {
				sortDrugs(ctr,criteria,order);
				printDrugsUI(ctr);
				runSubMenu = 0;
			}
		}
	}
	

}

void printUndoUI(DrugController* ctr) {
	showNode(ctr->undo);
	undoC(ctr);
}

void filterDrugsUI(DrugController* ctr) {
	//if there are no drugs in database then show a proper message
	if (getDrugListSize(ctr->repo) == 0) {
		printf("There are no drugs in the database!\n");
		return;
	}

	printf("Filter criteria :\n'1' - Maximum quantity\n'2' - Start with a letter\n");
	printf("Choose criteria : ");
	int criteria = 0;
	scanf("%d", &criteria);

	int maxQuantity = 0;
	char letter[1] = { '\0' };

	int runSubMenu = 1;

	switch (criteria) {
	case 1:
		printf("Maximum quantity value : ");
		scanf("%d", &maxQuantity);
		printFilteredDrugs(ctr, maxQuantity, letter);
		break;
	case 2:
		printf("Starting letter : ");
		scanf(" %c", letter);
		printFilteredDrugs(ctr, maxQuantity, letter);
		break;
	default:
		break;
	}
}

void showMenu() {
	printf("Available commands for drug store :\n");
	printf("'0' - Exit application\n");
	printf("'1' - Add new drug\n");
	printf("'2' - Update name/concentration\n");
	printf("'3' - Delete stock\n");
	printf("'4' - View sorted drug list\n");
	printf("'5' - Filter drug list\n");
	printf("'6' - Print drug list\n");
	printf("'7' - Undo\n");
}

void startUI(DrugController* ctr) {
	int runUI = 1;
	while (runUI) {
		showMenu();
		int cmd = 0;
		printf("Insert command : ");
		scanf("%d", &cmd);
		switch (cmd) {
		case 0:
			runUI = 0;
			break;
		case 1:
			addDrugUI(ctr);
			break;
		case 2:
			updateDrugUI(ctr);
			break;
		case 3:
			deleteDrugUI(ctr);
			break;
		case 4:
			sortDrugsUI(ctr);
			break;
		case 5:
			filterDrugsUI(ctr);
			break;
		case 6:
			printDrugsUI(ctr);
			break;
		case 7:
			printUndoUI(ctr);
			break;
		default:
			printf("Please insert a valid command!\n");
			break;
		}

	}
}