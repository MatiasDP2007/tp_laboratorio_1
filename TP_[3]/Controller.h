#ifndef CONTROLLER_H_
#define  CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"

int controller_CheckListStatus(LinkedList* pArrayListPassenger);
void controller_Menu();
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,  int OverWriteData);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger,  int OverWriteData);
int controller_addPassenger(LinkedList* pArrayListPassenger, PassengerType* type, int typeLen,PassengerStatus* status, int statusLen);
int controller_editPassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);
int controller_removePassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);
int controller_ListPassenger(LinkedList* pArrayListPassenger,PassengerType* type, int typeLen, PassengerStatus* flightStatus, int flightLen);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_exit(LinkedList* pArrayListPassenger, int flagSave);
int controller_overWriteData(LinkedList* pArrayListPassenger);
int controller_overWriteText(LinkedList* pArrayListPassenger);
int controller_overWriteBin(LinkedList* pArrayListPassenger);
#endif  /* CONTROLLER_H_ */

