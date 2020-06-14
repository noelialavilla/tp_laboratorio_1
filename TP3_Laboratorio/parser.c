#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int cantParametros;
    Employee* auxEmployee;
    int todoOk = -1;
    char buffer[4][100];

    if (pFile != NULL  && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            cantParametros = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantParametros == 4)
            {
                auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(pArrayListEmployee, auxEmployee);
                todoOk = 1;
            }
            else
            {
                break;
            }
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    Employee* auxEmployee;

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee=employee_new();
            if ( fread ( auxEmployee, sizeof(Employee),1,pFile) != 0)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                todoOk = 1;
            }
        }

    }
    return todoOk;
}
