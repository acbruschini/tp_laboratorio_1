#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 128
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_getIndexById(LinkedList* listaEmpleados,int id);
int employee_sortBySueldo(void* pElement1, void* pElement2);
int employee_sortByHorasTrabajadas(void* pElement1, void* pElement2);
int employee_sortByNombre(void* pElement1, void* pElement2);

int employee_print(void* pElement);
int employee_isSueldoMayor30000(void* pElement);
int employee_isHorasTrabajadasMayorA8(void* pElement);
int employee_getSueldoEnHorasMayorA120(void* pElement);
int employee_isSueldoMayorA60000(void* pElement);

#endif // employee_H_INCLUDED
