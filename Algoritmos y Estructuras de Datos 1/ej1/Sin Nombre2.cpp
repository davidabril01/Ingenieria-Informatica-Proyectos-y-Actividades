#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct fulanito{ 
char fulero [20];
int  a;
float b;
};

int main () {
	fulanito a;
	FILE *arch;
	
	arch=fopen("archivo1.dat","rb");
	fread (&a, sizeof (fulanito), 1, arch);
	printf("%s", &a.fulero);
	fclose (arch);
}

