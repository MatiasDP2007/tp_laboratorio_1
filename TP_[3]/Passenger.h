#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validations.h"



typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int isEmpty;

}Passenger;

typedef struct
{
	int idType;
	char descripcion[25];
}PassengerType;

typedef struct
{
	int idStatus;
	char descripcion[25];
}PassengerStatus;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoStr,char* tipoPasajeroStr,char* estadoStr);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstado(Passenger* this, int estado);
int Passenger_getEstado(Passenger* this, int* estado);

void displayTypes(PassengerType* type, int len);
void displayStatusFlight(PassengerStatus* status, int len);

int ComparePassengerType(char* typeStr);
int ComparePassengerStatus(char* statusStr);
void changeType(int type, char* typeStr);
void changeFlightStatus(int statusFlight, char* statusFlightStr);

void Passenger_print(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen);
void One_PassengerPrint(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen, int index);

int increaseId(char* path);
int id_Max(char* path);
int employee_searchForId(LinkedList* pArrayListEmployee, int id);
Passenger* getPassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);


Passenger* addPassenger(PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);
int editPassenger( PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen, Passenger* pPassenger);
int removePassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen,Passenger* pPassenger, int index);

int SortPassengersMenu(LinkedList* pArrayListPassenger);
int PassengerSortNames(void* elementOne, void* elementTwo);
int PassengerSortLastNames(void* elementOne, void* elementTwo);
int PassengerSortIds(void* elementOne, void* elementTwo);
int PassengerSortPrices(void* elementOne, void* elementTwo);

int sortPassengerByIdSubMenu(LinkedList* pArrayListPassenger);
int sortPassengersByNameSubMenu(LinkedList* pArrayListPassenger);
int sortPassengersByLastNameSubMenu(LinkedList* pArrayListPassenger);
int sortPassengersByPriceSubMenu(LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
