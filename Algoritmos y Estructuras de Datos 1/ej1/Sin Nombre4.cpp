#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct fulanito{ 
int b=1;
int  a=1;
float c=1.1;
float d=2.2;
};

int main () {
	fulanito a;
	FILE *arch;
	
	arch=fopen("x.dat","rb");
	fread (&a, sizeof (fulanito), 1, arch);
	printf("el primero es %d el segundo es %d", a.a, a.b);
	printf("el primero es %2.1f el segundo es %2.1f", a.c, a.d);
	fclose (arch);
}

