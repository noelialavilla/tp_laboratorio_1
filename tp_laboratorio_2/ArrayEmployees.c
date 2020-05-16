#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define NOTFOUND -1
#define NOTOK -1
#define OK 0

int menu()
{
    int option;

    system("cls");
    printf("**** Employee management **** \n\n");
    printf("1.  Register an employee.\n");
    printf("2.  Modify an employee.\n");
    printf("3.  Remove employee.\n");
    printf("4.  Reports menu.\n");
    printf("5.  Exit.\n");
    if(utn_getNumero(&option, "Enter option: ","",1,5,0) == NOTOK)
    {
        option = 0;
    }

    return option;

}

//************************************************************************************************************************************/
int validateEmptyArray(Employee* list, int len)
{
    int isEmpty = TRUE;
    if(validateLengthAndNullPointer(list, len))
    {
        for(int index = 0; index < len; index++)
        {
            if(list[index].isEmpty ==FALSE)
            {
                isEmpty = FALSE;
                break;
            }
        }
    }
    return isEmpty;

}

//************************************************************************************************************************************/
int modifyEmployee(Employee* list, int len)
{
    int id;
    int index;
    int newNameOk;
    int newLastNameOk;
    int newSalaryOk;
    int newSectorOk;
    char keepOn = 'y';
    int modifOk =NOTOK;
    Employee auxEmployee;

    system("cls");
    printEmployees(list, len);
    printf("Enter the id of the employee you want to modify.\n");
    fflush(stdin);
    scanf("%d", &id);
    system("cls");
    printf("**** Modification menu **** \n\n");
    index = findEmployeeById(list, len, id);

    if( index == NOTFOUND)
    {
        printf("There is no record of an employee with the Id %d\n", id);
    }
    else
    {
        printf("   Id       Name           LastName           Salary     Sector\n");
        printEmployee(list[index]);
        do
        {
            switch(modificationMenu())
            {
            case 1:
                newNameOk = utn_getNombre(auxEmployee.name, 51,"Enter new name: ", "The name can only contain letters and must have less than 50.\n",  3);
                if (newNameOk)
                {
                    strcpy(list[index].name, auxEmployee.name);
                    modificationOk(list, index);
                    modifOk = TRUE;
                }
                break;
            case 2:
                newLastNameOk = utn_getNombre(auxEmployee.lastName, 51, "Enter new last Name: ", "The last name can only contain letters and must have less than 50. \n",  3);
                if (newLastNameOk)
                {
                    strcpy(list[index].lastName, auxEmployee.lastName);
                    modificationOk(list, index);
                    modifOk = TRUE;
                }
                break;
            case 3:
                newSalaryOk = utn_getNumeroFlotante(&auxEmployee.salary, "Salary: ", "The salary value must be a number between 1 and 400000. \n", 1.00, 4000000.00, 3);
                if (newSalaryOk)
                {
                    list[index].salary = auxEmployee.salary;
                    modificationOk(list, index);
                    modifOk = TRUE;
                }
                break;
            case 4:
                newSectorOk = utn_getNumero(&auxEmployee.sector, "Sector: ", "The sector value must be a number between 1 and 10.\n", 1, 10, 3);
                if(newSectorOk)
                {
                    list[index].sector = auxEmployee.sector;
                    modificationOk(list, index);
                    modifOk = TRUE;
                }
                break;
            case 5:
                keepOn = 'n';
                break;
            case 0:
                printf("\nInvalid option. Please try again.\n");
                break;
            }
            system("pause");
        }
        while(keepOn =='y');

    }
    return modifOk;
}

//************************************************************************************************************************************/
void modificationOk(Employee* list, int index)
{
    printf("The modification was successful.\n\n");
    printf(" Id         Name           LastName         Salary       Sector\n");
    printEmployee(list[index]);

}

//************************************************************************************************************************************/
int modificationMenu()
{
    int option;

    printf("\n1.  Modify name.\n");
    printf("2.  Modify last name.\n");
    printf("3.  Modify salary.\n");
    printf("4.  Modify sector.\n");
    printf("5.  Exit.\n");
    printf("Enter option: ");

    if(utn_getNumero(&option, "Enter option: ","",1,5,0) == NOTOK)
    {
        option = 0;
    }

    return option;
}
//************************************************************************************************************************************/
int initEmployees(Employee* list, int len)
{
    int initOk = NOTOK;
    if (validateLengthAndNullPointer(list, len))
    {
        for (int index =0; index < len; index++)
        {
            list[index].isEmpty = TRUE;
            initOk = OK;
        }
    }

    return initOk;
}

