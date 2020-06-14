
//************************************************************************************************************************************/
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 //************************************************************************************************************************************/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 //************************************************************************************************************************************/
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 //************************************************************************************************************************************/
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 //************************************************************************************************************************************/
int controller_removeEmployee(LinkedList* pArrayListEmployee);
 /** \brief Baja de empleado
*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

//************************************************************************************************************************************/
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

//************************************************************************************************************************************/
int controller_sortEmployee(LinkedList* pArrayListEmployee);
 /** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//************************************************************************************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

//************************************************************************************************************************************/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
 /** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

//************************************************************************************************************************************/
int getIdFromArchive(int* id);
/** \brief abre el archivo proximoId.bin en modo lectura, si no existe lo crea y si existe lee el numero de id que contiene y lo guarda en la variable recibida por parametro
 *
 * \param puntero a varible del tipo entero
 * \return devuelve 1 si pudo conseguir el id del archivo y -1 si el archivo no existia
 *
 */

int updateId(int id);
/** \brief al id recibido por parametro le suma 1 y lo escribe en el archivo proximoId.bin
 *
 * \param variable del tipo entero
 * \return 1 si pudo actualizar el archivo con la nueva variable, -1 en caso contrario
 *
 */
