/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Employee.h"

#define ARRAYEMPLOYEES_LEN 1000
#define MENUPRINCIPAL_LEN 6

int main(void) {

	setbuf(stdout, NULL);
	Employee arrayEmployees[ARRAYEMPLOYEES_LEN];
	char menuPrincipal[MENUPRINCIPAL_LEN][300] = {
			"ABM TO MANAGE EMPLOYEES LIST",
			"Add an Employee",
			"Modify an Employee",
			"Delete an Employee",
			"Information",
			"Exit"
	};
	int indiceACargar;
	int idEmployee = 0;
	int opcionElegida;
	int idAuxiliar;
	int indiceAuxiliar;
	float totalSalary;
	float averageSalary;

	initEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN);

	// ALTA FORZADA PARA TESTEAR
	/*
	forcedAddEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, 0, &idEmployee, "Ariel", "Bruschini", 2, 5000);
	forcedAddEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, 1, &idEmployee, "Leticia", "Leoz", 2, 3500);
	forcedAddEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, 2, &idEmployee, "Diego", "Dalairac", 4, 5000);
	forcedAddEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, 3, &idEmployee, "Federico", "Szalai", 1, 1000.67);
	forcedAddEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, 4, &idEmployee, "Lia", "Bruschini", 1, 2000.5);
	*/

	do
	{
		opcionElegida = menu(menuPrincipal,MENUPRINCIPAL_LEN);
		switch (opcionElegida)
		{

		case 1:
			indiceACargar = getEmptyIndex(arrayEmployees, ARRAYEMPLOYEES_LEN);
			if(!addEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN, indiceACargar, &idEmployee) && indiceACargar != -1)
			{
				printf("\nA new employee was successfully added.");
			}

			break;

		case 2:
			if (!isArrayEmpty(arrayEmployees, ARRAYEMPLOYEES_LEN))
			{

				printEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN);
				if(!utn_getNumero(&idAuxiliar, "\nChoose the Employee ID you want to modify:\n", "\nERROR\n", 0, 999999, 5) &&
					(indiceAuxiliar = findEmployeedById(arrayEmployees, ARRAYEMPLOYEES_LEN, idAuxiliar)) != -1 &&
					!modifyEmployee(arrayEmployees, ARRAYEMPLOYEES_LEN, indiceAuxiliar))
				{
					printf("\nThe employee with iD number %d was successfully modified.",idAuxiliar);
				}

			}
			else
			{
				printf("\nYou have no clients in the system.");
			}
			break;

		case 3:
			if (!isArrayEmpty(arrayEmployees, ARRAYEMPLOYEES_LEN))
			{

				printEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN);
				if(!utn_getNumero(&idAuxiliar, "\nChoose the Employee ID you want to delete:\n", "\nERROR\n", 0, 999999, 5) &&
					(indiceAuxiliar = findEmployeedById(arrayEmployees, ARRAYEMPLOYEES_LEN, idAuxiliar)) != -1 &&
					!removeEmployee(arrayEmployees, ARRAYEMPLOYEES_LEN, indiceAuxiliar))
				{
					printf("\nThe employee with iD number %d was successfully deleted.",idAuxiliar);
				}

			}
			else
			{
				printf("\nYou have no clients in the system.");
			}
			break;

		case 4:
			if (!isArrayEmpty(arrayEmployees, ARRAYEMPLOYEES_LEN))
			{

				sortByLastnameAndSector(arrayEmployees, ARRAYEMPLOYEES_LEN);
				printEmployees(arrayEmployees, ARRAYEMPLOYEES_LEN);
				getTotalSalary(&totalSalary, arrayEmployees, ARRAYEMPLOYEES_LEN);
				printf ("\n\nThe total salary of all employees is: %.2f",totalSalary);
				getAverageSalary(&averageSalary, arrayEmployees, ARRAYEMPLOYEES_LEN);
				printf ("\n\nThe average salary between all employees is: %.2f",averageSalary);
				printf ("\n\nThe number of Employees that get paid above average is: %d",getEmployeesHigherAverage(arrayEmployees, ARRAYEMPLOYEES_LEN, averageSalary));

			}
			else
			{
				printf("\nYou have no clients in the system.");
			}
			break;
		}
	}while (opcionElegida != 5);
	return 0;
}
