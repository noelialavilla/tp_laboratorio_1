#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "validations.h"
#include "parser.h"
#include <ctype.h>
#include<string.h>

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {

        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
            {
                todoOk = 1;
                printf("Empleados cargados correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar los empleados.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {

        pFile=fopen(path,"rb");
        if( pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
            {
                todoOk=1;
                printf("Empleados cargados correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar los empleados.\n");
            }

        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
        fclose(pFile);
    }
    return todoOk;
}

//************************************************************************************************************************************/

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[128];
    int id ;
    int horasTrabajadas;
    int sueldo;
    int newNameOk;
    int newHoursWorkedOk;
    int newSalaryOk;
    char horasTrabajadasStr[20];
    char sueldoStr[20];
    char idStr[20];
    int empAddedOk = -1;
    Employee* auxEmployee;
    system("cls");
    printf("**** Alta de nuevo empleado **** \n\n");

    if ( pArrayListEmployee != NULL)
    {
        newNameOk = utn_getNombre(nombre, 127,"Ingrese nuevo nombre: ", "El nombre solo puede contener letras y debe tener una longitud menor a 128.\n",  3);
        newHoursWorkedOk = utn_getNumero(&horasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ", "La cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 3);
        newSalaryOk = utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: ", "El sueldo debe ser un numero entre 1 y 500000.\n", 1, 500000, 3);

        if(newNameOk && newHoursWorkedOk && newSalaryOk  )
        {
            getIdFromArchive(&id);
            strlwr(nombre);
            nombre[0]= toupper(nombre[0]);
            itoa(horasTrabajadas, horasTrabajadasStr, 10);
            itoa(sueldo, sueldoStr, 10);
            itoa(id, idStr, 10);
            auxEmployee = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
            if (auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                printf("Se ha agregado satisfactoriamente el empleado.\n");
                updateId(id);
                empAddedOk = 1;
            }

        }
        else
        {
            printf("Se produjeron errores durante la carga del empleado. Por favor intentelo de nuevo\n");

        }
    }
    system("pause");
    return empAddedOk;
}


//************************************************************************************************************************************/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int succes = -1;
    int index;
    int idOk;
    char confirm;

    system("cls");
    if ( pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idOk = utn_getNumero(&id, "Ingrese el ID del empleado al que desea realizarle algun cambio:","El id debe encontrarse entre 1 y 2000.", 1, 2000, 3);
        if (idOk != -1)
        {
            index = findEmployeeById(pArrayListEmployee, id);

            if(index == -1)
            {
                printf("No hay empleados con el id: %d .\n",id);
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nEl empleado a modificar es el siguiente: \n\n");

                printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
                printf("------------------------------------------------------------------------\n");

                showEmployee((Employee*) ll_get(pArrayListEmployee,index));
                printf("\n\nEsta seguro que desea modificar el  empleado mostrado por pantalla?  [s/n] ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (tolower(confirm) == 's')
                {
                    modifyEmployee((Employee*) ll_get(pArrayListEmployee,index));
                    succes = 1;
                }
                else
                {
                    printf("Se ha cancelado la operacion. \n");
                }
            }

        }
        else
        {
            printf("No se ha ingresado un Id correspondiente a un empleado activo. Por favor intentelo de nuevo.\n");
        }

    }
    return succes;
}

//************************************************************************************************************************************/
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int succes = -1;
    int index;
    int id;
    char confirm;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumero(&id,"Ingrese el id del empleado que desea eliminar: ","\nError, por favor ingrese un id valido.\n",0,20000,3) != -1)
        {
            index = findEmployeeById(pArrayListEmployee, id);
            if(index == -1)
            {
                printf("No hay empleados con el id: %d .\n",id);
                system("pause");
            }
            else
            {
                printf("El empleado a eliminar es el siguiente: \n\n");
                printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
                printf("------------------------------------------------------------------------\n");

                showEmployee((Employee*) ll_get(pArrayListEmployee,index));

                printf("Esta seguro que desea dar de baja el  empleado mostrado por pantalla?  [s/n] ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (tolower(confirm) == 's')
                {
                    ll_remove(pArrayListEmployee, index);
                    printf("\nEmpleado dado de baja exitosamente.\n");
                    succes = 1;
                }
                else
                {
                    printf("Se ha cancelado la operacion. \n");
                }
            }
        }
        else
        {
            printf("No se ha ingresado un Id correspondiente a un empleado activo. Por favor intentelo de nuevo.\n");
        }
    }
    return succes;
}

//************************************************************************************************************************************/

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int tam = ll_len(pArrayListEmployee);
    int flag = 0;
    Employee* auxEmp;

    if( pArrayListEmployee != NULL)
    {
        todoOk = 1;
        printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
        printf("------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if (  auxEmp  != NULL )
            {
                showEmployee( auxEmp );
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay empleados que mostrar\n");
        }
    }
    return todoOk;

}

//************************************************************************************************************************************/

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ordenamiento;
    int ordenIngresadoOk = -1;
    if( pArrayListEmployee != NULL)
    {
        ordenIngresadoOk = utn_getNumero(&ordenamiento, "Ingrese el orden en el que desea ordenar los empleados.\n0. Ascendente\n1. Descendete\n","Error. Ingrese 1 o 0.", 0,1, 3);
        if (ordenIngresadoOk)
        {
            ll_sort(pArrayListEmployee, compareEmployeesByName, ordenamiento);
        }
        else
        {
            printf("No se ingreso un ordenamiento valido. Por favor intentelo nuevamente.");
        }

    }

    return ordenIngresadoOk;
}

//************************************************************************************************************************************/
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"w") ;
    int tam =  ll_len(pArrayListEmployee);
    Employee* auxEmp;
    int todoOk = -1;

    if(f != NULL)
    {
        fprintf(f,"  Id                Nombre  Horas Trabajadas          Sueldo \n");
        for (int i =0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmp !=NULL)
            {
                fprintf(f, "%d,%s,%d,%d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}

//************************************************************************************************************************************/
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"wb") ;
    int tam =  ll_len(pArrayListEmployee);
    Employee* auxEmp;
    int todoOk = -1;
    // char header[] = "  Id                Nombre  Horas Trabajadas          Sueldo \n";

    if(f != NULL)
    {
        //     fwrite(header, 1, sizeof(header), f );

        for (int i =0; i<tam; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmp != NULL)
            {
                fwrite(auxEmp, sizeof(Employee), 1, f);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}

//************************************************************************************************************************************/
int getIdFromArchive(int* id)
{

    *id = 1001;
    int succes = -1;

    FILE* f;
    f = fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        succes = 1;
    }

    return succes;
}

//************************************************************************************************************************************/
int updateId(int id)
{
    int proxId =id;
    proxId++;
    int succes  = -1;
    FILE* f;
    f = fopen("proximoid.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);

        fclose(f);
        succes = 1;
    }

    return succes;
}
//************************************************************************************************************************************/
