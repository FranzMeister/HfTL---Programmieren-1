#ifndef __UEBUNG_3_H
#define __UEBUNG_3_H

#ifdef __cplusplus
extern "C"
{
#endif


/** \brief Diese Funktion bestimmt, ob das angegeben Jahr ein Schaltjahr ist
*
* \param[in] year das Jahr
* \return 0 wenn es kein Schaltjahr ist \n
*         1 wenn das Jahr ein Schaltjahr ist \n
*/
int is_leap_year(int year);


/** \brief Diese Funktion berechnet den groeßten gemeinsamen Teiler (ggt) der Zahlen a und b
*
* \param[in] a
* \param[in] b
*
* \return ggt von a und b
*/
int ggt(int a,int b);


/** \brief Diese Funktion berechnet fuer ein gegebenes Datum der wievielte Tag des Jahres es ist
*
* Das angegebe Datum ergibt sich aus Jahr, Monat und Tag.
*
* \param[in] year das Jahr 
* \param[in] month der Monat
* \param[in] day der Tag
*
* \return der Tag des Jahres \n
*         -1 im Fehlerfall
*/
int day_of_year(int year,int month,int day);


#ifdef __cplusplus
}
#endif

#endif // __UEBUNG_3_H
