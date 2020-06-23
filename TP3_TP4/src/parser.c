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

	int retorno = -1;
	Employee EmployeeAux;
	Employee* pEmployeeAux = NULL;
	int maxId = -1;
	int i = 0;
	char idAux[50];
	char horasTrabajadasAux[50];
	char sueldoAux[10];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//printf ("\nDEBUG - argumentos pasados bien al parser");
		retorno = 0;
		do
		{
			if (fread(&EmployeeAux,sizeof(Employee),1,pFile)==1)
			{
				//printf ("\nDEBUG - entro al fread");
				//printf ("\nDEBUG - ID = %d NOMBRE = %s HORAS = %d SUELDO = %d",EmployeeAux.id,EmployeeAux.nombre,EmployeeAux.horasTrabajadas,EmployeeAux.sueldo);

				sprintf(idAux, "%d", EmployeeAux.id);
				sprintf(horasTrabajadasAux, "%d", EmployeeAux.horasTrabajadas);
				sprintf(sueldoAux, "%d", EmployeeAux.sueldo);

				//printf ("\nDEBUG - IDSTRING = %s NOMBRE = %s HORASSTRING = %s SUELDOSTRING = %s",idAux, EmployeeAux.nombre,horasTrabajadasAux,sueldoAux);
				pEmployeeAux = employee_newParametros(idAux, EmployeeAux.nombre, horasTrabajadasAux, sueldoAux);
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
