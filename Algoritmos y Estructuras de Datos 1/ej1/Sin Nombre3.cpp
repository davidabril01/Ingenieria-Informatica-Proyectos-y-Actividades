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
	
	arch=fopen("x.dat","wb");
	
	fwrite(&a, sizeof (fulanito),1,arch);

	fclose (arch);
	}
