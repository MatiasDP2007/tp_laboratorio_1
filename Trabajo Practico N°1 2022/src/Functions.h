/*
 * Functions.h
 *
 *  Created on: 2 abr. 2022
 *      Author: Matia
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/// @brief Valida que se haya ingresado un dato previamente antes de permitirle al usuario calcular o mostrar los resultados
///
/// @param distance
/// @param latamPrices
/// @param aerolineasPrices
/// @return
int ValidateFirstOption(float distance, float latamPrices, float aerolineasPrices);

/// @brief Permite que el usuario ingrese una distancia
///
/// @param distance
/// @return
int EnterDistance(float* distance, int* checkUpdatedData);

/// @brief Permite que el usuario ingrese los precios de ambas empresas
///
/// @param latamPrices
/// @param aerolineasPrices
/// @return
int SetFlightPrices(float* latamPrices, float* aerolineasPrices, int* checkUpdatedData);

/// @brief Se encarga de calcular todos los resultados a mostrar recibiendo los datos ingresados
///
/// @param distance
/// @param latamPrices
/// @param aerolineasPrices
/// @param debitLatamCalculation
/// @param debitAerolineasCalculation
/// @param creditLatamCalculation
/// @param creditAerolineasCalculation
/// @param bitcoinLatamPrice
/// @param bitcoinAerolineasPrice
/// @param pricePerLatamKilometer
/// @param pricePerAerolineasKilometer
/// @param pricesDiference
/// @return
int CalculateFlightPrices(int* checkUpdatedData ,float* distance, float* latamPrices, float* aerolineasPrices, float* debitLatamCalculation, float* debitAerolineasCalculation,
						  float* creditLatamCalculation, float* creditAerolineasCalculation, float* bitcoinLatamPrice,float* bitcoinAerolineasPrice,
						  float* pricePerLatamKilometer, float* pricePerAerolineasKilometer, float* pricesDiference);

/// @brief Muestra todos los resultados calculados previamente
///
/// @param distance
/// @param latamPrices
/// @param aerolineasPrices
/// @param debitLatamCalculation
/// @param debitAerolineasCalculation
/// @param creditLatamCalculation
/// @param creditAerolineasCalculation
/// @param bitcoinLatamPrice
/// @param bitcoinAerolineasPrice
/// @param pricePerLatamKilometer
/// @param pricePerAerolineasKilometer
/// @param pricesDiference
void InformarResultados (float distance, float latamPrices, float aerolineasPrices, float debitLatamCalculation, float debitAerolineasCalculation,
		 float creditLatamCalculation, float creditAerolineasCalculation, float bitcoinLatamPrice,float bitcoinAerolineasPrice,
		float pricePerLatamKilometer, float pricePerAerolineasKilometer, float pricesDiference);




#endif /* FUNCTIONS_H_ */
