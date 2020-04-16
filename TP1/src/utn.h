/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Ariel
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
float sumFloats(float* pResultado,float numA, float numB);
float subFloats(float* pResultado,float numA, float numB);
float mulFloats(float* pResultado,float numA, float numB);
float divFloats(float* pResultado,float numA, float numB);
float factFloats(float* pResultado,float num);

#endif /* UTN_H_ */
