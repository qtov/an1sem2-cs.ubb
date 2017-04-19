#pragma once
typedef struct {
	int id;
	int quantity;
	char* name;
	char* concentration;
}Drug;


//Drug entity data structure
Drug* createDrug(int, char*, char*, int);
void destroyDrug(Drug*);


//Drug functionalities
int getId(Drug*);
char* getName(Drug*);
char* getConcentration(Drug*);
int getQuantity(Drug*);

void setId(Drug*,int);
void setName(Drug*, char*);
void setConcentration(Drug*, char*);
void setQuantity(Drug*, int);

int compareByName(Drug* , Drug* );
int compareByQuantity(Drug* , Drug* );
int	compareById(Drug*, Drug*);