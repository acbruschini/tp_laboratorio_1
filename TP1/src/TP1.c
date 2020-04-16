/*
 ============================================================================
 Name        : TP1 CALCULADORA
 Author      : Ariel Bruschini
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	//setbuf(stdout, NULL);
	int opcionMenu; // Opcion del menu seleccionada
	float numA = 0; // Operador A
	float numB = 0; // Operador B
	float resultadoSuma; // Resultado de la suma
	float resultadoResta; // Resultado de la Resta
	float resultadoMultiplicacion; // Resultado de la Multiplicacion
	float resultadoDivision; // Resultado de la Division
	int retornoDivision; // Retorno de func Division por si hay error
	int retornoFactNumA; // Retorno de func Factoreo del operador A por si hay error
	int retornoFactNumB; // Retorno de func Factoreo del operador B por si hay error
	float factorialNumA; // Resultado factorial operador A
	float factorialNumB; // Resultado factorial operador B
	int resultadosCalculadosFlag=0; // Flag que avisa si los resultados estan actualizados

	do
	{
		printf ("\n-------------------------------------\nMenu de opciones TP1 CALCULADORA\n-------------------------------------\n\n");
		printf ("1 - Ingresar 1er Operador (A = %f)\n",numA);
		printf ("2 - Ingresar 2do Operador (B = %f)\n",numB);
		printf ("3 - Calcular todas las operaciones\n");
		printf ("4 - Informar Resultados\n");
		printf ("5 - Salir\n");
		printf ("-------------------------------------\n");

		utn_getNumero(&opcionMenu,"Que desea hacer: ", "El numero ingresado no corresponde a una opcion del menu\n",1,5,10);


		switch(opcionMenu)
		{
			case 1:

				utn_getNumeroFlotante(&numA,"Ingrese el operador A:","Error: ",-99999999999999,9999999999999,10);
				resultadosCalculadosFlag = 0;
				break;

			case 2:

				utn_getNumeroFlotante(&numB,"Ingrese el operador B:","Error: ",-99999999999999,9999999999999,10);
				resultadosCalculadosFlag = 0;
				break;

			case 3:

				sumFloats(&resultadoSuma,numA,numB);
				subFloats(&resultadoResta,numA,numB);
				mulFloats(&resultadoMultiplicacion,numA,numB);
				retornoDivision = divFloats(&resultadoDivision,numA,numB);
				retornoFactNumA = factFloats(&factorialNumA,numA);
				retornoFactNumB = factFloats(&factorialNumB,numB);
				resultadosCalculadosFlag = 1;
				printf ("\nResultados Calculados\n\n");
				system ("pause");
				break;

			case 4:

				if (resultadosCalculadosFlag == 1) // Si los resultados estan actualizados, mostrarlos
				{
					printf ("\nEl resultado de A+B es: %f",resultadoSuma);
					printf ("\nEl resultado de A-B es: %f",resultadoResta);

					if(!retornoDivision) // Si no hubo error mostrar el resultado de la Division
					{
						printf ("\nEl resultado de A/B es: %f",resultadoDivision);
					}
					else
					{
						printf ("\nEl resultado de A/B es: No se puede dividir por 0");
					}

					printf ("\nEl resultado de A*B es: %f",resultadoMultiplicacion);

					if(!retornoFactNumA) // Si no hubo error mostrar el resultado del Factorial A
					{
						printf ("\nEl factorial de A es: %f | ",factorialNumA);
					}
					else
					{
						printf ("\nEl factorial de A es: No es un numero Natural Entero | ");
					}

					if(!retornoFactNumB) // Si no hubo error mostrar el resultado del Factorial B
					{
						printf ("El factorial de B es: %f",factorialNumB);
					}
					else
					{
						printf ("El factorial de B es: No es un numero Natural Entero");
					}

					printf ("\n\n");
					system ("pause");
				}
				else
				{

					printf ("\n\nCalcule los resultados antes con la opcion 3\n\n");
					system ("pause");

				}
				break;

			case 5:

				break;
		}

		system("cls");

	}while (opcionMenu != 5);

	return EXIT_SUCCESS;
}
