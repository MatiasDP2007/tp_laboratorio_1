#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"
#include "LinkedList.h"
#include "Passenger.h"

/// @brief Realiza el parseo de datos del archivo de texto y guarda a los pasajeros en la lista
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Realiza el parseo de datos del archivo de binario y guarda a los pasajeros en la lista
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Genera un archivo de tipo binario con un ID inicializdo en 1000
///
/// @param path
/// @return
int generateIdFile(char* path);

/// @brief Guarda la lista en modo texto
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int SaveTextList(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Guarda la lista en modo binario
///
/// @param pFile
/// @param pArrayListPassenger
/// @param path
/// @return
int SaveBinaryList(FILE* pFile , LinkedList* pArrayListPassenger, char* path);

/// @brief Informa al usuario que no se guardaron los datos antes de salir del programa
///
/// @param pArrayListPassenger
/// @param flagSave
/// @return
int CheckSavedData(LinkedList* pArrayListPassenger, int flagSave);
#endif /* PARSER_H_ */