//************************************************************************************************************************************/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee auxEmployee;
    int addedOk = FALSE;
    int freeIndex = findFreeIndex( list, len) ;

    if (validateLengthAndNullPointer(list, len) && freeIndex != NOTFOUND)
    {
        auxEmployee.id = id;
        strcpy(auxEmployee.name, name);
        strcpy(auxEmployee.lastName, lastName);
        auxEmployee.salary = salary;
        auxEmployee.sector = sector;
        auxEmployee.isEmpty = FALSE;

        list[freeIndex] = auxEmployee;

        addedOk = OK;
    }
    return addedOk;
}

//************************************************************************************************************************************/
int findEmployeeById(Employee* list, int len,int id)
{
    int employeeIndex = NOTFOUND;
    if  (validateLengthAndNullPointer(list, len))
    {
        for (int index =0; index < len; index++)
        {
            if (list[index].id == id && list[index].isEmpty == FALSE)
            {
                employeeIndex = index;
                break;
            }
        }
    }
    return employeeIndex;
}

//************************************************************************************************************************************/
int removeEmployee(Employee* list, int len, int id)
{
    int removedOk = NOTOK;
    int employeeIndex = findEmployeeById(list, len, id);
    char confirm;

    if(validateLengthAndNullPointer(list, len) && employeeIndex != NOTFOUND)
    {
        printf("   Id       Name           LastName           Salary     Sector\n");
        printEmployee(list[employeeIndex]);
        printf("Are you sure that you want to remove this employee?  y/n ");
        fflush(stdin);
        scanf("%c", &confirm);
        if (tolower(confirm) == 'y')
        {
            list[employeeIndex].isEmpty = TRUE;
            printf(" The employee has been removed successfully.\n");
            removedOk = OK;
        }
        else
        {
            printf("The operation has been canceled. \n");
        }

    }
    else if( employeeIndex == NOTFOUND)
    {
        printf("The given id does not correspond to any active employee in the system.\n  ");
    }

    return removedOk;
}

