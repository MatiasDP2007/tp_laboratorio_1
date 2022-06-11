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

/// @brief devuelve un espacio en memoria dinamica para un pasajero
///
/// @return
Passenger* Passenger_new();

/// @brief Crea un pasajero con las cadenas recibidas y las guarda por medio de setters
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param codigoStr
/// @param tipoPasajeroStr
/// @param estadoStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoStr,char* tipoPasajeroStr,char* estadoStr);

/// @brief Libera el espacio en memoria del pasajero
///
/// @param this
void Passenger_delete(Passenger* this);

/// @brief Setter del ID
///
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger* this,int id);

/// @brief Getter del ID
///
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger* this,int* id);

/// @brief Setter del nombre
///
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief Getter del nombre
///
/// @param this
/// @param nombre
/// @return
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief Setter del apellido
///
/// @param this
/// @param apellido
/// @return
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief getter del apellido
///
/// @param this
/// @param apellido
/// @return
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief Setter del codigo de vuelo
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Getter del codigo de vuelo
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Setter del tipo de pasajero
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief Getter del tipo de pasajero
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief Setter del precio
///
/// @param this
/// @param precio
/// @return
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief Getter del precio
///
/// @param this
/// @param precio
/// @return
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief Setter del estado de vuelo
///
/// @param this
/// @param estado
/// @return
int Passenger_setEstado(Passenger* this, int estado);

/// @brief Getter del estado de vuelo
///
/// @param this
/// @param estado
/// @return
int Passenger_getEstado(Passenger* this, int* estado);

///  @brief Imprime los clases de pasajeros que hay
///
/// @param type
/// @param len
void displayTypes(PassengerType* type, int len);

/// @brief  Imprime las clases de estado que hay
///
/// @param status
/// @param len
void displayStatusFlight(PassengerStatus* status, int len);

/// @brief Compara la cadena que recibe como parametro con las cadenas de tipo de pasajero devolviendo un entero como referencia
///
/// @param typeStr
/// @return
int ComparePassengerType(char* typeStr);

/// @brief Compara la cadena que recibe como parametro con las cadenas de estado de vuelo devolviendo un entero como referencia
///
/// @param statusStr
/// @return
int ComparePassengerStatus(char* statusStr);

/// @brief Recibe el dato ingresado de tipo entero y guarda una cadena de tipo de pasajero como referencia
///
/// @param type
/// @param typeStr
void changeType(int type, char* typeStr);

/// @brief Recibe el dato ingresado de tipo entero y guarda una cadena de estado de vuelo como referencia
///
/// @param statusFlight
/// @param statusFlightStr
void changeFlightStatus(int statusFlight, char* statusFlightStr);

/// @brief Imprime la lista de pasajeros cargados en la LinkedList
///
/// @param pArrayPassenger
/// @param type
/// @param typeLen
/// @param flightStatus
/// @param flightLen
void Passenger_print(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen);

/// @brief Imprime el pasajero del indice pedido
///
/// @param pArrayPassenger
/// @param type
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @param index
void One_PassengerPrint(LinkedList* pArrayPassenger, PassengerType*type,int typeLen, PassengerStatus* flightStatus, int flightLen, int index);

/// @brief  Realiza una lectura del archivo binario que tiene guardado el ultimo ID y lo incrementa
///
/// @param path
/// @return
int increaseId(char* path);

/// @brief Realiza una lectura del archivo binario y devuelve el ultimo ID
///
/// @param path
/// @return
int id_Max(char* path);

/// @brief Realiza una busqueda del indice en donde se encuentra el ID que recibe como parametro y lo devuelve
///
/// @param pArrayListEmployee
/// @param id
/// @return
int employee_Index(LinkedList* pArrayListEmployee, int id);

/// @brief Realiza la busqueda de un pasajero y lo devuelve en el caso de error devuelve NULL
///
/// @param pArrayListPassenger
/// @param passengerType
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @return
Passenger* getPassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);

/// @brief Realiza el alta de un pasajero y lo agrega a la LinkedList
///
/// @param passengerType
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @return
Passenger* addPassenger(PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen);

/// @brief Realiza la modificacion de un pasajero
///
/// @param passengerType
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @param pPassenger
/// @return
int editPassenger( PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen, Passenger* pPassenger);

/// @brief Realiza una baja en el indice que recibe como parametro
///
/// @param pArrayListPassenger
/// @param passengerType
/// @param typeLen
/// @param flightStatus
/// @param flightLen
/// @param pPassenger
/// @param index
/// @return
int removePassenger(LinkedList* pArrayListPassenger, PassengerType* passengerType, int typeLen, PassengerStatus* flightStatus, int flightLen,Passenger* pPassenger, int index);

/// @brief Imprime el menu con las opcions de Sort
///
/// @param pArrayListPassenger
/// @return
int SortPassengersMenu(LinkedList* pArrayListPassenger);

/// @brief Compara dos cadenas que son traidas con los getter del nombre y devuelve un entero como referencia
///
/// @param elementOne
/// @param elementTwo
/// @return
int PassengerSortNames(void* elementOne, void* elementTwo);

/// @brief Compara dos cadenas que son traidas con los getter del apellido y devuelve un entero como referencia
///
/// @param elementOne
/// @param elementTwo
/// @return
int PassengerSortLastNames(void* elementOne, void* elementTwo);

/// @brief Compara dos enteros que son traidos con los getter del ID y devuelve un entero como referencia
///
/// @param elementOne
/// @param elementTwo
/// @return
int PassengerSortIds(void* elementOne, void* elementTwo);

/// @brief Compara dos flotnates que son traidos con los getter del precio y devuelve un entero como referencia
///
/// @param elementOne
/// @param elementTwo
/// @return
int PassengerSortPrices(void* elementOne, void* elementTwo);

/// @brief  Imprime submenu para los tipos de sort de ID
///
/// @param pArrayListPassenger
/// @return
int sortPassengerByIdSubMenu(LinkedList* pArrayListPassenger);

/// @brief Imprime submenu para los tipos de sort de nombres
///
/// @param pArrayListPassenger
/// @return
int sortPassengersByNameSubMenu(LinkedList* pArrayListPassenger);

/// @brief Imprime submenu para los tipos de sort de apellidos
///
/// @param pArrayListPassenger
/// @return
int sortPassengersByLastNameSubMenu(LinkedList* pArrayListPassenger);

/// @brief  Imprime submenu para los tipos de sort de precio
///
/// @param pArrayListPassenger
/// @return
int sortPassengersByPriceSubMenu(LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
