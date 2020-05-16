#include <stdio.h>
#include <stdlib.h>
#define EMPQTY 1000
#define NOTOK -1
#define TRUE 1
#define FALSE 0
#include "utn.h"
#include "ArrayEmployees.h"

int main()
{
    char keepOn = 'y';
    char confirm;
    Employee list[EMPQTY];
    int initOk;
    int id;
    int nextId;
    int emptyList;
    initOk =initEmployees(list, EMPQTY);
    nextId = 1000;

    if (initOk == NOTOK)
    {
        printf("Initialization error.\n");
    }
    else
    {
        do
        {

            if(validateEmptyArray(list, EMPQTY))
            {
                emptyList = TRUE;
            }
            switch(menu())
            {
            case 1:
                if (askForEmployeeData(list, EMPQTY, nextId ))
                {
                    nextId++;
                    emptyList = FALSE;
                }
                break;
            case 2:
                if(emptyList)
                {
                    printf("The system is empty. You have to register at least one employee in order to do a modification. \n");
                }
                else
                {
                    if(modifyEmployee(list, EMPQTY) ==NOTOK)
                    {
                        printf("The modification could not be made. Please, try again.\n");
                    }
                }
                break;
            case 3:
                if (emptyList)
                {
                    printf("The system is empty. You have to register at least one employee in order to remove one. \n");
                }
                else
                {
                    system("cls");
                    printf("**** Remove Employee **** \n\n");
                    printEmployees(list, EMPQTY);
                    printf("Enter the id of the employee you want to remove:");
                    fflush(stdin);
                    scanf("%d", &id);
                    removeEmployee(list, EMPQTY, id);
                }

                break;
            case 4:
                if (emptyList)
                {
                    printf("The system is empty. You have to register at least one employee in order to generate the reports. \n");
                }
                else
                {
                    reportsMenu(list, EMPQTY);
                }
                break;
            case 5:
                printf("Are you sure you want to exit? (y/n) ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (confirm == 'y')
                {
                    keepOn = 'n';
                }
                break;
            case 0:
                printf("\nInvalid option. Please try again.\n");
                break;
            }
            system("pause");

        }while ( keepOn == 'y');

    }

    return 0;
}
