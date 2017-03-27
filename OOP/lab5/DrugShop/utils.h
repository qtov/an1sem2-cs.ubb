#pragma once
#include "DrugList.h"


typedef int(*CompareFunction)(void *o1, void *o2);

#pragma once

void sort(DrugList*, CompareFunction,int);