#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	//Textausgabe
	printf("Hello World! \n");
	printf("ganze Zahlen: %i %i %i %i \n", 0, 1, 234, -45);
	printf("Gleitkommazahlen: %f %0.2f %E \n", 0.1234, 0.1234, 0.1234);
	printf("ganze Zahlen oktale Darstellung: %o %o %04o \n", 8, 42, 42);
	printf("ganze Zahlen hexadezimale Darstellung: %x %X %04X \n", 42, 42, 42);
	printf("Textzeichen: %c %c %c \n", 'a', 'B', 0x37);
	printf("Strings: %s \n %s \n", "irgendein Text",
		"Ein String"
		"muss nicht"
		"auf einer"
		"Zeile stehen");
	printf("Konstanten: %i %i %i \n", 11, 011, 0x11); //dezimal, oktal, hexadezimal

	//Datentypen
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;

	printf("\n Datentypen \n");
	printf("char	: %li\n", sizeof(c));
	printf("short	: %li\n", sizeof(s));
	printf("int		: %li\n", sizeof(i));
	printf("long	: %li\n", sizeof(l));
	printf("float	: %li\n", sizeof(f));
	printf("double	: %li\n", sizeof(d));
	printf("\n");

	//Schleifen
	printf("\n Schleifen \n");
	int j;
	for(j=0; j<5; j++)
		printf("j=%i\n", j);

	printf("\n");
	for(j=0; j<5; j++);		//Semikolon am Ende
		printf("j=%i\n", j);

	/* Besser mit Klammern */
	printf("\n");
	for(j=0; j<5; j++){
		printf("j=%i\n", j);
	}

	//etwas Rechnen
	printf("\n Rechnen \n");
	int x,y,z;

	x=0; //Zuweisung
	y=5;
	printf("x=%i y=%i \n", x, y);

	x=y;
	printf("x: %i 	", x);
	printf("x++: %i ", x++);
	printf("x: %i \n", x);

	x=y;
	printf("x: %i 	", x);
	printf("++x: %i ", ++x);
	printf("x: %i \n", x);

	x=5;
	y=2;
	z=y*x;
	printf("%i*%i=%i\n", x, y, z);
	z = x/y;
	printf("%i/%i=%i", x, y, z);

	d=x*y;
	printf("%i*%i=%f\n", x,y,d);
	d=x/y;
	printf("%i/%i=%f\n", x,y,d);
	d=1.0*x/y;
	printf("%i/%i=%f\n", x,y,d);

	return 0;
}


























