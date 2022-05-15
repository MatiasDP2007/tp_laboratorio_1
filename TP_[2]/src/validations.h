
#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_


/// @param message
/// @param max
/// @param min
/// @return
int EnterNumberInt(char message[], char errorMessage[], int max, int min);

/// @param message
/// @param enteredString
void EnterString (char message[], char enteredString[]);

/// @param message
/// @return
float EnterNumberFloat (char message[], char errorms[], int min);

/// @param enteredNumber
/// @return
int ValidateNumberInt(char enteredNumber[], int min, int max);

/// @param enteredString
/// @return
int ValidateString(char enteredString[]);

/// @param enteredNumber
/// @return
int ValidateNumberFloat(char enteredNumber[], int min);

/// @param enteredString
void NormalizeString(char enteredString[]);

void EnterChar(char message[], char enteredChar);

#endif
