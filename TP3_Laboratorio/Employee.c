#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"

int menu()
{
    int option;

    system("cls");
    printf("**** Menu de empleados **** \n\n");
    printf("1.   Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");
    printf("2.   Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
    printf("3.   Alta de empleado.\n");
    printf("4.   Modificar datos de empleado.\n");
    printf("5.   Baja de empleado.\n");
    printf("6.   Listar empleados.\n");
    printf("7.   Ordenar empleados.\n");
    printf("8.   Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.   Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10.   Salir.\n");
    if(utn_getNumero(&option, "Enter option: ","",1,10,0) == -1)
    {
        option = 0;
    }

    return option;

}
//************************************************************************************************************************************/
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

//************************************************************************************************************************************/
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {

        if   ( (employee_setId(newEmployee, atoi(idStr)) == -1) ||
                (employee_setNombre(newEmployee, nombreStr) ==-1) ||
                (employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) ==-1)||
                (employee_setSueldo(newEmployee, atoi(sueldo)) == -1))
        {

            employee_delete(newEmployee);
            newEmployee = NULL;
        }

    }
    return newEmployee;
}

//************************************************************************************************************************************/
int employee_setId(Employee* this,int id)
{
    int succes = -1;

    if ( this != NULL && id >0 && id <= 100000)
    {
        this-> id = id;
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_getId(Employee* this,int* id)
{
    int succes = -1;
    if(this != NULL && id!=NULL)
    {
        *id = this-> id;
        succes = 1;
    }
    return succes;
}
//************************************************************************************************************************************/
int employee_setNombre(Employee* this,char* nombre)
{
    int succes = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this -> nombre, nombre);
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_getNombre(Employee* this, char* nombre)
{
    int succes = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre, this -> nombre);
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int succes = -1;

    if ( this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this-> horasTrabajadas = horasTrabajadas;
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int succes = -1;
    if ( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this -> horasTrabajadas;
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_setSueldo(Employee* this, int sueldo)
{
    int succes = -1;

    if ( this != NULL && sueldo >0 && sueldo <= 500000 )
    {
        this-> sueldo = sueldo;
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
int employee_getSueldo(Employee* this,int* sueldo)
{
    int succes = -1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        succes = 1;
    }
    return succes;
}

//************************************************************************************************************************************/
void employee_delete(Employee* this )
{

    if ( this != NULL)
    {
        free(this);
    }

}

//************************************************************************************************************************************/
int showEmployee(Employee* this)
{
    int todoOk =-1;
    if(this != NULL)
    {
        todoOk = 1;
        printf("%4d  %20s  %4d                     %5d \n", this->id, this->nombre, this-> horasTrabajadas, this->sueldo);
    }
    return todoOk;
}

//************************************************************************************************************************************/
int compareEmployeesByName(void* empA,void* empB)
{
    int orden = 0;

    if( empA != NULL && empB != NULL )
    {
        Employee* pEmpA = (Employee*) empA;
        Employee* pEmpB = (Employee*) empB;
        if (strcmp(pEmpA->nombre, pEmpB->nombre) > 0)
        {
            orden = 1;
        }
        else if(strcmp(pEmpA->nombre, pEmpB->nombre) < 0)
        {
            orden = -1;
        }

    }
    return orden;
}

//************************************************************************************************************************************//
int modificationMenu()
{
    int option;
    system("cls");
    printf("\n**** Menu de modificaciones **** \n");
    printf("\n1.  Modificar nombre.\n");
    printf("2.  Modificar horas trabajadas.\n");
    printf("3.  Modificar sueldo.\n");
    printf("4.  Salir.\n");

    if(utn_getNumero(&option, "Ingrese opcion:  ","",1,4,0) == -1)
    {
        option = 0;
    }

    return option;
}

//************************************************************************************************************************************//
int modifyEmployee(Employee* this)
{
    char keepOn = 's';
    int newNameOk;
    int newHoursWorkedOk;
    int newSalaryOk;
    int modifOk = -1;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    system("cls");

    do
    {
        switch(modificationMenu())
        {
        case 1:
            newNameOk = utn_getNombre(nombre, 127,"Ingrese nuevo nombre: ", "El nombre solo puede contener letras y debe tener una longitud menor a 128.\n",  3);
            if (newNameOk == 1)
            {
                employee_setNombre(this, nombre);
                modificationOk(this);
                modifOk = 1;
            }
            break;
        case 2:
            newHoursWorkedOk = utn_getNumero(&horasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ", "La cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 3);
            if (newHoursWorkedOk ==1)
            {
                employee_setHorasTrabajadas(this, horasTrabajadas);
                modificationOk(this);
                modifOk = 1;
            }
            break;
        case 3:
            newSalaryOk = utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: ", "El sueldo debe ser un numero entre 1 y 500000.\n", 1, 500000, 3);
            if(newSalaryOk == 1)
            {
                employee_setSueldo(this, sueldo);
                modificationOk(this);
                modifOk = 1;
            }
            break;
        case 4:
            keepOn = 'n';
            break;
        case 0:
            printf("\nHa ingresado una opcion invalida, por favor intente nuevamente.\n");
            break;
        }
        system("pause");
    }
    while(keepOn =='s');

    return modifOk;
}

//************************************************************************************************************************************/
void modificationOk(Employee* this)
{
    printf("La modificacion se ha realizado exitosamente. .\n\n");
    printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
    printf("------------------------------------------------------------------------\n");
    showEmployee(this);

}

//************************************************************************************************************************************/
int findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
    int employeeIndex = -1;
    int idAux;
    Employee* auxEmployee;

    for(int index = 0; index < ll_len(pArrayListEmployee); index++)
    {
        auxEmployee = ll_get(pArrayListEmployee, index);
        if(employee_getId(auxEmployee, &idAux)  &&  idAux == id)
        {
            employeeIndex = index;
            break;
        }
    }
    return employeeIndex;
}
