#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

//****************************************************************************/

void inicioCalculadora();
/** \brief se encarga de realizar la logica correspondiente a la calculadora
 *
 */

//****************************************************************************/

int imprimirMenuPrincipal();
/** \brief imprime menu principal de opciones
 *
 * \return int la opcion escogida por el usuario
 *
 */

//****************************************************************************/

int imprimirSubmenuPrimerOperando(int primerOperando);

/** \brief imprime las opciones aun no realizadas en un submenu en el que se muestra el dato que ya fue ingresado
 *
 * \param recibe int primer operando ingresado por el usuario
 * \return int opcion elegida por el usuario
 *
 */

//****************************************************************************/

int imprimirSubmenuAmbosOperandos(int primerOperando, int segundoOperando);

/** \brief imprime las opciones aun no realizadas en un submenu en el que se muestran los datos que ya fueron ingresados
 *
 * \param recibe int primer operando ingresado por el usuario
 * \param recibe int segundo operando ingresado por el usuario
 * \return int opcion elegida por el usuario
 *
 */

//****************************************************************************/

int ingresarOperando();

/** \brief se encarga de recibir un operando del tipo integer
 *
 * \return devuelve el operando ingresado
 *
 */

//****************************************************************************/
int esNumerico(char dato[]);

/**
 * \brief Verifica si el valor recibido es un numero
 * \param dato Array con la cadena a ser analizada
 * \return 0 si se trata de un numero, 1 si se trata de una cadena de letras
 *
 */
//****************************************************************************/

void mostrarResultados(int a, int b, int resSuma, int resResta, float resDiv,int resMultiplicacion,int resFactorialA,int resFactorialB);

/** \brief muestra por pantalla el resultado de las operaciones realizadas
 *
 * \param int primer operando
 * \param int segundo operando
 * \param int resultado de la suma
 * \param int resultado de la resta
 * \param float resultado de la division
 * \param int resultado de la multiplicacion
 * \param int resFactorialA resultado del factorial del primer operando ingresado
 * \param int resFactorialB resultado del factorial del segundo operando ingresado
 * \return
 *
 */

//****************************************************************************/

void mostrarResultadosFactoreo(int numero, int factorial);
/** \brief Recibe un numero y su factorial, muestra el resultado en caso de que el numero sea positivo y menor que 13, muestra mensaje de error en caso contrario.
 *
 * \param int numero al que se le aplico el factoreo
 * \param int factorial, resultado del factoreo del primer parametro
 *
 */
//****************************************************************************/

int sumar(int primerSumando, int segundoSumando);

/** \brief realiza la suma de los dos sumandos ingresados
 *
 * \param int primer sumando
 * \param int segundo sumando
 * \return resultado de la suma del tipo integer
 *
 */

//****************************************************************************/

int restar(int minuendo, int sustraendo);

/** \brief realiza la resta entre el minuendo y el sustraendo
 *
 * \param int minuendo
 * \param int sustraendo
 * \return devuelve la resta entre minuendo y sustraendo, del tipo integer
 *
 */

//****************************************************************************/

int multiplicar (int primerFactor, int segundoFactor);

/** \brief realiza la multiplicacion entre dos numeros dados
 *
 * \param int primer factor de la multiplicacion
 * \param int segundo factor de la multiplicacion
 * \return resultado tipo integer, multiplicacion entre primer factor y segundo
 *
 */

//****************************************************************************/

float dividir(int dividendo, int divisor);

/** \brief realiza la division entre el dividendo y el divisor
 *
 * \param integer dividendo
 * \param integer divisor
 * \return resultado de la division entre el dividendo y el divisor del tipo float
 *
 */

//****************************************************************************/

int factorial(int numero);

/** \brief realiza el factorial de cada uno de los numeros ingresados
 *
 * \param int numero a factoriar
 * \return devuelve un array de dos elementos, en el primero se encuentra el factorial del primer numero
 *         y en el segundo el factorial del segundo numero
 *
 */


//****************************************************************************/
void resetTrigger(int* p);
/** \brief realiza un reseteo de la bandera/trigger pasada por parametro
 *
 * \param direccion de memoria de la bandera a resetear
 *
 */

#endif // CALCULOS_H_INCLUDED
