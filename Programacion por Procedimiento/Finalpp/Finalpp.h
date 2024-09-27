#include <fstream>
#include <iostream>
using namespace std;

class principal
{
private:
    struct ingresos
    {
        int edad;
        char sexo;
        int ingresos;
        int region;
    };

public:
    void escribir_archivo()
    {
        ingresos datos;
        FILE *arch;
        arch = fopen("ingresos.dat", "wb");
        fclose(arch);
        arch = fopen("ingresos.dat", "a");
        datos.edad = 18;
        datos.sexo = 'M';
        datos.ingresos = 1200;
        datos.region = 1;
        fwrite(&datos, sizeof(ingresos), 1, arch);
        datos.edad = 34;
        datos.sexo = 'M';
        datos.ingresos = 1250;
        datos.region = 1;
        fwrite(&datos, sizeof(ingresos), 1, arch);
        datos.edad = 23;
        datos.sexo = 'F';
        datos.ingresos = 6300;
        datos.region = 2;
        fwrite(&datos, sizeof(ingresos), 1, arch);
        fclose(arch);
    }
    int media_ingresos()
    {
        ingresos ing;
        int a = 0, cont=0;
        FILE *arch;
        arch = fopen("ingresos.dat", "rb");
        if (arch == NULL)
            perror("Error opening file");
        else
        {
            fread(&ing, sizeof(ingresos), 1, arch);
            while (!feof(arch))
            {
                a = a + ing.ingresos;
                cont++;
                fread(&ing, sizeof(ingresos), 1, arch);
            }
        }
        return (a/cont);
    }
    void Pers_region()
    {
        ingresos ing;
        FILE *arch;
        int r1 = 0, r2 = 0, r3 = 0;
        arch = fopen("ingresos.dat", "rb");
        if (arch == NULL)
            perror("Error opening file");
        else
        {
            fread(&ing, sizeof(ingresos), 1, arch);
            while (!feof(arch))
            {
                if (ing.region == 1)
                {
                    r1++;
                }
                else if (ing.region == 2)
                {
                    r2++;
                }
                else if (ing.region == 3)
                {
                    r3++;
                }
                fread(&ing, sizeof(ingresos), 1, arch);
            }
        }
        ofstream cantP("Persona.txt");
        cantP << "Region "
              << "Cantidad de Personas" << endl;
        cantP << "1         " << r1 << endl
              << "2         " << r2 << endl
              << "3         " << r3 << endl;
        cantP.close();
    }
};