//************************************************************************************************************************************/
int sortEmployees(Employee* list, int len, int order)
{
    int  sortedOk = NOTOK;
    Employee auxEmpleado;
    if(validateLengthAndNullPointer(list, len))
    {
        if (order ==1 )
        {
            for (int i = 0; i< len-1; i++)
            {
                for (int j= i+1;  j< len;  j++)
                {
                    if (strcmp(list[i].lastName, list[j].lastName) > 0)
                    {
                        auxEmpleado = list [i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    else if (strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector > list[j].sector)
                    {
                        auxEmpleado = list [i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    sortedOk = OK;

                }
            }
        }
        else if(order == 0)
        {
            for (int i = 0; i< len-1; i++)
            {
                for (int j= i+1;  j< len;  j++)
                {
                    if (strcmp(list[i].lastName, list[j].lastName) < 0)
                    {
                        auxEmpleado = list [i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    else if (strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector < list[j].sector)
                    {
                        auxEmpleado = list [i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                    sortedOk = OK;

                }
            }
        }
    }
    return sortedOk;
}

//************************************************************************************************************************************/
int printEmployees(Employee* list, int length)
{
    int hasEmployees;
    int printedOk = NOTOK;
    if( validateLengthAndNullPointer(list, length))
    {
        system("cls");
        hasEmployees = FALSE;
        printf("\n****** Active Employees ******\n\n");
        printf("   Id       Name           LastName         Salary       Sector\n");

        for (int index = 0; index < length; index++)
        {
            if (list[index].isEmpty == FALSE)
            {
                printEmployee(list[index]);
                hasEmployees = TRUE;
            }
        }

        if ( hasEmployees == FALSE)
        {
            printf("\nThere are no active employees in the system. \n");
        }
        printedOk = OK;
    }
    return printedOk;
}

//************************************************************************************************************************************/
int findFreeIndex(Employee* list, int len)
{
    int freeIndex = -1;
    if(validateLengthAndNullPointer(list, len))
    {
        for (int index =0 ; index <  len; index++)
        {
            if (list[index].isEmpty)
            {
                freeIndex = index;
                break;
            }
        }
    }

    return freeIndex;
}

//************************************************************************************************************************************/
int validateLengthAndNullPointer( Employee* list, int len)
{
    int validationOk = NOTOK;
    if  (len > 0  && list != NULL)
    {
        validationOk = TRUE;
    }
    return validationOk;
}

void printEmployee( Employee emp )
{
    printf("%d    %10s      %10s          %.2f      %d   \n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);

}

//************************************************************************************************************************************/
int askForEmployeeData(Employee* list, int len, int id)
{
    system("cls");
    printf("**** Add new employee menu **** \n\n");
    int dataReceived = NOTOK;
    if( validateLengthAndNullPointer(list,len))
    {
        int addedOk = NOTOK;
        Employee auxEmployee;

        int nameOk = utn_getNombre(auxEmployee.name, 51,"Name: ", "The name can only contain letters and must have less than 50.\n",  3);
        int lastNameOk = utn_getNombre(auxEmployee.lastName, 51, "Last Name: ", "The last name can only contain letters and must have less than 50. \n",  3);
        int salaryOk = utn_getNumeroFlotante(&auxEmployee.salary, "Salary: ", "The salary value must be a number between 1 and 400000. \n", 1.00, 4000000.00, 3);
        int sectorOk = utn_getNumero(&auxEmployee.sector, "Sector: ", "The sector value must be a number between 1 and 10.\n", 1, 10, 3);

        if(nameOk && lastNameOk && salaryOk  && sectorOk )
        {
            auxEmployee.id = id;
            auxEmployee.isEmpty = FALSE;
            strlwr(auxEmployee.name);
            auxEmployee.name[0]= toupper(auxEmployee.name[0]);
            strlwr(auxEmployee.lastName);
            auxEmployee.lastName[0]= toupper(auxEmployee.lastName[0]);
            addedOk = addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

            if (addedOk == OK)
            {
                dataReceived = TRUE;
                printf("The employee has been registered in the system successfully.\n");
            }
            else
            {
                printf("The system is full. There is no place for new employees.\n");
            }
        }
        else
        {
            printf("Errors occurred during data upload. Please try again.\n");
            dataReceived = NOTOK;
        }
    }
    return dataReceived;
}

//************************************************************************************************************************************/
void reportsMenu(Employee* list, int len)
{
    int option;
    int order;
    system("cls");
    printf("**** Reports Menu **** \n\n");
    printf("1.  Show employees ordered by last name and sector.\n");
    printf("2.  Show total and average wages, and quantity of employees that have a salary beyond of the average.\n");
    if(utn_getNumero(&option, "Enter option: ","",1,2,0) == NOTOK)
    {
        option = 0;
    }
    switch(option)
    {
    case 1:
        printf("In which way do you want to sort the employees? \n1.Ascending.\n2.Descending.\n");
        if (utn_getNumero(&order, "Enter option: ","Error. The options are 1 or 2.",1,2,1) == NOTOK)
        {
            order =0;
        }
        else
        {
            switch(order)
            {
            case 1:
                if(sortEmployees(list, len, 1) == OK)
                {
                    printEmployees(list, len);
                    printf("The order has been made succesfully.\n");
                }
                else
                {
                    printf("The order could not be performed.\n");
                }

                break;
            case 2:
                if(sortEmployees(list, len, 0) == OK)
                {
                    printEmployees(list, len);
                    printf("The order has been made succesfully.\n");
                }
                else
                {
                    printf("The order could not be performed.\n");
                }

                break;
            case 0:
                printf("The ordering couldn't be made. Please choose a valid option.");
                break;
            }
        }
        break;
    case 2:
        reportTotalSalaryAndAverage(list, len) ;
        break;

    case 0:
        printf("\nInvalid option. Please try again.\n");
        break;
    }
}

void reportTotalSalaryAndAverage (Employee* list, int len)
{
    float totalSalary = 0;
    int qtyEmployees = 0;
    int qtyEmployeesBeyondAverage =0;
    float averageSalary;

    system("cls");
    printf("\n***** Total wages and average wage *****\n\n");
    for(int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == FALSE)
        {
            totalSalary += list[i].salary;
            qtyEmployees ++;
        }
    }
    averageSalary = totalSalary / qtyEmployees;
     for(int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == FALSE && list[i].salary > averageSalary)
        {
           qtyEmployeesBeyondAverage ++;
        }
    }
    printf("Total salary: %.2f \n", totalSalary);
    printf("Average salary: %.2f\n", averageSalary);
    printf("Quantity of employees whose salary exceeds the  average: %d\n", qtyEmployeesBeyondAverage);

}



