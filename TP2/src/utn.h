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
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getMail(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
float math_sumFloats(float* pResultado,float numA, float numB);
float math_subFloats(float* pResultado,float numA, float numB);
float math_mulFloats(float* pResultado,float numA, float numB);
float math_divFloats(float* pResultado,float numA, float numB);
float math_factFloats(float* pResultado,float num);
int menu(char pArray[][300],int len);
int printArrayCharWithMessage (char pArray[],int len,int type,char* mensaje);



#endif /* UTN_H_ */
