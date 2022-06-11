#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "LinkedList.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int generateIdFile(char* path);
int SaveTextList(FILE* pFile , LinkedList* pArrayListPassenger);
int SaveBinaryList(FILE* pFile , LinkedList* pArrayListPassenger, char* path);
int CheckSavedData(LinkedList* pArrayListPassenger, int flagSave);
#endif /* PARSER_H_ */
