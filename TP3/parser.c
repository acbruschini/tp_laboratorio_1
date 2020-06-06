#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int El maximo ID (exito) -1 (Error)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	char idAux[50];
	char nombreAux[128];
	char horasTrabajadasAux[50];
	char sueldoAux[10];
	int i = 0;
	int maxId = -1;
	Employee* pEmployeeAux;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux)==4)
			{
				pEmployeeAux = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);
				if (pEmployeeAux != NULL)
				{
					ll_add(pArrayListEmployee, pEmployeeAux);
					if(pEmployeeAux->id > maxId)
					{
						maxId = pEmployeeAux->id;
					}
					i++;
				}
			}
		}while(feof(pFile)==0);

		retorno = maxId+1;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
