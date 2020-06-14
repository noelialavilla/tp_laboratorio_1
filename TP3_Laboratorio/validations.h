#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED



#endif // VALIDATIONS_H_INCLUDED

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
 /**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 *
 */

int getFloat(float* pResultado);
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */

int esFlotante(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */

int strnlen(const char *s, size_t maxlen);
/**
* \brief busca un '\0' y a su vez, busca no pasarse del tamaño maximo que tiene el array que le paso en la llamada.
 *
 * \param el array que le paso.
 * \param el tamaño de dicho array.
 * \return int longitud en bytes y si se desborda, devuelve el maximo.
 */

int getString(char* cadena, int longitud);
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */

 int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
 /**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 1 si se obtuvo el nombre y -1 si no
 *
 */

 int getNombre(char* pResultado, int longitud);
 /**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */

 int esNombre(char* cadena,int longitud);
 /**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 0 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */

 int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
 /**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 *
 */

int getInt(int* pResultado);
 /**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */

int esNumerica(char* cadena, int limite);
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
