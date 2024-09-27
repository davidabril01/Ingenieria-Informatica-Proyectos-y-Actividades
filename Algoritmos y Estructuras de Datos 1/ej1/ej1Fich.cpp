#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct fulanito{ 
char fulero [20]="holamanito";
int  a=1;
float b=1.1;
};

int main () {
	fulanito a;
	
	FILE *arch;
	
	arch=fopen("archivo1.dat","wb");
	
	fwrite(&a, sizeof (fulanito),1,arch);

	fclose (arch);
	}
