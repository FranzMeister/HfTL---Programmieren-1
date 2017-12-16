#ifndef __UEBUNG_2_H
#define __UEBUNG_2_H

#ifdef __cplusplus
extern "C"
{
#endif

/** \brief diese Funktion ermittelt den kleinsten Wert eines Arrays und gibt diesen zurueck
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return der kleinste Wert den das Array enthaelt \n
*         NAN im Fehlerfall
*/
double min(int *array,int length); 

/** \brief diese Funktion ermittelt den groessten Wert eines Arrays und gibt diesen zurueck
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return der groesste Wert den das Array enthaelt \n
*         NAN im Fehlerfall
*/
double max(int *array,int length);

/** \brief diese Funktion ermittelt den Index des kleinsten Wertes eines Arrays und gibt diesen zurueck
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return Index des kleinsten Wertes den das Array enthaelt \n
*         NAN im Fehlerfall
*/
double min_index(int *array,int length); 

/** \brief diese Funktion ermittelt den Index des groessten Wertes eines Arrays und gibt diesen zurueck
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return Index des groessten Wertes den das Array enthaelt \n
*         NAN im Fehlerfall
*/
double max_index(int *array,int length);

/** \brief diese Funktion berechnet die Summer aller Werte eines uebergebenen Arrays
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return Summe \n
*         NAN im Fehlerfall
*/
double sum(int *array,int length);

/** \brief diese Funktion berechnet den Mittelwert aller Elemente eines uebergebenen Arrays
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >0
* \return Mittelwert \n
*         NAN im Fehlerfall
*/
double average(int *array,int length);

/** \brief diese Funktion berechnet die Standardabweichung aller Werte eines uebergebenen Arrays
*
* \param[in] *array Array mit Zahlen
* \param[in] length Laenge des Arrays; gueltige Werte >1
* \return Standardabweichung \n
*         NAN im Fehlerfall
*/
double stddev(int *array,int length);


#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_2_H
