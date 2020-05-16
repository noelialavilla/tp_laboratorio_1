#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name [51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED

int menu();
/** \brief show the available options
 *
 * \return int option entered by the user
 *
 */

 int validateEmptyArray(Employee* list, int len);
 /** \brief validate if the array is empty
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  * \return 1 when the array is empty or 0 if not
  *
  */

int modifyEmployee(Employee* list, int len);
/** \brief  ask the user which parameter he wants to modify
 *
* \param list Employee* Pointer to array of employees
  * \param len int Array length
 * \return 1 when the modification could be done, -1 if not
 *
 */

void modificationOk(Employee* list, int index);
/** \brief  report to the user that the modification went well and print the data of the employee with the modifications
 *
* \param list Employee* Pointer to array of employees
  * \param len int Array length
 *
 */

 int modificationMenu();
 /** \brief shows the user the possible attributes to modify
  *
  * \return int option that indicate which attribute he wants to change
  *
  */

int initEmployees(Employee* list, int len) ;
/** \brief  To indicate that all position in the array are empty,
*                    this function put the flag (isEmpty) in TRUE in all
*                    position of the array
*  \param list Employee* Pointer to array of employees
*  \param len int Array length
*  \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief add in a existing list of employees the values received as parameters
 *     in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/

int findEmployeeById(Employee* list, int len,int id) ;
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/

int removeEmployee(Employee* list, int len, int id) ;
/** \brief Remove a Employee by Id (put isEmpty Flag in 1
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't  find a employee] - (0) if Ok
*
*/

int sortEmployees(Employee* list, int len, int order) ;
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int printEmployees(Employee* list, int length) ;
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/

int findFreeIndex(Employee* list, int len);
/** \brief  look for a free index in the given array, return the free index if found or -1 if out of space
 *
 * \param array list of Employee
 * \param len of the array
 * \return free index or -1
 *
 */

 int validateLengthAndNullPointer( Employee* list, int len);
 /** \brief return 1 if validation is Ok or -1 if the given array has an invalid length or  null pointer
  *
  * \param list of Employee
  * \param length of the array
  * \return 1 if ok or -1 if not
  *
  */

void printEmployee( Employee emp);
/** \brief show the data of the given employee
 *
 * \param Employee
 */

 int askForEmployeeData(Employee* list, int len, int id);
 /** \brief ask the user to enter the data for the new employee
  *
  * \param list of Employee
  * \param length of the array
  * \return 1 when data received was ok, -1 when not
  *
  */

void reportsMenu(Employee* list, int len);
/** \brief shows the user the possible reports to be shown
 *
 * \param list of Employee
 * \param length of the array
*
*/

void reportTotalSalaryAndAverage (Employee* list, int len);
/** \brief report the total of the salarys, the average salary and the quantity of employees whose salary is beyond the average
*
 * \param list of Employee
 * \param length of the array
*
*/

