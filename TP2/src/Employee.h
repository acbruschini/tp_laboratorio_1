#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct
{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector; //AGREGADO
	int isEmpty;
	int id;
}Employee;

int printEmployee(Employee* auxProducto);
int initEmployees(Employee* array,int limite);
int addEmployees(Employee* array,int limite, int indice, int* id);
int getEmptyIndex(Employee* array,int limite);
int printEmployees(Employee* array,int limite);
int findEmployeedById(Employee array[], int limite, int valorBuscado);
int modifyEmployee(Employee* array,int limite, int indice);
int removeEmployee(Employee* array,int limite, int indice);
int sortByName(Employee* array,int limite);
int sortByLastnameAndSector(Employee* array,int limite);
int forcedAddEmployees(Employee* array,int limite, int indice, int* id, char* name, char* lastname, int sector, float salary);
int getTotalSalary(float* pResultado, Employee* array,int limite);
int getAverageSalary(float* pResultado, Employee* array,int limite);
int getEmployeesHigherAverage(Employee* array,int limite, float promedio);
int isArrayEmpty(Employee* array,int limite);

#endif /* EMPLOYEE_H_ */
