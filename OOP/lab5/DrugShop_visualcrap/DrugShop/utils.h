#pragma once
#include "DrugList.h"


typedef int(*CompareFunction)(void *o1, void *o2);

void sort(DrugList*, CompareFunction,int);