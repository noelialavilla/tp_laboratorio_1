#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
/** \brief busca espacio en la memoria dinamica y devuelve un puntero a empleado en el espacio encontrado. Es el constructor vacio de empleados
 *
 * \return devuelve la posicion de memoria en la que asigno el puntero dinamico a empleado
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
/** \brief constructor de empleados con parametros, recibe variables, crea un empleado y se las asigna
 *
 * \param id de empleado en variable del tipo cadena de caracteres
 * \param nombre de empleado en variable del tipo cadena de caracteres
 * \param horas trabajadas del empleado en variable del tipo cadena de caracteres
 * \param sueldo de empleado en variable  del tipo cadena de caracteres
 * \return
 *
 */

void employee_delete(Employee* this );
/** \brief recibe un puntero a empleado y libera la zona de memoria que este ocupaba
 *
 * \param puntero a empleado del tipo Employee
 *
 */


int employee_setId(Employee* this,int id);
/** \brief recibe un puntero a Employee y  una variable del tipo entero, asigna al atributo id del empleado recibido la variable id recibida por parametro
 *
 * \param puntero a empleado del tipo Employee
 * \param variable del tipo entero
 * \return  devuelve 1 si pudo asignarle el id al empleado y -1 si el puntero a empleado es nulo o si el id recibido no se encuentra en el rango esperado
 *
 */

int employee_getId(Employee* this,int* id);
/** \brief  recibe un puntero a un empleado y el puntero a una variable entera, obtiene el valor del id del empleado recibido y se lo asigna a la variable id recibida
 *
 * \param  recibe el puntero a un empleado del tipo Employee
 * \param  recibe puntero a una variable id del tipo int
 * \return  devuelve -1 si el empleado es nulo o el puntero a id es nulo, 1 si pudo realizar la accion
 *
 */


int employee_setNombre(Employee* this,char* nombre);
/** \brief  recibe un puntero a Employee y un puntero a una variable del tipo cadena de caracteres, asigna al atributo nombre del empleado recibido la variable nombre recibida por parametro
 *
 * \param recibe el puntero a un empleado del tipo Employee
 * \param recibe puntero a variable del tipo cadena de caracteres
 * \return  devuelve 1 si pudo asignarle nombre al empleado y -1 si el puntero a empleado es nulo o si el nombre recibido no se encuentra en el rango esperado
 *
 */

int employee_getNombre(Employee* this,char* nombre);
/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo cadena de caracteres, obtiene el valor del nombre del empleado recibido y se lo asigna a la variable nombre recibida
 *
 * \param recibe el puntero a un empleado del tipo Employee
 * \param recibe puntero a variable del tipo cadena de caracteres
 * \return  devuelve -1 si el empleado es nulo o el puntero a nombre es nulo, 1 si pudo realizar la accion
 *
 */


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
/** \brief recibe un puntero a Employee y una variable del tipo entero, asigna al atributo horasTrabajadas del empleado recibido la variable horasTrabajadas recibida por parametro
 *
 * \param recibe el puntero a un empleado del tipo Employee
 * \param recibe variable del tipo entero
 * \return devuelve 1 si pudo asignarle las horas trabajadas al empleado y -1 si el puntero a empleado es nulo o si las horas trabajadas recibidas no se encuentran en el rango solicitado
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo entero, obtiene el valor de las horas trajadas del empleado recibido y se lo asigna a la variable horas trabajadas recibida
 *
 * \param puntero a un empleado del tipo Employee
 * \param puntero a variable del tipo entero
 * \return devuelve -1 si el empleado es nulo o el puntero a horasTrabajadas es nulo, 1 si pudo realizar la accion
 *
 */

int employee_setSueldo(Employee* this, int sueldo);
/** \brief recibe un puntero a Employee y una variable del tipo entero, asigna al atributo sueldo del empleado recibido la variable sueldo recibida por parametro
 *
 * \param puntero a un empleado del tipo Employee
 * \param recibe variable del tipo entero
 * \return devuelve 1 si pudo asignarle el sueldo al empleado y -1 si el puntero a empleado es nulo o si el sueldo recibido no se encuentra en el rango solicitado
 *
 */

int employee_getSueldo(Employee* this,int* sueldo);
/** \brief recibe un puntero a un empleado y el puntero a una variable del tipo entero, obtiene el valor de las sueldo del empleado recibido y se lo asigna a la variable sueldo recibida
 *
 * \param puntero a un empleado del tipo Employee
 * \param puntero a variable del tipo entero
 * \return devuelve -1 si el empleado es nulo o el puntero a sueldo es nulo, 1 si pudo realizar la accion
 *
 */


int menu();
/** \brief muestra por pantalla las opciones disponibles del menu de gestion de empleados
 *
 * \return int opcion elegida por el usuario
 *
 */

int showEmployees(LinkedList* lista);
/** \brief recibe el puntero a una lsita de empleados del tipo LinkedList y muestra esos empleados por pantalla
 *
 * \param puntero a lista de empleados del tipo LinkedList
 * \return
 *
 */

int showEmployee(Employee* this);
/** \brief recibe un puntero a empleado y lo muestra por pantalla
 *
 * \param puntero a un empleado del tipo Employee
 * \return  devuelve 1 si el puntero recibido es distinto de nulo y -1 si el puntero recibido es nulo
 *
 */

int compareEmployeesByName(void* empA,void* empB);
/** \brief castea a puntero a empleado los parametros recibidos y compara los nombres de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los nombers de los empleados son iguales, 1 si el nombre del empA es mayor al nombre del empB y -1 si el nombre del empA es menor al nombre del empB
 *
 */

int modifyEmployee(Employee* this);
/** \brief recibe un puntero a Employee e interactua con el usuario para que elija que atributo desea modificar permitiendole modificarlo
 *
 * \param  puntero a un empleado del tipo Employee
 * \return devuelve 1 si se pudo realizar alguna modificacion, y -1 en caso contrario
 *
 */

void modificationOk(Employee* this);
/** \brief informa al usuario que se realizo satisfactoriamente la modificación y muestra al empleado modificado
 *
 * \param puntero a un empleado del tipo Employee
 *
 */

int findEmployeeById(LinkedList* pArrayListEmployee, int id);
/** \brief busca en la lista el empleado que posea el id recibido por parametro y devuelve su indice
 *
 * \param puntero a una lista de empleados del tipo LinkedList
 * \param variable del tipo entero
 * \return -1 si no existe en la lista un empleado con el id proporcionado o el indice del empleado con el id recibido si existe
 *
 */

#endif // employee_H_INCLUDED
